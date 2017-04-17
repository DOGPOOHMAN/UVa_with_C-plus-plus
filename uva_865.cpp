#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    
    int group;//紀錄總共有幾篇文章要處理
    string trash;//字串垃圾桶
    
    cin >> group;
    getline(cin, trash);//把group後面的換行LF讀進來
    getline(cin, trash);//把空白行讀進來
    
    for (int i = 0; i < group; i++) {//依照group，重複處理文章轉換
        
        map<char, char> transform;//字元轉換前與轉換後的對應表
        string key, value;
        
        getline(cin, key);//讀入愈轉換的字元
        getline(cin, value);//讀入轉換後相對應的字元
        
        for (int i = 0; i < key.size(); i++){//建立轉換前後對應表
            
            transform[ key[i] ] = value[i];
            //把某個key設定一個數值value給他
        }
        
        //依照題目需求而輸出
        cout << value << '\n';
        cout << key << '\n';

    
        string aLine;//儲存一行將要被處理的文字
        char oTemp;//暫時儲存即將要被印出的字元
        map<char, char>::iterator ite;//儲存找尋相對應字元後的結果
        
        while (true) {//一次處理一行，讀到空白行時終止
            
            getline(cin, aLine);
            if(aLine == ""){ break; }//讀到空白行時終止
           
            for (int i = 0; i < aLine.size(); i++) {
                
                oTemp = aLine[i];//循序取得一個字元
                ite = transform.find( oTemp );//到對應表裡面尋找這個文字需不需要被替換
                
                if (ite != transform.end())//這個判斷式如果成立代表有找到，這個字元需要被替換
                { oTemp = ite->second; }//把替換後的字元重新設定為輸出的字元
                
                cout << oTemp;//把結果輸出
            }
            
            cout << '\n';//補齊最後的換行
        }
        
        if(i != (group - 1))//題目要求每一組文章之間都要空行分開，但最後一組文字不用
        { cout << '\n'; }
    }
    
    return 0;
}

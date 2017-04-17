#include <string>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

int main(){
    int ruleGroup, textGroup;
    map<string, string> rule;//用來儲存單字轉換規則
    
    cin >> ruleGroup;//得知有幾行規則
    
    //讀入單字轉換規則
    string key, value;
    int i;
    for (i = 0; i < ruleGroup; i++) {
        cin >> key;
        cin >> value;
        rule.insert(make_pair(key, value));
    }
    
    
    cin >> textGroup;//得知有幾行需要轉換的文字
    
    string line, word;
    getline(cin , line);//把前一行的換行LF讀進來，以免影響後面的作業
    
    //讀取欲轉換的文字，並且轉換他們，接著直接輸出
    int j;
    for (j = 0; j < textGroup; j++) {
        
        getline(cin , line);//讀取整行文字
        istringstream stream(line);//分解這行文字為一個個的單字
        
        bool printSpace = false;//用來控制是否要印出空白
        while (stream >> word) {//一次處理一個單字
            
            //去規則表裡面找找看，這個單字需不需要被轉換
            auto rule_Ite = rule.find(word);
            
            //如果這個單字需要被轉換，就把word設為轉換之後的單字
            if (rule_Ite != rule.end())
            { word = rule_Ite->second; }
            
            //印出結果
            if(printSpace)//如果現在處理的是第一個單字就不印出空白
            { cout << " "; }
            else
            { printSpace = true; }
            
            cout << word;
        }
        
        cout << '\n';
        
      
    }
    return 0;
}


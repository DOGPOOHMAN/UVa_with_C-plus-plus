#include <string>
#include <iostream>

using namespace std;

int main(){
    string text, revText;
    int group; cin >> group;
    
    while(group != 0){
        text.clear();//初始化text
        revText.clear();//初始化revText
        
        cin >> text;//讀入將要被反轉的文字
        revText.resize(text.size(), '\n');//重新規劃空間給revText
        
        //一組一組的把文字反轉後，存入revText
        int i, words;
        words = (int)text.size() / group;
        for (i = 0; i < group; i++) {
            
            reverse_copy(text.begin()    + (i * words),
                         text.begin()    + ((i + 1) * words),
                         revText.begin() + (i * words));
        }
        cout << revText << '\n';//印出被反轉後的文字
        cin >> group;//得知下一個幾個一組得資訊
    }
    
    return 0;
}


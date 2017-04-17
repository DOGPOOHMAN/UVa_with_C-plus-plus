#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main(){
    int group, i, j;
    string text;
    
    cin >> group;//讀入幾個一組
    while (group != 0) {//如果group == 0程式就會結束
        
        cin >> text;//讀入將要被反轉的文字
        //一組一組的把文字倒著印出來
        for (i = 1; i <= (text.size() / group); i++) {
            
            //將迭代器指向每一組文字的尾巴
            string::iterator ite = text.begin() + (i * group) - 1;
            for (j = 0; j < group; j++)//再把文字由後往前印出來
            { cout << *ite--; }
        }
        cout << '\n';
        cin >> group;//讀入幾個一組
    }
    
    return 0;
}

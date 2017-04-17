#include <string>
#include <iostream>

#define PC_LEN   10 //總共有10個按鍵
#define NOTE_LEN 15 //總共有15組指法
using namespace std;

int pressButton(char pre, char cur){
    
    //相對應的指法簡寫，'N'代表所有按鍵都不按
    static const char note[ NOTE_LEN + 1 ] = "cdefgabCDEFGABN";
    //每一個位元代表相對應的指法，最高位元相對應題目中的第一個按鍵finger 1
    static const int  finger[ NOTE_LEN ] = {
        0b0111001111, 0b0111001110, 0b0111001100, 0b0111001000,
        0b0111000000, 0b0110000000, 0b0100000000,
        
        0b0010000000, 0b1111001110, 0b1111001100, 0b1111001000,
        0b1111000000, 0b1110000000, 0b1100000000,
        
        0b0000000000
    };
    
    int preIndex, curIndex;
    
    //找前一個按鍵的index
    preIndex = 0;
    while (note[preIndex] != pre)
    { preIndex++; }
    
    
    //找現在這一個按鍵的index
    curIndex = 0;
    while (note[curIndex] != cur)
    { curIndex++; }
   
    
    int pressed = 0, willBePressMask = 0b1111111111;
    //得知還沒被按下的按鍵位置
    pressed = finger[preIndex] ^ willBePressMask;
    //得知被按下的按鍵位置
    pressed = finger[curIndex] & pressed;
    return pressed;
}

int main(){
    
    int pressedCounter[ PC_LEN ] = {0};
    
    int group = 0;  cin >> group;
    
    int pressed, i;
    string text;
    for (i = 0; i < group; i++) {
        
        memset(pressedCounter, 0, sizeof(pressedCounter));
        
        cin >> text;//讀入樂譜
        auto ite = text.begin();//讓迭代器指向樂譜得第一個字
        
        while (ite != text.end()) {
            
            if(ite == text.begin())//如果是樂譜的第一個音符就做特別處理
            { pressed = pressButton('N', *ite++); }
            else
            { pressed = pressButton(*(ite - 1), *ite++); }
            
                      
            int pressMask = 0b1000000000, index;
            //掃描被按下的按鍵有哪些，並且把他們紀錄在pressedCounter[]
            for (index = 0; index < PC_LEN; index++) {
                
                if((pressMask & pressed) > 0)
                { pressedCounter[ index ]++; }
                pressMask >>= 1;
            }
           
        }
        
        int p;
        //印出pressCounter[]裡面的累加次數
        for (p = 0; p < PC_LEN; p++) {
            
            if (p != 0)
            { printf(" "); }
            
            printf("%d", pressedCounter[p]);
        }
        
        cout << '\n';
    }
    
    return 0;
}


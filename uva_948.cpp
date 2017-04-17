#include <string>
#include <iostream>

using namespace std;
#define FIB_LEN 45

int main(){
    unsigned fib[FIB_LEN] = {0};
    
    //初始化fib，並且算出每一個FIB(i)的數值
    fib[0] = 1;
    int index, theA = 1, theB = 1, sum = 0;
    for (index = 1; index < FIB_LEN; index++) {
        
        sum = theA + theB;
        theA = theB;
        theB = sum;
        fib[ index ] = sum;
    }
    
    

    unsigned dec;
    int i, group, fibIndex;
    cin >> group;
    for (i = 0; i < group; i++) {
        
        cin >> dec;//Input
        cout << dec << " = ";//Output
        
        //找出最接近或等於dec的fib數值
        fibIndex = FIB_LEN;
        while (fib[fibIndex] > dec) {
            fibIndex--;
        }
       
        //依照題目中的Figure 2解題方式，印出結果
        for (; fibIndex >= 0; fibIndex--) {
            
            if (dec >= fib[ fibIndex ]) {
                
                cout << "1";
                dec -= fib[ fibIndex ];
            }
            else
            { cout << "0"; }
        }
        
        cout << " (fib)" << '\n';
    }
    
    return 0;
}

#include <string>
#include <sstream>
#include <iostream>


using namespace std;

int main(){
    unsigned long long int M = 0;
    string line;
    int val, group;
    bool divi_flag;//true:所有數值都能整除  false:無法整除
    
    cin >> group;
    for (int i = 0; i < group; i++) {
        
        cin >> M;
		
    	getline(cin , line);//把前一行的換行LF讀進來，以免影響後面的作業
    	getline(cin , line);//讀取整行文字
        istringstream val_set_stream(line);//分解這行文字為一個個的單字

        divi_flag = true;
        while(val_set_stream >> val){

        	if((M % val) != 0){
        		divi_flag = false;
        		break;
        	}
        }

        //printing result
        cout << M << " - ";
        if(divi_flag)
        	cout << "Wonderful.\n";
        else
        	cout << "Simple.\n";
    }
    
    return 0;
}


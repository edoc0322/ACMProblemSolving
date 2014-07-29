#include <iostream>

using namespace std;
int dig2[100];
int dig4[10000];
int dig6[1000000];
int dig8[100000000];
int main()
{
    int n;
    int count2=0,count4=0,count6=0,count8=0;
    for(int i = 0 ; i <=9 ;i++){
        for(int j = 0 ; j <=9;j++){
            if( (i+j)*(i+j) == (i*10+j)){
                dig2[count2++] = i*10+j;
            }
        }
    }

    for(int i = 0 ; i <=99 ;i++){
        for(int j = 0 ; j <=99;j++){
            if( (i+j)*(i+j) == (i*100+j)){
                dig4[count4++] = i*100+j;
            }
        }
    }

    for(int i = 0 ; i <=999 ;i++){
        for(int j = 0 ; j <=999;j++){
            if( (i+j)*(i+j) == (i*1000+j)){
                dig6[count6++] = i*1000+j;
            }
        }
    }

    for(int i = 0 ; i <=9999 ;i++){
        for(int j = 0 ; j <=9999;j++){
            if( (i+j)*(i+j) == (i*10000+j)){
                dig8[count8++] = i*10000+j;
            }
        }
    }

    while(cin >> n){
        if(n == 2){
            for(int i = 0 ; i < count2;i++){
                if(dig2[i] <10){cout << "0";}
                cout << dig2[i]<<endl;
            }
        }
        if(n == 4){
            for(int i = 0 ; i < count4;i++){
                if(dig4[i] <10){cout << "000";}
                else if(dig4[i] <100){cout << "00";}
                else if(dig4[i] <1000){cout << "0";}
                cout << dig4[i]<<endl;
            }
        }
        if(n == 6){
            for(int i = 0 ; i < count6;i++){
                if(dig6[i] <10){cout << "00000";}
                else if(dig6[i] <100){cout << "0000";}
                else if(dig6[i] <1000){cout << "000";}
                else if(dig6[i] <10000){cout << "00";}
                else if(dig6[i] <100000){cout << "0";}
                cout << dig6[i]<<endl;
            }
        }
        if(n == 8){
            for(int i = 0 ; i < count8;i++){
                if(dig8[i] <10){cout << "0000000";}
                else if(dig8[i] <100){cout << "000000";}
                else if(dig8[i] <1000){cout << "00000";}
                else if(dig8[i] <10000){cout << "0000";}
                else if(dig8[i] <100000){cout << "000";}
                else if(dig8[i] <1000000){cout << "00";}
                else if(dig8[i] <10000000){cout << "0";}
                cout << dig8[i]<<endl;
            }
        }

    }
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int sum[101];
    int temp[101];
    int i,j,n;
    string num;
    for (i = 0 ; i < 101;i++){
        sum[i] = 0;
    }
    while(cin >> num){
        string b;

        if(num == "0"){
            int count;
            for(i = 99;i>=0;i--){
                if(sum[i]!=0){
                    count = i;
                    break;
                }
            }
            for(i = count;i>=0;i--){
                cout << sum[i];
            }
            cout << endl;
            break;

        }
        else{
            for(i = 0 ; i < 101;i++){
                temp[i] = 0;
            }
            for(i = 0 ; i < num.length();i++){
                temp[i] = (int)(num[num.length()-i-1] - '0');
            }
            for(i = 0 ; i < 100;i++){
                sum[i] += temp[i];
            }
            for(i = 0 ; i < 100-1;i++){
                sum[i+1] += sum[i] /10;
                sum[i] %= 10;
            }
            /*
            for(i = 0 ; i < 100;i++){
                cout << sum[i] ;
            }
            cout <<endl;
            */

        }
    }
    return 0;
}

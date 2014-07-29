#include <iostream>

using namespace std;

int imap[100][100];
int main()
{
    int R;
    int rowe1,rowe2,cole1[100],cole2,cole3,rowe3;
    int status = 0;
    while(cin >> R){
        if(!R) break;
        status =cole3 =rowe3= rowe1 = rowe2 = cole2 = 0;
        for(int i = 0 ; i < R ; ++i)
            cole1[i] = 0;
        for(int i = 0 ; i < R;++i){
            rowe1 = 0;
            for(int j = 0 ; j < R;++j){
                cin >> imap[i][j];
                rowe1 += imap[i][j];
                cole1[j] += imap[i][j];
            }
            if(rowe1 % 2){
                rowe3 = i;
                ++rowe2;
            }
            if(rowe2 == 2){
                status = 1;

            }
        }
        for(int i = 0 ; i < R;++i)
        {
            if(cole1[i] %2 ){
                ++cole2;
                cole3 = i;
            }
            if(cole2 == 2){
                status = 1;
            }
        }
        if(status == 0 && cole3 && rowe3){
            cout << "Change bit ("<<(rowe3+1)<<","<<(cole3+1) <<")\n";
        }
        else if(status == 1){
            cout << "Corrupt\n";
        }
        else{
            cout << "OK\n";
        }
    }
    return 0;
}

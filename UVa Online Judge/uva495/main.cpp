#include <iostream>

using namespace std;
int fnum[5001][1050];
int main()
{
    int i , j,k ;
    fnum[0][0] = 0;
    fnum[1][0] = 1;
    for(i = 2 ; i <=5000;i++){
        for(j = 0;j<1050;j++){
            fnum[i][j] = fnum[i-1][j] + fnum[i-2][j];
        }

        for(j = 0 ; j < 1050-1;j++){

            fnum[i][j+1] += fnum[i][j] / 10;
            fnum[i][j] = fnum[i][j] % 10;


        }

    }

    int n;
    while(cin >> n){
        cout << "The Fibonacci number for "<<n << " is ";
        int in = 0;
        for(i = 1049;i>=0;i--){
            if(fnum[n][i]!=0){
                in = i;
                break;
            }
        }
        for(i = in;i>=0;i--){
            cout << fnum[n][i];
        }
        cout << endl;
    }
    return 0;
}

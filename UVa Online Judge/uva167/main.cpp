#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int col[8];
int chess[8][8];
int score;

int N;
void queen(int i)
{
    if(i ==N)
    {
        int s = 0;
        for(int j = 0 ; j < N;++j){
            s+= chess[j][col[j]];
        }
        if(s > score)
        {
            score = s;
        }
    }
    else
    {
        for(int j = 0 ; j < N;++j){
            col[i] = j;
            int ok = 1;
            for(int k = 0 ; k < i ;++k){
                if(col[k] == j || abs(col[k] - col[i]) == abs(k-i))
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
            {
                queen(i+1);
            }
        }
    }
}
int main()
{
    N = 8;
    int k;
    while(cin >> k){
        for(int i = 0 ; i < k ;++i)
        {
            for(int j = 0 ; j < 8;++j)
            {
                for(int m = 0 ; m < 8;++m)
                {
                    cin >> chess[j][m];
                }
            }
            score = 0;
            queen(0);
            cout << fixed << setw(5) << score<<endl;
        }

    }

    return 0;
}

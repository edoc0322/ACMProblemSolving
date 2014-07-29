#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;

int main()
{
    int N;
    while(cin >> N && N)
    {
        string s[N];
        int bn[N];
        int Ln[N],Rn[N];
        getchar();
        for(int i = 0 ; i < N;++i)
        {
            Ln[i] = Rn[i] = 0;
            int status = 0;
            getline(cin,s[i]);
            for(int j = 0 ; j < 25;++j)
            {
                if(s[i][j] == ' ' && status == 0)
                {
                    Ln[i] = j;
                    status = 1;
                }
                else if(s[i][j] == 'X' && status == 1)
                {
                    Rn[i] = j;
                    break;
                }
            }
            //cin.getline(s,1000);
        }
        for(int i = 0 ; i < N;++i)
        {
            bn[i] = Rn[i] - Ln[i];
        }
        sort(bn,bn+N);
        int sums = 0;
        for(int i = 0 ; i < N;++i)
        {
            //cout << bn[i] << " " << bn[(int)N/2]<<endl;
            sums += abs(bn[i] - bn[0]);
        }
        cout << sums <<endl;
    }
    return 0;
}

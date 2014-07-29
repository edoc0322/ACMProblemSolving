#include <iostream>
#include <string>
using namespace std;
int M,N;
int r,c;
string maps[105];
string wantMap[105];
void printM()
{
    cout <<endl;
    for(int i = 0 ; i < M;++i)
    {
        cout << maps[i] <<endl;;
    }
    cout <<endl;
}
int main()
{
    while(cin >> M && cin >> N && cin >> r && cin >> c)
    {
        if(!M && !N && !r && !c) break;
        for(int i = 0 ; i < M;++i)
        {
            cin >> wantMap[i];
            maps[i] = wantMap[i];
            for(int j = 0 ; j < N;++j)
            {
                maps[i][j] = '0';
            }
        }
        int broken = 0;
        int ans = 0;
        for(int i = 0 ; i < M && !broken;++i)
        {
            for(int j = 0 ; j < N && !broken;++j)
            {
                if(maps[i][j] != wantMap[i][j])
                {
                    //cout << "not same " << i << "   " << j <<endl;;
                    //printM();
                    if(i + r -1 < M && j + c -1 < N)
                    {
                        ans++;
                        for(int i2 = i , r2 = 0 ; r2 < r;++r2)
                        {
                            for(int j2 = j, c2 = 0 ; c2 < c;++c2)
                            {
                                maps[i2+r2][j2+c2] = maps[i2+r2][j2+c2] == '0' ? '1' : '0';
                            }
                        }
                        //printM();
                    }
                    else
                    {
                        broken = 1;
                        break;
                    }
                }
            }
        }
        if(broken)
        {
            cout << -1 <<endl;
        }
        else
        {
            cout << ans <<endl;
        }
    }
    return 0;
}

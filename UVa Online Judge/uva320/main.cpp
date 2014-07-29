#include <iostream>
#include <cstring>
#include <cstdio>
#define maxB 32*32+1
using namespace std;
int maps[35][35];
int main()
{
    int T;
    cin >> T;
    int s,e;
    char p[10000];
    int c = 1;
    while(T--)
    {
        cin >> s>>e;
        getchar();
        cin.getline(p,10000);
        int counts = 1;
        for(int i = 0 ; i < 32;++i)
        {
            for(int j = 0 ; j < 32;++j)
            {
                maps[i][j] = 0;
            }
        }
        for(int i = 0 ; i < strlen(p);++i)
        {
            if(p[i]=='.')
            {
                cout << "Bitmap #" << c++<<endl;
                for(int j = 31;j>=0;--j)
                {
                    for(int k = 0;k< 32;++k)
                    {
                        if(maps[k][j])
                        {
                            cout << 'X';
                        }
                        else
                        {
                            cout << '.';
                        }
                    }
                    cout <<endl;
                }
                cout <<endl;
                break;
            }
            else
            {
                if(p[i]=='E')
                {
                    maps[s][e-1] = 1;
                    s++;
                }
                else if(p[i] == 'N')
                {
                    maps[s][e] = 1;
                    e++;
                }
                else if(p[i] == 'W')
                {
                    s--;
                    maps[s][e] = 1;
                }
                else
                {
                    e--;
                    maps[s-1][e] = 1;
                }
            }
        }
    }

    return 0;
}

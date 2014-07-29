#include <iostream>
#include <string>
using namespace std;

int maps[10][10];
int main()
{
    int test;
    cin >> test;
    string s;
    string s2;
    for(int t= 1 ; t <= test;++t)
    {
        int N;
        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            cin >> s2;
            for(int j = 0 ; j < N;++j)
            {
                maps[i][j] = s2[j]-'0';
            }
        }
        int M;
        cin >> M;
        while(M--)
        {
            cin >> s;
            if(s == "transpose")
            {
                for(int i = 0 ; i < N;++i)
                {
                    for(int j = 0 ; j < i ;++j)
                    {
                        int temp = maps[i][j];
                        maps[i][j] = maps[j][i];
                        maps[j][i] = temp;
                    }
                }
            }
            else if(s == "row")
            {
                int a,b;
                cin >> a >> b;
                a--;
                b--;
                for(int i = 0 ; i < N;++i)
                {
                    int temp = maps[a][i];
                    maps[a][i] = maps[b][i];
                    maps[b][i] = temp;
                }
            }
            else if(s == "col")
            {
                int a,b;
                cin >> a >> b;
                a--;
                b--;
                for(int i = 0 ; i < N;++i)
                {
                    int temp = maps[i][a];
                    maps[i][a] = maps[i][b];
                    maps[i][b] = temp;
                }
            }
            else if(s == "inc")
            {
                for(int i = 0 ; i < N;++i)
                {
                    for(int j = 0 ; j < N;++j)
                    {
                        maps[i][j] = (maps[i][j] + 1) % 10;
                    }
                }
            }
            else if(s == "dec")
            {
                for(int i = 0 ; i < N;++i)
                {
                    for(int j = 0 ; j < N;++j)
                    {
                        maps[i][j] = maps[i][j] - 1;
                        if(maps[i][j]<0)
                        {
                            maps[i][j] = 9;
                        }
                    }
                }
            }
        }
        cout << "Case #" << t <<endl;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                cout << maps[i][j];
            }
            cout <<endl;
        }
        cout <<endl;

    }
    return 0;
}

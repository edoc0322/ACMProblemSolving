#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int maps[30][30];
string sets[10000];
int order[30];
int N;
int v[30];

void dfs(int s)
{
    if(v[s] == 2)
        return;
    v[s] = 1;
    for(int i = 0 ; i < 26;++i)
    {
        if(maps[s][i] && v[i] == 0)
        {
            dfs(i);
        }
    }

    v[s] = 2;
    order[N++] = s;
}

int main()
{

    string s;
    int counts = 0;
    for(int i = 0 ; i < 30;++i)
    {
        v[i] = -1;
        order[i] = 0;
        for(int j = 0 ; j < 30;++j)
        {
            maps[i][j] = 0;
        }
    }
    N = 0;

    while(cin >> s)
    {
        if(s == "#")
        {
            for(int i = 0 ,j = i+1; j < counts; ++i,++j)
            {
                int minLen =  min(sets[i].length() ,sets[j].length() );
                for(int k = 0 ; k < minLen ; ++k)
                {
                    if(sets[i][k] != sets[j][k])
                    {
                        //cout << sets[j][k] << "  " << sets[i][k] <<endl;
                        maps[sets[j][k]-'A'][sets[i][k]-'A'] = 1;
                        v[sets[j][k]-'A'] = 0;
                        v[sets[i][k]-'A'] = 0;
                        break;
                    }
                }
            }

            for(int i = 0; i < 26;++i)
            {
                if(v[i] == 0)
                {
                    dfs(i);
                }
            }
            for(int i = 0;i < N ;++i)
            {
                cout << (char) (order[i]+'A');
            }
            cout <<endl;;


            N = 0;
            counts = 0;
            for(int i = 0 ; i < 30;++i)
            {
                order[i] = 0;
                v[i] = -1;
                for(int j = 0 ; j < 30;++j)
                {
                    maps[i][j] = 0;
                }
            }
        }
        else
        {
            sets[counts++] = s;
        }
    }
    return 0;
}

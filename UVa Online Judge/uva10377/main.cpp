#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
string maps[500];

int dirStep[4][2] = { {0,-1},{1,0} , {0,1},{-1,0}  };
int M,N;

int main()
{
    string dirC = "NESW";
    int test;
    cin >> test;
    int counts = 0;
    while(test--)
    {
        if(counts > 0)
        {
            cout << endl;
        }
        counts++;

        cin >> M >> N;
        getchar();
        for(int i = 0 ;i< M;++i)
        {
            getline(cin,maps[i]);
        }
        int dir = 0;
        int sy,sx;
        cin >> sy >> sx;
        sy--;
        sx--;
        string s;
        int over = 0;
        while(cin >> s)
        {
            for(int i = 0 ; i < s.length();++i)
            {
                if(s[i] == 'F')
                {
                    int ny = sy + dirStep[dir][1];
                    int nx = sx + dirStep[dir][0];
                    if(ny >= M || ny < 0 || nx >= N || nx < 0 || maps[ny][nx] == '*')
                    {
                        continue;
                    }
                    sy = ny;
                    sx = nx;
                }
                else if(s[i] == 'R')
                {
                    dir = (dir + 1) % 4;
                }
                else if(s[i] == 'L')
                {
                    if(dir == 0)
                    {
                        dir = 3;
                    }
                    else
                    {
                        dir -= 1;
                    }
                }
                else if(s[i] == 'Q')
                {
                    over = 1;
                    break;
                }
            }
            if(over)
            {
                break;
            }
        }
        cout << sy+1 << " " << sx+1 << " " << dirC[dir] <<endl;

    }


    return 0;
}

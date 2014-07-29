#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
int R,C;
string maps[205];
int mapNum[205][205];
int visit[205][205];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int dx2[8] = {1,1,0,-1,-1,-1,0,1};
int dy2[8] = {0,1,1,1,0,-1,-1,-1};
map<int,int> idMap;
int side;

void bdfs(int y,int x,int mark,int num)
{
    mapNum[y][x] = num;
    visit[y][x] = 1;
    for(int i = 0 ; i < 4 ; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < R && nx >= 0 && nx < C && !visit[ny][nx] && maps[ny][nx] == mark)
        {
            bdfs(ny,nx,mark,num);
        }
    }
}
void wdfs(int y,int x)
{
    visit[y][x] = 1;
    for(int i = 0 ; i < 4 ; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < R && nx >= 0 && nx < C && !visit[ny][nx] && maps[ny][nx] == '0')
        {
            wdfs(ny,nx);
        }
    }
}

void dfs(int y,int x,int mark)
{
    visit[y][x] = 1;
    for(int i = 0 ; i < 4 ; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < R && nx >= 0 && nx < C && !visit[ny][nx] && maps[ny][nx] == mark)
        {
            dfs(ny,nx,mark);
        }
    }
    for(int i = 0 ; i < 4 ; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < R && nx >= 0 && nx < C && !visit[ny][nx] && maps[ny][nx] == '0')
        {
            side++;
            wdfs(ny,nx);
        }
    }
}





int main()
{
    string codes[300];
    codes['0'] = "0000";
    codes['1'] = "0001";
    codes['2'] = "0010";
    codes['3'] = "0011";
    codes['4'] = "0100";
    codes['5'] = "0101";
    codes['6'] = "0110";
    codes['7'] = "0111";
    codes['8'] = "1000";
    codes['9'] = "1001";
    codes['a'] = "1010";
    codes['b'] = "1011";
    codes['c'] = "1100";
    codes['d'] = "1101";
    codes['e'] = "1110";
    codes['f'] = "1111";

    int test = 1;
    while(cin >> R >> C)
    {
        if(!R && !C) break;
        string s;
        for(int i = 0 ; i < R; ++i)
        {
            cin >> s;
            maps[i] = "";
            for(int j = 0 ; j < C;++j)
            {
                maps[i] += codes[s[j]];
            }
        }
        C = C*4;
        /*
        for(int i = 0 ; i < R;++i)
        {
            cout << maps[i] <<endl;
        }
        */
        memset(mapNum,0,sizeof(mapNum));
        memset(visit,0,sizeof(visit));


        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < C;++j)
            {
                if( (i == 0 || i == R-1 || j == 0 || j == C-1) && !visit[i][j] && maps[i][j] == '0')
                    bdfs(i,j,'0',1e9);
            }
        }



        string ans = "";
        for(int i = 0 ;i < R ;++i)
        {
            for(int j = 0 ; j < C;++j)
            {
                if(!visit[i][j] && maps[i][j] == '1')
                {
                    side = 0;
                    dfs(i,j,'1');
                    if(side == 0)
                    {
                        ans += "W";
                    }
                    else if(side == 1)
                    {
                        ans += "A";
                    }
                    else if(side ==2)
                    {
                        ans += "K";
                    }
                    else if(side == 3)
                    {
                        ans += "J";
                    }
                    else if(side == 4)
                    {
                        ans += "S";
                    }
                    else if(side== 5)
                    {
                        ans += "D";
                    }
                }
            }
        }




        sort(ans.begin(),ans.end());
        cout << "Case " << test++ << ": " << ans <<endl;

    }
    return 0;
}

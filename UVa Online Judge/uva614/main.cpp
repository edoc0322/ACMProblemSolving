#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int maps[20][20][4];
int visit[20][20];
int R,C;
int sr,sc,er,ec;

int dfs(int r,int c,int depth)
{
    visit[r][c] = depth;
    if(r == er && c == ec) return 2;
    int ans1 = 0,ans2 = 0,ans3 = 0,ans4 = 0;
    if(maps[r][c][3] == 0 && visit[r][c-1] == 0)
    {
        //cout << "hi1" <<endl;
        ans1 = dfs(r,c-1,depth+1);
        if(ans1 == 2) return 2;
    }
    if(maps[r][c][0] == 0 && visit[r-1][c] == 0)
    {
        //cout << "hi2" <<endl;
        ans2 = dfs(r-1,c,depth+1);
        if(ans2 == 2) return 2;
    }
    if(maps[r][c][1] == 0 && visit[r][c+1] == 0)
    {
        //cout << "hi3" <<endl;
        ans3 = dfs(r,c+1,depth+1);
        if(ans3 == 2) return 2;
        //status = 1;
    }
    if(maps[r][c][2] == 0 && visit[r+1][c] == 0)
    {
        //cout << "hi4" <<endl;
        ans4 = dfs(r+1,c,depth+1);
        if(ans4 == 2) return 2;
        //status = 1;
    }
    if(ans1 == 2 || ans2 == 2 || ans3 == 2 || ans4 == 2)
    {
        return 2;
    }
    else if(ans1 == 0 && ans2 == 0 && ans3 == 0 && ans4 ==0)
    {
        visit[r][c] = -1;
        return 0;
    }


    return 1;
}

int main()
{
    int test = 1;
    while(cin >> R >> C >> sr >> sc >> er >> ec)
    {
        if(!R && !C && !sr && !sc && !er && !ec) break;
        memset(maps,0,sizeof(maps));
        memset(visit,0,sizeof(visit));
        for(int i = 1 ; i <= R;++i)
        {
            for(int j = 1 ; j <= C;++j)
            {
                int w;
                cin >> w;
                if(i == 1) maps[i][j][0] = -1;
                if(i == R) maps[i][j][2] = -1;
                if(j == 1) maps[i][j][3] = -1;
                if(j == C) maps[i][j][1] = -1;
                if(w == 1)
                {
                    maps[i][j][1] = -1;
                    maps[i][j+1][3] = -1;
                }
                if(w == 2)
                {
                    maps[i][j][2] = -1;
                    maps[i+1][j][0] = -1;
                }
                if(w == 3)
                {
                    maps[i][j][1] = -1;
                    maps[i][j+1][3] = -1;
                    maps[i][j][2] = -1;
                    maps[i+1][j][0] = -1;
                }
            }
        }
        dfs(sr,sc,1);

        cout << "Maze " << test++ <<endl << endl;

        for(int i = 1 ; i <= R;++i)
        {
            for(int j = 1 ; j <= C;++j)
            {
                cout << "+";
                if(maps[i][j][0] == -1) cout << "---";
                else cout << "   ";
            }
            cout << "+" <<endl;
            for(int j = 1 ; j <= C;++j)
            {
                if(maps[i][j][3] == -1) cout << "|";
                else cout << " ";

                if(visit[i][j] > 0) printf("%3d",visit[i][j]);
                else if(visit[i][j] == -1) cout << "???";
                else cout << "   ";
            }
            cout << "|" <<endl;
        }
        for(int j = 1 ; j <= C;++j)
        {
            cout << "+---";
        }
        cout << "+" <<endl;
        cout << endl <<endl;
    }
    return 0;
}

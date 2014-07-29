#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int maps1[105][105];
int maps2[105][105];

int C,R;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int tot = 0;
int visit1[105][105];
int visit2[105][105];
void dfs(int y,int x,int maps[][105],int visit[][105])
{
    visit[y][x] = 1;
    vector<int> dirs;
    for(int i = 0 ; i < 4;++i)
    {
        int ny = y+dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < R && nx >= 0 && nx < C && maps[ny][nx] == 1)
        {
            if(!visit[ny][nx])
            {
                dfs(ny,nx,maps,visit);
            }
            dirs.push_back(i);
        }
    }
    if(dirs.size() == 1)
    {
        tot +=1;
    }
    else if(dirs.size() == 3)
    {
        tot += 3;
    }
    else if(dirs.size() == 4)
    {
        tot += 4;
    }
    else if(dirs.size() == 2)
    {
        if( (dirs[0] == 0 && dirs[1] == 2) || ( dirs[0] == 1 && dirs[1] == 3 ))
        {
            tot+= 2;
        }
        else
        {
            tot += 5;
        }
    }
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> C >> R;
        int n;
        cin >> n;
        int x,y;
        memset(maps1,0,sizeof(maps1));
        memset(maps2,0,sizeof(maps2));
        memset(visit1,0,sizeof(visit1));
        memset(visit2,0,sizeof(visit2));
        for(int i = 0 ; i < n;++i)
        {
            cin >> x >> y;
            maps1[y][x] = 1;
        }

        for(int i = 0 ; i < n;++i)
        {
            cin >> x >> y;
            maps2[y][x] = 1;
        }
        int ans1 = 0, ans2 = 0;
        vector<int> v1,v2;
        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < C;++j)
            {
                if(maps1[i][j] == 1 && !visit1[i][j])
                {
                    tot = 0;
                    dfs(i,j,maps1,visit1);
                    ans1++;
                    //cout << "v1 = " << tot <<endl;
                    v1.push_back(tot);
                }
            }
        }

        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < C;++j)
            {
                if(maps2[i][j] == 1 && !visit2[i][j])
                {
                    tot = 0;
                    dfs(i,j,maps2,visit2);
                    ans2++;
                    //cout << "v2 = " << tot <<endl;
                    v2.push_back(tot);
                }
            }
        }
        //cout << ans1 << "  " << ans2 << endl;
        if(ans1 != ans2)
        {
            cout << "NO\n";
        }
        else
        {
            int status = 1;
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end());
            for(int i = 0 ; i < v1.size();++i)
            {
                if(v1[i] != v2[i])
                {
                    status = 0;
                    break;
                }
            }
            if(status)
                cout << "YES\n";
            else
                cout << "NO\n";
        }

    }
    return 0;
}

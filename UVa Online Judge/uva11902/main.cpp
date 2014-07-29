#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> maps[102];
int visit[102];
int firstVisit[102];
int dominate[102][102];
int n;
int cnt;
void dfs(int u,int first)
{
    if(u == first) return;
    visit[u] = 1;
    for(int i = 0 ; i < maps[u].size();++i)
    {
        if(!visit[maps[u][i]])
            dfs(maps[u][i],first);
    }
}
int main()
{
    int test;
    cin >> test;
    for(int t = 1 ;  t <= test;++t)
    {
        cin >> n;
        memset(dominate,0,sizeof(dominate));
        for(int i = 0 ; i < n;++i)
        {
            visit[i] = 0;
            maps[i].clear();
        }
        int v;
        for(int i = 0 ; i < n;++i)
        {
            for(int j = 0 ; j < n;++j)
            {
                cin >> v;
                if(v)
                {
                    maps[i].push_back(j);
                }
            }
        }
        memset(visit,0,sizeof(visit));
        memset(firstVisit,0,sizeof(firstVisit));
        dfs(0,-1);
        for(int i = 0 ; i < n;++i)
        {
            firstVisit[i] = visit[i];
        }
        for(int i = 0 ; i < n;++i)
        {
            memset(visit,0,sizeof(visit));
            dfs(0,i);
            for(int j = 0 ; j < n;++j)
            {
                dominate[i][j] = (!visit[j] && firstVisit[j]) ? 1 : 0;
            }
            dominate[i][i] = firstVisit[i];
        }
        cout << "Case " << t << ":" <<endl;
        for(int i = 0 ; i < n;++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if(j == 0)
                {
                    cout << "+";
                }
                if(j < n-1)
                    cout << "--";
                else
                    cout << "-+";
            }
            cout << endl;
            for(int j = 0 ; j < n;++j)
            {
                cout << "|" << (dominate[i][j]  ? 'Y' : 'N') ;
            }
            cout << "|" << endl;
        }
        for(int j = 0 ; j < n ; ++j)
        {
            if(j == 0)
            {
                cout << "+";
            }
            if(j < n-1)
                cout << "--";
            else
                cout << "-+";
        }
        cout << endl;
    }
    return 0;
}

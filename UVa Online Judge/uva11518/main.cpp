#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N,M,L;
vector<int> maps[10005];
bool visit[10005];
void dfs(int num)
{
    visit[num] = true;
    for(int i = 0 ; i < maps[num].size();++i)
    {
        if(!visit[maps[num][i]])
        {
            dfs(maps[num][i]);
        }
    }
}
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        cin >> N >> M >> L;
        for(int i = 1 ; i <= N;++i)
        {
            maps[i].clear();
        }
        int s,t;
        for(int i = 0 ; i < M;++i)
        {
            cin >>s >> t;
            maps[s].push_back(t);
        }
        memset(visit,0,sizeof(visit));
        int pushD;
        for(int i = 0 ;i < L;++i)
        {
            cin >> pushD;
            if(!visit[pushD])
            {
                dfs(pushD);
            }
        }
        int counts = 0;
        for(int i = 1 ; i <= N;++i)
        {
            if(visit[i]) counts++;
        }
        cout << counts <<endl;
    }
    return 0;
}

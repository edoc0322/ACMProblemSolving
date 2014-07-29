#include <iostream>
#include <algorithm>
using namespace std;

int target;
int maps[30][30];
int visit[30];
int ans[30];
int nodes[30];
int maxV;
int ansN;
void firstDfs(int source)
{
    nodes[source] = 1;
    for(int i = 1 ;i <= maxV;++i)
    {
        if(maps[source][i] == 1 && nodes[i] == 0)
        {
            firstDfs(i);
        }
    }
}

void backtrack(int depth,int source)
{
    visit[source] = 1;
    if(source == target)
    {
        cout << 1 ;
        for(int i = 0 ; i < depth;++i)
        {
            cout << " " << ans[i];
        }
        cout << endl;
        ansN++;
        return;
    }
    if(depth >= maxV)
    {
        return;
    }
    for(int i = 1;i <= maxV;++i)
    {
        if(maps[source][i] == 1 && visit[i] == 0 && nodes[i] == 1)
        {
            ans[depth] = i;
            backtrack(depth+1,i);
            visit[i] = 0;
        }
    }
}
int main()
{
    int test = 1;
    while(cin >> target)
    {
        cout << "CASE " << test++ << ":" <<endl;
        int a,b;
        ansN = 0;
        for(int i = 0 ; i < 30;++i)
        {
            visit[i] = 0;
            nodes[i] = 0;
            for(int j = 0 ; j < 30;++j)
            {
                maps[i][j] = 0;
            }
        }
        maxV = -1;
        while(cin >> a && cin >> b)
        {
            if(a == 0 && b == 0) break;
            maps[a][b] = maps[b][a] = 1;
            maxV = max(maxV,max(a,b));
        }
        firstDfs(target);
        for(int i = 0 ; i <30;++i)
        {
            visit[i] = 0;
        }
        ans[0] = 1;
        backtrack(0,1);
        cout << "There are " << ansN << " routes from the firestation to streetcorner " << target << "." <<endl;
    }
    return 0;
}

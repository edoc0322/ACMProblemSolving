#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

struct node
{
    long long int num;
    vector<int> child;
};
int N;
node nodes[10005];
int visit[10005];
long long int ans = 0;


long long int dfs(int nodeN)
{
    visit[nodeN] = 1;
    long long int curN = 0;
    for(vector<int>::iterator it = nodes[nodeN].child.begin();
        it != nodes[nodeN].child.end();++it)
    {
        if(visit[*it] == 0)
        {
            curN += dfs(*it);
            nodes[nodeN].num += nodes[*it].num;
        }
    }
    ans += abs(nodes[nodeN].num - curN - 1);
    return curN+1;
}
int main()
{
    while(cin >> N && N)
    {
        for(int i = 1 ; i <= N;++i)
        {
            nodes[i].child.clear();
            visit[i] = 0;
        }
        int par,child;
        long long num;
        for(int i = 1 ; i <= N;++i)
        {
            cin >> par >> num >> child;
            nodes[par].num = num;
            int childN;
            for(int j = 0 ; j < child;++j)
            {
                cin >> childN;
                nodes[par].child.push_back(childN);
                nodes[childN].child.push_back(par);
            }
        }
        ans = 0;
        dfs(1);
        cout << ans <<endl;
    }
    return 0;
}

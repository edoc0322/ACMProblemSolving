#include <iostream>
#include <queue>
#include <cstdio>
#define inf 1000000000
using namespace std;

int maps[20001][20001];
int d[20001];
int v[20001];
int N,M;
struct node
{
    int s,d;
};


bool operator<(const node& n1 , const node& n2)
{
    return n1.d > n2.d;
}

int main()
{
    int test;
    cin >> test;
    int c= 1;
    while(test--)
    {
        scanf("%d",&N);
        scanf("%d",&M);
        //cin >> N;
        //cin >> M;
        int S,E;
        scanf("%d",&S);
        scanf("%d",&E);
        //cin >> S;
        //cin >> E;
        for(int i = 0 ; i < N;++i)
        {
            d[i] = inf;
            v[i] = 0;
            for(int j = 0 ; j < N;++j)
            {
                maps[i][j] = inf;
            }
        }
        for(int i = 0 ; i < M;++i)
        {
            int p1,p2,w;
            scanf("%d",&p1);
            scanf("%d",&p2);
            scanf("%d",&w);
            //cin >> p1 ;
            //cin >> p2;
            //cin >> w;
            maps[p1][p2] = maps[p2][p1] = w;
        }
        d[S] = 0;
        priority_queue<node> que;
        que.push( (node){S,d[S]} );
        for(int k = 0 ; k < N;++k)
        {
            int a = -1;

            while(!que.empty()&& v[a = que.top().s])
                que.pop();
            if(a == -1 || a == E) break;
            v[a] = 1;
            for(int i = 0 ; i < N;++i)
            {
                if(!v[i] && d[a] + maps[a][i] < d[i])
                {
                    d[i] = d[a] + maps[a][i];
                    que.push( (node) {i,d[i]} );
                }
            }
        }
        printf("Case #%d: " , c);
        //cout << "Case #" << c<< ": ";
        if(d[E] == inf)
            printf("unreachable\n");
            //cout << "unreachable\n";
        else printf("%d\n",d[E]);
            //cout << d[E] <<endl;
        c++;

    }

    return 0;
}

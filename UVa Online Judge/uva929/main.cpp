#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int oriMap[1100][1100];
int dp[1100][1100];
bool visit[1100][1100];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
struct node
{
    int x,y,minD;
};

class cmp
{
public:
    bool operator() (node&t1 , node&t2)
    {
        return t1.minD > t2.minD;
    }
};

int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int R,C;
        //cin >> R >> C;
        scanf("%d",&R);
        scanf("%d",&C);
        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < C;++j)
            {
                scanf("%d",&oriMap[i][j]);
                //cin >> oriMap[i][j];
            }
        }
        int nodes = R*C;
        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < C;++j)
            {
                dp[i][j] = 1e9;
                visit[i][j] = false;
            }

        }
        dp[0][0] = oriMap[0][0];
        priority_queue<node, vector<node> , cmp> pq;
        pq.push( (node){0,0,dp[0][0]}  );
        for(int i = 0 ; i < nodes;++i)
        {
            int x = -1,y = -1;
            while (!pq.empty() )
            {
                node temp = pq.top();
                x = temp.x;
                y = temp.y;
                if( !visit[temp.y][temp.x]) break;
                pq.pop();
            }


            if (x == -1) break;
            visit[y][x] = true;
            for (int j=0; j<4; j++)
            {
                int nx = dx[j] + x;
                int ny = dy[j] + y;
                if( ny >= 0 && ny < R && nx >= 0 && nx < C)
                {
                    if(!visit[ny][nx] && dp[y][x] + oriMap[ny][nx] < dp[ny][nx])
                    {
                        dp[ny][nx] =  dp[y][x] + oriMap[ny][nx];
                        pq.push( (node){nx,ny, dp[ny][nx]} );
                    }
                }

            }




        }
        cout << dp[R-1][C-1] <<endl;

    }
    return 0;
}

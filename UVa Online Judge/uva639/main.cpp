#include <iostream>
#include <string>
using namespace std;


int N;
int counts;
struct node
{
    int x,y;
};
node nodes[16];
string maps[4];
int maxAns =0;

void backtrack(int ans,int depth)
{
    if(depth == counts)
    {
        /*
        for(int i = 0 ; i < N;++i)
        {
            cout << maps[i] <<endl;
        }
        */
        maxAns = max(maxAns,ans);
        return;
    }
    else
    {
        int x,y;
        x = nodes[depth].x;
        y = nodes[depth].y;
        int status = 1;
        for(int i = 0 ; i < counts;++i)
        {
            //cout << nodes[i].y << " " << nodes[i].x << " " <<
            if( maps[nodes[i].y][nodes[i].x] == 'O' )
            {
                //cout << "= =? " << y <<" " << x <<endl;
                if(nodes[i].y == y )
                {
                    int status2 = 0;
                    for(int j = min(nodes[i].x,x) ; j <= max(nodes[i].x,x);++j)
                    {
                        if(maps[y][j] == 'X')
                        {
                            status2 = 1;
                            break;
                        }
                    }
                    if(status2 == 0)
                    {
                        status = 0;
                        break;
                    }
                }
                else if(nodes[i].x == x)
                {
                    int status2 = 0;
                    for(int j = min(nodes[i].y,y) ; j <= max(nodes[i].y,y);++j)
                    {
                        if(maps[j][x] == 'X')
                        {
                            status2 = 1;
                            break;
                        }
                    }
                    if(status2 == 0)
                    {
                        status = 0;
                        break;
                    }
                }
            }
        }
        if(status)
        {
            maps[y][x] = 'O';
            backtrack(ans+1,depth+1);
        }
        maps[y][x] = '.';
        backtrack(ans,depth+1);
    }
}

int main()
{
    while(cin >> N && N)
    {
        counts = 0;
        maxAns =0;
        for(int i = 0 ; i < N;++i)
        {
            cin >> maps[i];
            for(int j = 0 ; j < N;++j)
            {
                if(maps[i][j] == '.')
                {
                    nodes[counts] = (node) {j,i};
                    counts++;
                }
            }

        }
        backtrack(0,0);
        cout << maxAns <<endl;
    }
    return 0;
}

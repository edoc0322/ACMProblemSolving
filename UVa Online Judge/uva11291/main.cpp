#include <iostream>
#include <string>
#include <vector>
using namespace std;

string maps[12];
string pattern[12];
int visit[12][12];
int pvisit[12][12];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int firstY,firstX;
int R,C;
struct point
{
    int r,c;
};
vector<point> vectors;
int maxI = 0;
void dfs(int r1,int c1, int r2,int c2)
{
    point p ;
    p.r = r1;
    p.c = c1;
    vectors.push_back(p);
    visit[r1][c1] = 1;
    pvisit[r2][c2] = 1;
    for(int i = 0 ; i < 4 ; ++i)
    {
        int nx1 = dx[i] + c1;
        int ny1 = dy[i] + r1;
        int nx2 = dx[i] + c2;
        int ny2 = dy[i] + r2;
        if(nx1 >= 0 && nx1 < R && ny1 >= 0 && ny1 < R &&
            nx2 >= 0 && nx2 < C && ny2 >= 0 && ny2 < C )
        {
            if(!visit[ny1][nx1] && !pvisit[ny2][nx2] && maps[ny1][nx1] == '*' && pattern[ny2][nx2] == '*')
            {
                dfs(ny1,nx1,ny2,nx2);
            }
        }
    }
}
int main()
{

    while(cin >> R && cin >> C && R && C)
    {
        vectors.clear();
        for(int i = 0; i < R;++i)
        {
            cin >> maps[i];
        }
        for(int i = 0 ; i < C;++i)
        {
            cin >> pattern[i];
        }
        int status = 0;
        maxI = 0;
        for(int i = 0 ; i < C;++i)
        {
            for(int j = 0 ; j < C;++j)
            {
                if(pattern[i][j] == '*' )
                {
                    if(status == 0)
                    {
                        firstY = i;
                        firstX = j;
                        status = 1;
                    }
                    maxI++;
                }
            }

        }
        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < R;++j)
            {
                visit[i][j] = 0;
            }
        }

        for(int i = 0 ; i < C;++i)
        {
            for(int j = 0 ; j < C;++j)
            {
                pvisit[i][j] = 0;
            }
        }

        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < R;++j)
            {
                if(maps[i][j] == '*' && !visit[i][j])
                {
                    dfs(i,j,firstY,firstX);
                    if(vectors.size() != maxI)
                    {
                        for(int k = 0 ; k < vectors.size();++k)
                        {
                            point p = vectors[k];
                            visit[p.r][p.c] = 0;
                        }
                    }
                    vectors.clear();
                    for(int k = 0 ; k < C;++k)
                    {
                        for(int m = 0 ; m < C;++m)
                        {
                            pvisit[k][m] = 0;
                        }
                    }
                }
            }
        }
        int ans = 1;
        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < R;++j)
            {
                if(maps[i][j] == '*' && !visit[i][j])
                {
                    ans = 0;
                    break;
                }
            }
            if(!ans)
            {
                break;
            }
        }
        cout << ans <<endl;
    }
    return 0;
}

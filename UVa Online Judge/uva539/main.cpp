#include <iostream>
#include <algorithm>
using namespace std;
int map1[26][26];
int d[26][26];
int N;
int maxI;

void backtrack(int t, int cur)
{

    for(int j = 0 ; j < N ;++j)
    {
        if(cur != j && map1[cur][j] && !d[cur][j])
        {
            //cout << cur << " and " << j << " is \n";
            d[cur][j]=d[j][cur] = 1;
            t++;
            if(t > maxI)
            {
                maxI = t;
            }
            backtrack(t,j);
            t--;
            d[cur][j] = d[j][cur] = 0;
        }
    }

}
int main()
{
    int edge;
    while((cin >> N) && (cin >>edge))
    {
        if(!N && !edge)break;
        int a,b;
        int t;
        maxI = 0;
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                d[i][j] = map1[i][j] = 0;
        for(int i = 0 ; i < edge; ++i)
        {
            cin >> a ;
            cin >> b;
            map1[a][b] = map1[b][a] = 1;
        }
        for(int i = 0 ; i < N;++i)
        {
            t = 0;
            backtrack(t,i);
        }

        cout << maxI <<endl;

    }
    return 0;
}

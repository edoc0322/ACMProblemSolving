#include <iostream>
#include <algorithm>
using namespace std;
int N;

int dp[91];

struct block
{
    int x,y,z;
} blo[91];

bool cmp(block a,block b)
{
    return a.x * a.y < b.x * b.y;
}
int main()
{
    int x,y,z;
    int test = 1;
    while(cin >> N)
    {
        if(!N) break;
        for(int i = 0 ; i < N;++i)
        {
            cin >> x;
            cin >> y;
            cin >> z;
            blo[i*3].x = x;
            blo[i*3].y = y;
            blo[i*3].z = z;
            blo[i*3+1].x = x;
            blo[i*3+1].y = z;
            blo[i*3+1].z = y;
            blo[i*3+2].x = y;
            blo[i*3+2].y = z;
            blo[i*3+2].z = x;
        }
        sort(blo,blo+3*N,cmp);
        for(int i = 0 ; i < 3*N;++i)
        {
            //dp[i] = 0;
            dp[i] = blo[i].z;
            //cout << dp[i]<<endl;
        }
        for(int i = 0 ; i < 3*N;++i)
        {
            for(int j = i+1 ; j < 3*N;++j)
            {
                if(blo[i].x*2 < blo[j].x && blo[i].y*2 < blo[j].y
                   || blo[i].x*2 < blo[j].y && blo[i].y*2 < blo[j].x )
                {
                    //cout << i << " and "<< j << endl;
                    if(dp[i] + blo[j].z > dp[j])
                    {
                        dp[j] = dp[i] + blo[j].z;
                    }
                }
            }
        }

        int maxI = 0;
        for(int i = 0 ; i < 3*N;++i)
        {
            if(dp[i] > maxI)
            {
                maxI = dp[i];
            }
        }
        cout << "Case "<<test <<": the highest tower is equal to ";
        cout << maxI <<endl;
        test++;
    }

    return 0;
}

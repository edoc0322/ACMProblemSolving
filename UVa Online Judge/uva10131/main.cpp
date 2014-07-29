#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int w[1001];
int iq[1001];
int prev[1001];
struct ele
{
    int w;
    int iq;
    int seq;
} e1[1001];
bool cmp(ele a,ele b)
{
    if(a.iq > b.iq)
    {
        return true;
    }
    else if(a.iq < b.iq)
    {
        return false;
    }
    else
    {
        return a.w < b.w;
    }
}
int N;
void trace(int i)
{
    if(prev[i] != -1)
    {
        trace(prev[i]);
    }
    cout << e1[i].seq+1 <<endl;
}
int main()
{
    int N = 0;
    while((cin >> e1[N].w)&&(cin >> e1[N].iq))
    {
        //if(e1[N].w== 0 && e1[N].iq == 0 ) break;
        e1[N].seq =N;
        N++;
    }
    sort(e1,e1+N,cmp);

    for(int i = 0 ; i < N; ++i)
    {
        dp[i] = 1;
        prev[i] = -1;
    }

    for(int i = 0 ; i < N; ++i)
    {
        for(int j = i+1 ; j < N; ++j )
        {
            if(e1[i].w < e1[j].w)
            {
                if(dp[i] + 1 > dp[j])
                {
                    dp[j] = dp[i] + 1;
                    prev[j] = i;
                }
            }

        }
    }

    int maxI = 0;
    int pos = 0;
    for(int i = 0 ; i < N; ++i)
    {
        if(dp[i] > maxI)
        {
            maxI = dp[i];
            pos = i;
        }
    }
    cout << maxI <<endl;
    trace(pos);
    return 0;
}

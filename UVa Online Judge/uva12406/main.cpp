#include <iostream>

using namespace std;
long long minAns,maxAns;
int visit[20];
int p,q;

void backtrack(int depth)
{
    if(depth==p)
    {
        long long int sums = 0;
        long long int base = 1;
        for(int i = 0 ; i < p ;++i)
        {
            if(visit[i])
            {
                sums+= base;
            }
            else
            {
                sums += base*2;
            }
            base *= 10;
        }
        long long int twos = 1;
        for(int i = 0 ; i < q;++i)
        {
            twos *= 2;
        }
        if(sums % twos == 0)
        {
            if(sums > maxAns)
            {
                maxAns = sums;
            }
            if(sums < minAns)
            {
                minAns = sums;
            }
        }
        return ;
    }
    visit[depth] = 0;
    backtrack(depth+1);
    visit[depth] = 1;
    backtrack(depth+1);
}
int main()
{
    int test;
    cin >> test;
    for(int t = 1 ; t <= test;++t)
    {
        cin >> p >> q;
        minAns = 1e17;
        maxAns = -1;
        for(int i = 0 ; i < 20;++i)
        {
            visit[i] = 0;
        }
        backtrack(0);
        cout << "Case " << t <<":";
        if(maxAns == -1)
        {
            cout << " impossible" <<endl;
        }
        else if(maxAns == minAns)
        {
            cout << " " << maxAns <<endl;
        }
        else
        {
            cout << " " << minAns << " " << maxAns <<endl;
        }
    }
    return 0;
}

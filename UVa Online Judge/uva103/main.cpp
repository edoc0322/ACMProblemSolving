#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int prev[31];
int dp[31];
int N,D;
struct Weight
{
    int len[10];
    int num;
} w[31];
vector<int> posi;

void trace(int i)
{
    if(prev[i]!= -1) trace(prev[i]);
    posi.push_back(w[i].num);
}
bool cmp(Weight a,Weight b)
{
    long long int a1 = 0;
    long long int a2 = 0;
    for(int i = 0 ; i < D;++i)
    {
        a1+=a.len[i];
        a2 += b.len[i];
    }
    return a1 < a2;
}

int main()
{

    while( (cin >> N) && (cin >> D))
    {
        posi.clear();
        for(int i = 0 ; i < N;++i)
        {
            prev[i] = -1;
            dp[i] = 1;
            for(int j = 0 ; j < D;++j)
            {
                cin >> w[i].len[j];
            }
            w[i].num = i+1;
        }
        for(int i = 0 ; i < N;++i)
        {
            sort(w[i].len,w[i].len+D);
            /*
            for(int j = 0 ; j < D;++j)
            {
                cout << w[i][j] << " ";
            }
            cout <<endl;
            */
        }
        sort(w,w+N,cmp);

        for(int i = 0 ; i < N;++i)
        {
            for(int j = i + 1;j < N;++j)
            {
                int ok = 1;
                for(int k = 0 ; k < D; ++k)
                {
                    if(w[i].len[k] >= w[j].len[k])
                    {
                        ok = 0;
                        break;
                    }
                }
                if(ok)
                {
                    if(dp[i]+1 > dp[j])
                    {
                        //cout << i << " "<< j <<endl;
                        dp[j] = dp[i] + 1;
                        prev[j] = i;
                    }
                }
            }
        }
        int maxI = 0,pos = -1;
        for(int i = 0 ; i < N;++i)
        {
            if(dp[i] > maxI)
            {
                maxI = dp[i];
                pos = i;
            }
        }

        trace(pos);
        cout << maxI<<endl;
        for(int i = 0 ; i < posi.size()-1;++i)
        {
            cout << posi[i] << " ";
        }
        cout << posi[posi.size()-1] <<endl;
    }

    return 0;
}

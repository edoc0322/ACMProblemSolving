#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long int> w;
long long int position[10000011];

int main()
{
    int N;
    cin >> N;
    char s[10000];
    getchar();
    getchar();
    int test = 0;
    while(N>0)
    {
        w.clear();
        int count = 0;
        long long int temp;
        while(gets(s) && *s)
        {
            //w.push_back(t);
            temp = atoi(s);
            w.push_back(temp);
            count++;


        }
        vector<long long int> v;
        long long int n;
        n = w[0];
        v.push_back(n);
        vector<long long int> pri;
        position[0] = 1;
        long long int pos = 1;
        for(long long int i = 1 ; i < count; ++i)
        {
            n = w[i];
            //cout << n <<endl;
            if(n > v.back())
            {
                v.push_back(n);
                pos = lower_bound(v.begin(),v.end(),n) - v.begin() + 1;
                position[i] = pos;
            }
            else
            {
                pos = lower_bound(v.begin(),v.end(),n) - v.begin() + 1;
                *lower_bound(v.begin(),v.end(),n) = n;
                position[i] = pos;
            }
        }
        long long int order = v.size();
        //cout << order<<endl;

        for(long long int i = count-1; i>=0; i--)
        {
            if(position[i] == order)
            {
                //cout << w[i]<<endl;
                pri.push_back(w[i]);
                order--;
            }
            if(order == 0)
            {
                break;
            }
        }


        /*
        for(int i = 0 ; i < count;++i)
        {
            dp[i] = 1;
            prev[i] = -1;
        }

        for(int i = 0 ; i < count;++i)
        {
            for(int j = i+1 ; j < count;++j)
            {
                if(w[i] < w[j])
                {
                    //cout << w[i] << " and " <<w[j]<<endl;
                    if(dp[i]+1>dp[j])
                    {
                        dp[j] = dp[i]+1;
                        prev[j] = i;
                    }
                }
            }
        }
        int maxI = -1;
        int pos = -1;
        for(int i = 0 ;i < count;++i)
        {
            //cout << "dp is " << dp[i]<<endl;
            if(dp[i] > maxI)
            {
                maxI = dp[i];
                pos = i;
            }
        }

        cout <<"Max hits: "<<maxI <<endl;
        trace(pos);

        */
        if(test > 0)
        {
            cout << endl;
        }

        cout <<"Max hits: "<<v.size()<<"\n";
        for(long long int i = pri.size()-1 ; i >=0 ; --i)
        {
            cout << pri[i]<<endl;
        }


        test++;
        N--;
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

vector<long long int> w;
long long int position[10000011];

int main()
{
    long long int count = 0;
    long long int t;
    while(cin >> t)
    {
        //if(t == -10000) break;
        w.push_back(t);
        count++;
    }

    vector<long long int> v;
    long long int n;
    if(count == 0) cout << "0\n-\n";
    else
    {
        n = w[0];
        v.push_back(n);
        vector<long long int> pri;
        position[0] = 1;
        long long int pos = 1;
        for(long long int i = 1 ; i < count;++i){
            n = w[i];
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


        for(long long int i = count-1;i>=0;i--)
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

        cout << v.size()<<"\n-\n";
        for(long long int i = pri.size()-1 ; i >=0 ;--i)
        {
            cout << pri[i]<<endl;
        }

    }

    system("pause");
    return 0;

}

#include <iostream>

#include <map>

using namespace std;

int main()
{
    int N,Q;
    int testcase = 1;
    while((cin >>N) && (cin >> Q))
    {
        if(!N && !Q)break;
        map<int ,int> m1;
        map<int,int>m2;
        int t;
        map<int,int>::iterator iter;
        for(int i = 0 ;i < N ;++i){
            cin >> t;
            m1[t]++;
        }
        int count = 1;
        for(iter = m1.begin() ; iter != m1.end() ;++iter){
            m2[iter->first] =  count;
            count += iter->second;
        }

        cout << "CASE# "<<testcase++<<":\n";
        for(int i = 0 ; i < Q ;++i){
            cin >> t;
            if(m2[t] == 0){
                cout << t << " not found\n";
            }
            else
            {
                cout << t <<" found at "<<m2[t]<<endl;
            }
        }
    }
    return 0;
}

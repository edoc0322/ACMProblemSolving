#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    int test;
    cin >> test;
    for(int t = 1 ; t <= test;++t)
    {
        int N,D;
        cin >> N >> D;
        string s;
        vector<int> dist;
        dist.push_back(0);
        dist.push_back(0);
        for(int i = 0 ; i < N;++i)
        {
            cin >> s;
            string str = s.substr(2);
            stringstream ss;
            ss << str;
            int num;
            ss >> num;
            dist.push_back(num);
            if(s[0] == 'B')
            {
                dist.push_back(num);
            }
        }
        dist.push_back(D);
        dist.push_back(D);
        int maxI = 0;
        for(int i = 2 ; i < dist.size();++i)
        {
            maxI = max(maxI,dist[i]-dist[i-2]);
        }
        cout << "Case " << t << ": " << maxI <<endl;
    }
    return 0;
}

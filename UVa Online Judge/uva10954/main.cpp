#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    long long int num;
    while(cin >> N)
    {
        priority_queue<int, vector<int> , greater<int> > ans;
        if(!N)break;
        long long int ans2 = 0;
        for(int i = 0 ; i < N ;++i)
        {
            cin >> num;
            ans.push(num);
        }
        int minI = 0;
        while(ans.size() != 1 )
        {
            long long a = ans.top();
            ans.pop();
            long long b = ans.top();
            ans.pop();
            minI += a + b;
            ans.push(a+b);
        }

        cout << minI<<endl;
    }
    return 0;
}

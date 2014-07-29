#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct query
{
    int qnum,period;
};

class cmp
{

    public:
    bool operator()(query& q1,query& q2)
    {
        if(q1.period > q2.period)
        {
            return true;
        }
        else if(q1.period < q2.period)
        {
            return false;
        }
        else
        {
            if(q1.qnum > q2.qnum)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    }
};

priority_queue<query, vector<query> , cmp> pq;
int main()
{
    string s;
    while(cin >> s)
    {

        if(s == "#")
        {
            int K;
            cin >> K;
            for(int i = 0 ; i < K;++i)
            {
                query que = pq.top();

                pq.pop();
                cout << que.qnum <<endl;
            }
            pq = priority_queue<query, vector<query> , cmp>();
        }
        else
        {
            int num,period;
            cin >> num >> period;
            int adds = period;
            for(int i = 0 ; i <= 10000;++i)
            {
                query que;
                que.period = period;
                que.qnum = num;
                //cout << i << num <<endl;
                pq.push(que);
                period = period + adds;
            }
        }

    }
    return 0;
}

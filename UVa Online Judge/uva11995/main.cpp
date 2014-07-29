#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int N;
    while(cin >> N)
    {
        priority_queue<int,vector<int>,less<int> > pq;
        stack<int> stacks;
        queue<int> que;
        int ans[3] = {1,1,1};
        int types,num;

        for(int i = 0 ; i < N;++i)
        {
            cin >> types >> num;
            if(types == 1)
            {
                pq.push(num);
                stacks.push(num);
                que.push(num);
            }
            else
            {
                if(stacks.size() == 0)
                {
                    ans[0] = ans[1] = ans[2] = 0;
                }
                else
                {
                    int temp = stacks.top();
                    stacks.pop();
                    if(temp != num)
                    {
                        ans[0] = 0;
                    }
                    temp = que.front();
                    que.pop();
                    if(temp != num)
                    {
                        ans[1] = 0;
                    }
                    temp = pq.top();
                    pq.pop();
                    if(temp != num)
                    {
                        ans[2] = 0;
                    }
                }

            }
        }
        int sums = 0;
        int target = -1;
        for(int i = 0 ; i < 3;++i)
        {
            sums += ans[i];
            if(ans[i] == 1)
            {
                target = i;
            }
        }
        if(sums > 1)
        {
            cout << "not sure" <<endl;
        }
        else if(sums == 0)
        {
            cout << "impossible" <<endl;
        }
        else if(target == 0)
        {
            cout << "stack" << endl;
        }
        else if(target == 1)
        {
            cout << "queue" <<endl;
        }
        else if(target == 2)
        {
            cout << "priority queue" <<endl;
        }
    }
    return 0;
}

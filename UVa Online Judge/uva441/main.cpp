#include <iostream>
#include <queue>
using namespace std;

int ans[14];
int ball[14];
int N;
int maxI;
void backtrack(int index,int num)
{
    if(index == N)
    {
        if(num == maxI)
        {
            queue<int> ans2;
            for(int i = 0 ; i < N;++i)
            {
                if(ans[i])
                {
                    ans2.push(ball[i]);
                }
            }
            while(!ans2.empty())
            {
                cout << ans2.front();
                if(ans2.size()>1)
                {
                    cout << " ";
                }
                ans2.pop();
            }
            cout << endl;
            return;
        }
        else
        {
            return ;
        }

    }
    else
    {
        ans[index] = 1;
        backtrack(index+1,num+1);
        ans[index] = 0;
        backtrack(index+1,num);
    }
}
int main()
{
    maxI = 6;
    int count = 0;
    while(cin >> N && N)
    {
        for(int i = 0 ; i < N;++i)
        {
            cin >> ball[i];
            ans[i] = 0;
        }
        if(count > 0)
        {
            cout << endl;
        }
        backtrack(0,0);

        count++;
    }

    return 0;
}

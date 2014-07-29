#include <iostream>
#include <map>
#include <cmath>
#include <vector>
using namespace std;
map<int,int> square;
int peg;
vector<int> sta[51];
int re[51];
int ans ;
void backtrack(int index)
{
    if(index > ans)
    {
        ans = index;
    }
    else{
        return;
    }
    if(index == (int) sqrt(2147483647))
    {
        ans = -1;
        return;
    }
    else
    {
        for(int i = 0 ; i < peg;++i)
        {

                sta[i].push_back(index);
                int ok = 1;
                if(sta[i].size() > 1)
                {
                    if(square[sta[i][sta[i].size() - 1] + sta[i][sta[i].size() - 2]] != 1  )
                    {
                        ok = 0;
                        sta[i].pop_back();
                    }
                }
                if(ok)
                {

                    backtrack(index+1);
                }

        }
        return;
    }
    return ;
}

int main()
{
    int test;
    for(int i = 1 ; i <= (int) sqrt(2147483647);++i)
    {
        square[i*i] = 1;
    }
    cin >> test;


    for(int i = 0 ; i < test;++i)
    {
        cin >> peg;
        for(int j = 0 ; j < peg;++j)
        {
            re[j+1] = 0;
            sta[j].clear();
        }
        ans = 0;
        backtrack(1);
        if(ans == -1)
        {
            cout << -1<<endl;
            continue;
        }
        cout << ans-1 << endl;
    }


    return 0;
}

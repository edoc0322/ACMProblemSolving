#include <iostream>

using namespace std;


int s,d;
int maxS;
int visit[12];

void backtrack(int depth)
{
    if(depth == 12)
    {
        int sums = 0;
        for(int i = 0 ;i < 12;++i)
        {
            if(visit[i]) sums += s;
            else sums -= d;
        }
        int ok = 1;
        for(int i = 0 ; i <= 7;++i)
        {
            int temps = 0;
            for(int j = i ; j < i+5;++j)
            {
                if(visit[j]) temps += s;
                else temps -= d;
            }
            if(temps >= 0)
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            if(sums > maxS)
            {
                maxS = sums;
            }
        }
        return;
    }
    visit[depth] = 1;
    backtrack(depth+1);
    visit[depth] = 0;
    backtrack(depth+1);
}
int main()
{
    while(cin >> s && cin >> d)
    {
        maxS = -1;
        for(int i = 0 ; i < 12;++i)
        {
            visit[i];
        }
        backtrack(0);
        if(maxS == -1)
        {
            cout << "Deficit" <<endl;
        }
        else
        {
            cout << maxS <<endl;
        }
    }
    return 0;
}

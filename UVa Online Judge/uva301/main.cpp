#include <iostream>

using namespace std;


int maxP;
int N;
int sn;
int person[9];

int ans[23];
int maxE;
struct ticket
{
    int s,d,people;
} ticket1[23];

void backtrack(int index)
{
    if(index == N)
    {

        int sum = 0;
        for(int i = 0 ; i <sn ;++i)
        {
            //cout << price[i];
            sum+=person[i];
        }
        if(sum > maxE)
        {
            maxE = sum;
        }

        return;
    }
    else
    {

        ans[index] = 1;
        int ok = 1;
        int backup[23];
        for(int j = ticket1[index].s; j < ticket1[index].d;++j)
        {
            backup[j] = person[j];
        }
        for(int j = ticket1[index].s; j < ticket1[index].d;++j)
        {
            person[j] += ticket1[index].people;

            if(person[j] > maxP)
            {
                ok = 0;
                break;
            }
        }
        if(ok)
            backtrack(index+1);
        ans[index] = 0;
        for(int j = ticket1[index].s; j < ticket1[index].d;++j)
        {
            person[j] = backup[j] ;
        }
        backtrack(index+1);
    }
    return ;
}

int main()
{
    while((cin >> maxP) && (cin >> sn) && (cin >> N))
    {
        if(!maxP && !sn && !N) break;
        maxE = 0;
        for(int i = 0 ;i < N;++i)
        {
            cin >> ticket1[i].s;
            cin >> ticket1[i].d;
            cin >> ticket1[i].people;
            ans[i] = 0;
        }
        for(int i = 0 ; i <= sn;++i)
        {
            person[i]  = 0;
        }
        backtrack(0);
        cout << maxE<<endl;
    }
    return 0;
}

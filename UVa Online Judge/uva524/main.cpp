#include <iostream>

using namespace std;

bool prime[50];
int N;
int c;
int ans[20];
int tot;
void make_prime()
{
    for (int i=0; i<50; i++)
        prime[i] = true;

    prime[0] = false;
    prime[1] = false;

    for (int i=2; i<50; i++)
        if (prime[i])
            // 刪掉質數i的倍數，從i倍開始。
            for (int j=i*i; j<50; j+=i)
                prime[j] = false;
}

void backtrack(int i )
{
    if(i == N)
    {
        for(int j = 0 ; j < N-1;++j)
        {
            cout << ans[j] << " ";
        }

        cout << ans[N-1]<<endl;
        //tot++;
        return;
    }
    else
    {
        for(int j = 2 ; j <= N ;++j)
        {
            ans[i] = j;
            int ok = 1;
            for(int k = 0 ; k < i ;++k)
            {
                if(ans[k] == j || !prime[ans[k+1]+ans[k]])
                {
                    ok = 0;
                    break;
                }
                if(i == N-1)
                {
                    if(!prime[ans[i]+ans[0]])
                    {
                        ok = 0;
                        break;
                    }
                }

            }
            if(ok)
            {
                backtrack(i+1);
            }
        }
    }
    return ;

}


int main()
{
    make_prime();
    c = 1;
    while(cin >> N)
    {
        //tot=0;]
        if(c > 1) cout << endl;
        cout << "Case " <<c<<":"<<endl;
        ans[0] = 1;
        backtrack(1);
        //cout << tot <<endl;
        c++;

    }
    return 0;
}

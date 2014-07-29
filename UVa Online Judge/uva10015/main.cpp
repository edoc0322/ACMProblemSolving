#include <iostream>
#include <queue>
using namespace std;
bool prime[20000000];
int live[3502];
void next(int& a,int n)
{
    do
    {
        a++;
        a%=(n+1);
        if(a == 0) a = 1;
    }
    while(!live[a]);
}

void eratosthenes()
{
    for (int i=0; i<20000000; i++)
        prime[i] = true;

    prime[0] = false;
    prime[1] = false;

    for (int i=2; i<20000000; i++)
        if (prime[i])
            // k琌瞯j琌借计i计
            // パ耞讽prime[k]Θミ
            // k瞇籠┮Τ单i借计ㄤ计
            for (int k=(20000000-1)/i, j=i*k; k>=i; k--, j-=i)
                if (prime[k])
                    prime[j] = false;
}
int m[3502];
void mcc()
{
    int count = 0;
    for(int i = 2 ;i <20000000;i++){
        if(prime[i]){
            m[count++] = i;
            if(count == 3502){
                break;
            }
        }
    }
}

int josephus(int n)
{
    int answer = 0;
    for (int i=1; i<=n; ++i)
        answer = (answer + m[n-i]) % i;
    return answer+1;
}
int whoSaved(int n )
{
    int count = 0;
    int answer;

    for(int i = 1 ; i <= n ;i++)
    {
        live[i] = 1;
    }


    count = 0;
    int p = 1;
    for(int men = n;men> 1;--men)
    {
        int mm = m[count];
        for(int i = 0 ; i < (mm - 1)%men; ++i)
        {
            next(p,n);
        }
        live[p] = 0;
        next(p,n);

        count++;
    }
    answer = p;
    return answer;
}
int main()
{
    int ans[3502];
    eratosthenes();
    mcc();
    int n;
    for(int i = 1;i <= 3501;++i)
    {
        //cout << i << endl;
       ans[i] =josephus(i);
    }
    while(cin >> n){
        if(!n) break;
        cout << ans[n]<<endl;
    }
    return 0;
}

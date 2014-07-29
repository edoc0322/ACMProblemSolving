#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node
{
    int a,b,c,d;
    int sums;
};
node ans[1000000];
int cnt = 0;

bool cmp(node n1,node n2)
{
        if(n1.a != n2.a)
        {
            return n1.a < n2.a;
        }
        else
        {
            if(n1.b != n2.b)
            {
                return n1.b < n2.b;
            }
            else
            {
                if(n1.c != n2.c)
                {
                    return n1.c < n2.c;
                }
            }
        }

}
int main()
{
    for(long long int i = 1; i+i+i+i <= 2000;++i)
    {
        for(long long int j = i; i+j+j+j <= 2000;++j )
        {
            for(long long int k = j;i+j+k+k <= 2000;++k)
            {
                //cout << " = =?"<<endl;
                if(i*k*j <= 1000000) continue;
                long long int sums = i+j+k;
                long long int product = i*j*k;
                long long int m = sums*1e6 / ( product-(long long)1000000 );
                sums += m;
                //cout << i << " " << j << " " << k << " " << m  << " " << sums << " " << product <<endl;
                if( m < k || sums > 2000) continue;
                //cout << i << " " << j << " " << k << " " << m <<endl;
                if(i+j+k+m == i*j*k*m/1e6)
                {
                    ans[cnt].a = i;
                    ans[cnt].b = j;
                    ans[cnt].c = k;
                    ans[cnt].d = m;
                    ans[cnt].sums = sums;
                    cnt++;
                    //cout << i << " " << j << " " << k << " " << m <<endl;
                }
            }
        }
    }
    sort(ans,ans+cnt,cmp);
    //cout << cnt << endl;

    for(int i = 0 ; i < cnt;++i)
    {
        printf("%d.%.2d %d.%.2d %d.%.2d %d.%.2d\n",
               ans[i].a/100,ans[i].a%100,ans[i].b/100,ans[i].b%100,ans[i].c/100,ans[i].c%100,ans[i].d/100,ans[i].d%100);
    }

    return 0;
}

#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;


struct number
{
    long long int t,w,h,s;
};

bool cmp(number t1,number t2)
{
    if(t1.s != t2.s)
    {
        return t1.s < t2.s;
    }
    else
    {
        return t1.t < t2.t;
    }

}
int main()
{

    number ans[25610];

    double n1,n2;
    int cnt = 0;
    for(long long int t = 1 ; t+t+t <= 25600 ;t += 1)
    {
        for(long long w = t ; w+w+t <= 25600; w+=1)
        {
            if(w*t <= 10000) continue;
            long long int tw = t*w;
            long long int s = t+w;
            long long int h = s*(long long)10000 / (tw-10000);
            s += h;
            if( s > 25600 || h < w) continue;
            if(t + w + h == (long long)t*w*h/10000)
            {
                ans[cnt].h =h;
                ans[cnt].w = w;
                ans[cnt].s = s;
                ans[cnt].t = t;
                cnt++;
                //printf("%lld.%.2lld = %lld.%.2lld + %lld.%.2lld + %lld.%.2lld = %lld.%.2lld * %lld.%.2lld * %lld.%.2lld\n",
                 //      i/100,i%100,t/100,t%100,w/100,w%100,h/100,h%100,t/100,t%100,w/100,w%100,h/100,h%100);

            }
        }
    }
    sort(ans,ans+cnt,cmp);
    while(scanf("%lf %lf",&n1,&n2) == 2)
    {
        long long int N1 = n1*100;
        long long int N2 = n2 * 100;
        for(long long int i = 0 ; i < cnt;++i)
        {
            if(ans[i].s >= N1 && ans[i].s <= N2)
            {
                printf("%lld.%.2lld = %lld.%.2lld + %lld.%.2lld + %lld.%.2lld = %lld.%.2lld * %lld.%.2lld * %lld.%.2lld\n",
                ans[i].s/100,ans[i].s%100,ans[i].t/100,ans[i].t%100,ans[i].w/100,ans[i].w%100,ans[i].h/100,ans[i].h%100,ans[i].t/100
                ,ans[i].t%100,ans[i].w/100,ans[i].w%100,ans[i].h/100,ans[i].h%100);
            }
        }
    }
    return 0;
}

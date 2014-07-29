#include <stdio.h>
int main()
{
    int n;
    while(scanf("%d", &n) == 1 && n){
        long long int p;
        if(n == 1)  {puts("1 1");    continue;}
        for(int i = 1; ; i++){
            long long int m = i;
            if(n >= m*m && n <= (m+1)*(m+1)){
                p = m+1;  break;
            }
        }
        long long int mid = (p*p+(p-1)*(p-1)+1)/2;
        long long int x = p, y = p;
        if(p&1){
            if(n > mid)   x -= n-mid;
            else    y -= mid-n;
        }
        else{
            if(n > mid)   y -= n-mid;
            else    x -= mid-n;
        }
        printf("%lld %lld\n", x, y);
    }
    return 0;
}

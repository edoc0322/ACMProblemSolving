#include <stdio.h>

int a[1000003];
int b[1000003];
int c[1000003];
int main()
{
    int test;
    scanf("%d",&test);
    int cc =0;
    int i;
    while(test--)
    {
        int M;
        scanf("%d",&M);
        for(i = 0 ;i<=M+1;++i)
        {
            c[i] = 0;
        }
        for(i = M-1;i>=0;i--)
        {
            scanf("%d",&a[i]);
            scanf("%d",&b[i]);
        }
        for(i = 0 ; i < M;++i)
        {
            c[i] += (a[i]+b[i]);
            c[i+1] = c[i] /10;
            c[i] = c[i]%10;
        }
        int index = M+1;
        while(!c[index]) index--;
        if(cc>0)
        {
            printf("\n");
        }
        for(int i = index;i>=0;--i)
        {
            printf("%d",c[i]);
        }
        printf("\n");
        cc++;

    }
    return 0;
}

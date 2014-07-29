#include <stdio.h>

long long maps[105][105];
int N,M,K;
long long maxP,minC;



int main()
{
    int test;
    scanf("%d",&test);
    int i,j,k,x,y,t,start;
    for(t = 1 ; t <= test;++t)
    {
        scanf("%d%d%d",&N,&M,&K);
        for(i = 0 ; i < N;++i)
        {
            for(j = 0 ; j < M;++j)
            {
                scanf(" %lld",&maps[i][j]);
            }
        }

        for(i = 0 ; i < M;++i)
        {
            for(j = 1 ; j < N;++j)
            {
                maps[j][i] += maps[j-1][i];
            }
        }
        maxP = -2*1e15;
        minC = 2*1e15;

        for(i = 0 ; i < N;++i)
        {
            for(j = i ; j < N;++j)
            {
                long long int sums = 0;
                for(k = 0,start = 0 ; k < M;++k)
                {
                    sums += maps[j][k];

                    if(i > 0) sums -= maps[i-1][k];
                    while(sums > K)
                    {
                        sums -= maps[j][start];
                        if(i > 0) sums += maps[i-1][start];
                        start++;
                    }

                    if( (k-start+1)*(j-i+1) > maxP)
                    {
                        maxP = (k-start+1)*(j-i+1);
                        minC = sums;
                    }
                    else if( (k-start+1)*(j-i+1) == maxP)
                    {
                        if(minC > sums)
                            minC = sums;
                    }
                }
            }
        }
        printf("Case #%d: %lld %lld\n",t,maxP,minC);


    }

    return 0;
}

#include <stdio.h>


int oneBit[65537] = {0};
int main()
{
    int i,j;
    for(i = 1 ; i <= 65536 ; i = i << 1)
    {
        oneBit[i] = 1;
    }
    int N;
    while(scanf("%d",&N) == 1)
    {

        int dim = 1 << N;
        int poten[dim];
        int weight[dim];
        for(i = 0 ;i < dim ; ++i)
        {
            scanf("%d",&weight[i]);
            poten[i] = 0;
        }
        for(i = 0 ; i < dim; ++i)
        {
            for(j = 0 ; j < dim ; ++j)
            {
                if( i != j)
                {
                    if(oneBit[i^j] == 1)
                    {
                        poten[i] += weight[j];
                    }
                }
            }
        }

        int maxI = -1;
        for(i = 0 ; i < dim; ++i)
        {

            for(j = 0 ; j < dim ; ++j)
            {
                if( i != j)
                {
                    if(oneBit[i^j] == 1)
                    {
                        int sums  = poten[i]+poten[j];
                        if(sums > maxI)
                        {
                            maxI = sums;
                        }

                    }
                }
            }
        }
        printf("%d\n",maxI);
    }

    return 0;
}

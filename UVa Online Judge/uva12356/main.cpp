#include <iostream>
#include <cstdio>
using namespace std;
int S,B;

int SL[100010];
int SR[100010];
int main()
{
    while(scanf("%d %d",&S,&B))
    {
        if(!S && !B) break;
        for(int i = 0 ; i <= S;++i)
        {
            SL[i] = i - 1;
            SR[i] = i + 1;
        }
        int L,R;
        for(int i = 0 ; i < B;++i)
        {
            scanf("%d %d",&L,&R);
            if(SL[L] < 1)
            {
                printf("* ");
                //cout << "* ";
            }
            else
            {
                printf("%d ", SL[L]);
                //cout << SL[L] << " ";
            }
            if(SR[R] > S)
            {
                printf("*\n");
                //cout << "*\n";
            }
            else
            {
                printf("%d\n",SR[R]);
                //cout << SR[R] << endl;
            }
            SL[SR[R]] = SL[L];
            SR[SL[L]] = SR[R];

        }
        printf("-\n");
        //cout << "-" <<endl;
    }
    return 0;
}

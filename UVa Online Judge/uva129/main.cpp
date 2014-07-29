#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int N,L;
char ans[100];
int counts = 0;
char maxAns[100];
void backtrack(int depth)
{
    if(counts > N) return;
    for(int i = 'A' ; i < 'A'+L;++i)
    {
        ans[depth] = i;
        int len = depth + 1;
        int half = len/2;
        int ok = 1;
        for(int gap = 1 ; gap <= half;++gap)
        {
            int j,start1,start2;
            for(start1 = depth,start2 = depth-gap,j = 0 ;j< gap;++j )
            {
                if(ans[start1-j] != ans[start2-j])
                {
                    break;
                }
            }
            if(j == gap)
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            ans[depth+1] = '\0';
            counts++;
            if(counts == N)
            {
                for(int j = 1 ; j <= depth+1;++j)
                {
                    if(j == 65) cout <<endl;
                    if(j % 4 == 1 && j > 1 && j != 65) cout << " ";
                    cout << ans[j-1];

                }
                cout <<endl;
                cout << depth+1 <<endl;
            }

            backtrack(depth+1);
        }
    }
}
int main()
{
    while(cin >> N && cin >> L)
    {
        if(N == 0 && L == 0) break;
        counts = 0;
        backtrack(0);


    }
    return 0;
}

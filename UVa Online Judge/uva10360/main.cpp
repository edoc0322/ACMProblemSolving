#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int d,N;

int maps[1025][1025];
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        //cin >> d >> N;
        scanf("%d",&d);
        scanf("%d",&N);
        int x,y,num;
        for(int i = 0 ; i <= 1024;++i)
        {
            for(int j = 0 ; j <= 1024;++j)
            {
                maps[i][j] = 0;
            }
        }
        for(int i = 0 ; i < N;++i)
        {
            scanf("%d %d %d",&x,&y,&num);
            for(int j = max(0,x-d); j <= min(1024,x+d);++j)
            {
                for(int k = max(0,y-d); k <= min(1024,y+d);++k)
                {
                    maps[j][k] += num;
                }
            }
        }

        int minX,minY,maxNum = -1;
        for(int i = 0 ; i <= 1024;++i)
        {
            for(int j = 0 ; j <= 1024 ; ++j)
            {
                if(maps[i][j] > maxNum)
                {
                    maxNum = maps[i][j];
                    minX = i;
                    minY = j;
                    //cout << i << "   " << j <<endl;
                }
            }
        }
        cout << minX << " " << minY << " " << maxNum <<endl;

    }
    return 0;
}

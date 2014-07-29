#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
int row[8];
int ansN = 0;
vector<int> ansV[100000];
void backtrack(int depth)
{
    if(depth == 8)
    {
        int choose[8];
        for(int i = 0 ; i < 8;++i)
        {
            choose[row[i]] = i;
        }
        for(int i = 0 ; i < 8;++i)
        {
            ansV[ansN].push_back(choose[i]);
        }
        ansN++;
        return;
    }
    for(int c= 0 ; c < 8;++c)
    {
        int ok = 1;
        for(int r = 0 ; r < depth;++r)
        {
            if(c == row[r] || abs(c-row[r]) == abs(depth-r))
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            row[depth] = c;
            backtrack(depth+1);
        }
    }
}
int main()
{
    backtrack(0);
    int num[8];
    int test = 1;
    //cout << ansN <<endl;
    while( scanf("%d %d %d %d %d %d %d %d",&num[0],&num[1],&num[2],&num[3],&num[4],&num[5],&num[6],&num[7])!= EOF)
    {
        for(int i = 0 ; i < 8;++i)
        {
            num[i]--;
        }
        int minS = 100;
        for(int i = 0 ; i < ansN;++i)
        {
            int sums = 0;
            for(int j = 0 ; j < 8;++j)
            {
                if(abs(num[j]-ansV[i][j])> 0)
                    sums++ ;
            }
            if(sums < minS)
            {
                //for(int j = 0 ; j < 8 ; ++j)
                //{
                //    cout << ansV[i][j] << " ";
                //}
                //cout <<endl;
                minS = sums;
            }
        }
        cout << "Case " << test++ << ": " << minS <<endl;

    }
    return 0;
}

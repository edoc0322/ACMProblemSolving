#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int L,G;
int left[10005],right[10005];
int x[10005],r[10005];
struct node
{
    int left,right;
};
node point [10005];

bool cmp(node n1,node n2)
{
    if(n1.left != n2.left)
    {
        return n1.left < n2.left;
    }
    else
    {
        return n1.right < n2.right;
    }
}
int main()
{
    while(scanf("%d %d",&L,&G))
    {
        if(!L && !G) break;
        for(int i = 0 ; i < G;++i)
        {
            scanf("%d %d",&x[i],&r[i]);
            point[i].left = x[i] - r[i];
            point[i].right = x[i] + r[i];
        }
        sort(point,point+G,cmp);
        int curL = 0,curR = 0;
        int i = 0,j = 0 ;
        int ans = 0;
        while(curL < L)
        {
            curR = curL;
            while( j < G && point[j].left <= curL)
            {
                curR = max(curR,point[j].right);
                j++;
            }
            if(curR == curL) break;
            i = j;
            ans++;

            curL = curR;
            //cout <<curL << " is curL"  << " j is " << j <<endl;
        }
        if(curR < L)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",G-ans);
        }
    }
    return 0;
}

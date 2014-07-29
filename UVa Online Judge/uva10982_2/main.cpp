#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int s[105][105],set[105];
vector <int> v[2];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int T,c[2],all;
    cin >> T;
    for(int t=1,N,M;t<=T && cin >> N >> M;t++){
        memset(set,-1,sizeof(set));
        memset(s,0,sizeof(s));
        for(int i=0,x,y;i<M && cin >> x >> y;i++)
            s[x][y] = s[y][x] = 1;
        v[0].clear();
        v[1].clear();
        all = 0;
        for(int n=1;n<=N;n++){
            c[0] = c[1] = 0;
            for(int i=0;i<2;i++)
                for(int j=0;j<v[i].size();j++)
                    if(s[n][v[i][j]]==1)    c[i]++;
            //printf("n = %d, c[0] = %d, c[1] = %d\n",n,c[0],c[1]);
            if(c[0]<c[1])    v[0].push_back(n), all += c[0];
            else    v[1].push_back(n), all += c[1];
        }
        //printf("all = %d\n",all);
        if(all<=M/2){
            printf("Case #%d: %d\n",t,v[0].size());
            for(int i=0;i<v[0].size();i++)
                if(i==0)    printf("%d",v[0][i]);
                else    printf(" %d",v[0][i]);
            printf("\n");
        }else{
            printf("Case #%d: Impossible.\n\n",t);
        }
    }

    return 0;
}

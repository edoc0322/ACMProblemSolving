#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

char s[10],now[10];
double op[26] = {12.53,1.42,4.68,5.86,13.68,0.69,1.01,0.70,6.25,0.44,0.00,4.97,3.15,
6.71,8.68,2.51,0.88,6.87,7.98,4.63,3.93,0.90,0.02,0.22,0.90,0.52    };
char mom[5] = {'a','e','i','o','u'};
char chi[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
int len,N,visit[30];
double all;

void dfs(int lv){
    int i,j;
    if(lv&1==0 && lv){
        if(now[lv-1]=='a' || now[lv-1]=='e' || now[lv-1]=='i' || now[lv-1]=='o' || now[lv-1]=='u'){
        }
        else
            return;
    }
    if(lv==len){
        double self = 0.00;
        N++;
        for(i=0;i<len;i++)
            self += (i+1)*op[now[i]-'a'];
        all += self;
        return;
    }
    if(lv&1){
        for(i=0;i<5;i++){
            if(visit[mom[i]-'a']<2){
                visit[mom[i]-'a']++;
                now[lv] = mom[i];
                //all += (lv+1)*op[mom[i]-'a'];
                dfs(lv+1);
                visit[mom[i]-'a']--;
            }
        }
    }
    else{
        for(i=0;i<21;i++){
            if(visit[chi[i]-'a']<2){
                visit[chi[i]-'a']++;
                now[lv] = chi[i];
                //all += (lv+1)*op[chi[i]-'a'];
                dfs(lv+1);
                visit[chi[i]-'a']--;
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int T,i,j;
    double self = 0.00;
    scanf(" %d",&T);
    gets(s);
    while(T--){
        gets(s);
        self = 0.00;
        len = strlen(s);
        for(i=0;i<len;i++)
            self += (i+1)*op[s[i]-'a'];
        N = 0;
        all = 0.00;
        memset(visit,0,sizeof(visit));
        now[0] = s[0];
        visit[s[0]-'a'] = 1;
        dfs(1);
        //all += N*op[s[0]-'a'];
        double avg = all/N;
        if(self>=avg)
            printf("above or equal\n");
        else
            printf("below\n");
    }

    return 0;
}

#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;

int N,C;
int main()
{
    int test = 1;
    while(scanf("%d %d",&N,&C) == 2)
    //while(cin >> N &&cin >> C)
    {
        if(N == 0 && C == 0) break;
        //cout << "Case " << test++ <<
        printf("Case %d:\n",test++);
        list<int> que;
        for(int i = 1 ; i <= min(N,C);++i)
        {
            que.push_back(i);
        }
        char s[10];
        for(int j = 0 ; j < C;++j)
        {
            //cin >> s;
            scanf("%s",s);
            if(strcmp(s,"N") == 0)
            {

                printf("%d\n",que.front());
                //cout << que.front() <<endl;
                que.push_back(que.front());
                que.pop_front();
            }
            else if(strcmp(s,"E") == 0)
            {
                int index;
                //cin >> index;
                scanf("%d",&index);

               // printf("%d\n",index);
                que.remove(index);
                que.push_front(index);
                //que.push_back(index);
            }
        }
    }
    return 0;
}

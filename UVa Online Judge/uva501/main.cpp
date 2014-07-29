#include <iostream>
#include <stdio.h>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
int numbers[1000000];
int commands[1000000];
int visit[1000000];
int main()
{
    int test;
    scanf("%d",&test);
    int blank = 0;
    while(test--)
    {
        if(blank > 0)
        {
            cout << endl;
        }
        scanf("%d %d",&N,&M);
        for(int i = 0 ; i < N;++i)
        {
            visit[i] = 0;
            //cin >> numbers[i];
            scanf("%d",&numbers[i]);
        }
        for(int i = 0 ; i < M;++i)
        {
            //cin >> commands[i];
            scanf("%d",&commands[i]);
        }
        vector<int> vec;
        int index = 1;
        int commandIndex= 0;
        for(int i = 0 ; i < M;++i)
        {
            int target = commands[i];
            for(;index <= target;++index)
            {
                if(visit[index-1] == 0)
                {
                    //cout << index-1 << "  " << numbers[index-1]<<endl;
                    vector<int>::iterator it = lower_bound(vec.begin(),vec.end(),numbers[index-1]);
                    vec.insert(it,numbers[index-1]);
                    visit[index-1] = 1;
                }
            }
            index--;
            //int counts = 0;
           // multiset<int>::iterator iter = (sets.begin() );
            //std::advance(iter,commandIndex);
            //cout << *iter <<endl;
            printf("%d\n",vec[commandIndex]);
            commandIndex++;

        }
        blank++;
    }
    return 0;
}

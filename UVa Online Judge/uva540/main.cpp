#include <iostream>
#include <queue>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;







int main()
{
    int n;
    int test = 1;
    while(cin >>n )
    {

        if(n == 0)break;

        map<int,int> maps;
        for(int i = 0 ; i < n;++i)
        {
            int t;
            //cin >> t;
            scanf("%d",&t);
            int num;
            for(int j = 0 ; j < t;++j)
            {
                //cin >> num;
                scanf("%d",&num);
                maps[num] = i;
            }

        }
        map<int,int> teamNumInQueue;
        //map<int,int> teamIndexInQueue;
        vector<int> ans;
        for(int i = 0 ; i < n;++i)
        {
            teamNumInQueue[i] = 0;
            //teamIndexInQueue[i] = 0;
        }
        deque<int> que;
        deque<int> que2;
        //string s;
        char s[10];
        while(scanf("%s",s))
        {
            if(strcmp(s,"STOP") == 0)
            {
                cout << "Scenario #" << test++ <<endl;
                for(int i = 0 ; i < ans.size() ;++i)
                {
                    cout << ans[i] <<endl;
                }
                cout <<endl;
                break;
            }
            int num;
            if(strcmp(s,"ENQUEUE") == 0)
            //if(s == "ENQUEUE")
            {
                //cin >> num;
                scanf("%d",&num);
                int teamNum = maps[num];
                if(teamNumInQueue[teamNum] == 0)
                {
                    que.push_back(num);
                    que2.push_back(teamNum);
                    teamNumInQueue[teamNum]++;
                    //teamIndexInQueue[teamNum] = que.size();
                }
                else
                {
                    int dif = -1;
                    for(int i = 0 ; i < que2.size();++i)
                    {
                        if(que2[i] == teamNum)
                        {
                            for(int j = i ; j < que2.size();++j)
                            {
                                if(que2[j] != teamNum)
                                {
                                    break;
                                }
                                else
                                {
                                    dif = j;
                                }
                            }
                            if(dif != -1) break;
                        }
                    }
                    //cout << dif << endl;
                    que.insert(que.begin()+dif+1,num);
                    que2.insert(que2.begin() + dif+1,teamNum);
                    /*
                    cout << "current que : = ";
                    for(int i = 0 ; i < que.size();++i)
                    {
                        cout << " " <<que[i];
                    }
                    cout <<endl;
                    */
                    teamNumInQueue[teamNum]++;
                    //teamIndexInQueue[teamNum]++;
                }
            }
            else
            {
                int num = que.front();
                int teamNum = maps[num];
                que.pop_front();
                que2.pop_front();
                teamNumInQueue[teamNum]--;
                //teamIndexInQueue[teamNum]--;

                ans.push_back(num);
            }
        }



    }
    return 0;
}

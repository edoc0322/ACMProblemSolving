#include <iostream>
#include <string>
#include <deque>
using namespace std;


int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int L,N;
        cin >> L >> N;
        deque<int> LArr,RArr;
        L *= 100;
        int dis;
        string dir;
        for(int i = 0 ; i < N;++i)
        {
            cin >> dis >> dir;
            if(dir == "left")
            {
                LArr.push_back(dis);
            }
            else
            {
                RArr.push_back(dis);
            }
        }
        string status = "left";
        int sums =0;
        int curL = 0;
        while(!LArr.empty() || !RArr.empty())
        {
            if(status == "left")
            {
                if(LArr.size())
                {
                    while(LArr.front() + curL <= L)
                    {
                        curL += LArr.front();
                        LArr.pop_front();
                        if(LArr.size() == 0)
                        {
                            sums++;
                            status = "right";
                            curL = 0;
                            break;
                        }
                    }
                    if(status == "left")
                    {
                        curL = 0;
                        status = "right";
                        sums++;
                    }
                }
                else
                {
                    curL = 0;
                    sums++;
                    //cout << "left " << sums << "  " << LArr.size() << " " << RArr.size()<< endl;
                    status = "right";
                }

            }
            else
            {
                if(RArr.size())
                {
                    curL = 0;
                    while(RArr.front() + curL <= L)
                    {
                        //cout << RArr.front() + curL << " " << L <<endl;
                        curL += RArr.front();
                        RArr.pop_front();
                        if(RArr.size() == 0)
                        {
                            sums++;
                            status = "left";
                            curL = 0;
                            break;
                        }
                    }
                    if(status == "right")
                    {
                        curL = 0;
                        status = "left";
                        sums++;
                    }
                }
                else
                {
                    curL = 0;
                    sums++;
                    status = "left";
                }
            }
        }
        cout << sums <<endl;
    }
    return 0;
}

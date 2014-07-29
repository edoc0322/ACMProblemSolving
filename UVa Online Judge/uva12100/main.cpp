#include <iostream>
#include <deque>
using namespace std;

struct point
{
    int index;
    int pri;
};
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int N;
        cin >> N;
        int my;
        cin >> my;
        deque<point> priArr;
        for(int i = 0 ; i < N;++i)
        {
            int pri;
            cin >> pri;
            point p;
            p.index = i;
            p.pri = pri;
            priArr.push_back(p);
        }
        int sums = 1;
        for(int i = 0 ; ;++i)
        {
            int maxI = -1,maxN = -1;
            for(int j = 0 ; j < priArr.size();++j)
            {
                if(priArr[j].pri> maxN)
                {
                    maxN = priArr[j].pri;
                    maxI = j;
                }
            }
            //cout << priArr[0].pri << " " << maxN <<endl;
            if(priArr[0].pri == maxN)
            {
                if(priArr[0].index == my)
                {
                    cout << sums <<endl;
                    break;
                }
                else
                {
                    sums++;
                    priArr.pop_front();
                }

            }
            else
            {
                point temp = priArr[0];
                priArr.pop_front();
                priArr.push_back(temp);
            }
        }

    }
    return 0;
}

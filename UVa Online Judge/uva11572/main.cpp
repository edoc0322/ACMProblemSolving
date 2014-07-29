#include <iostream>
#include <map>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int N;
        cin >> N;
        int snow;
        map<int,int> sets;
        int counts = 0;
        int maxI = 0;
        int starts = 0;
        for(int i = 0 ; i < N;++i)
        {
            cin >> snow;
            if(sets.find(snow) == sets.end())
            {
                sets[snow]=i;
            }
            else
            {
                if(sets[snow] >= starts)
                {
                    counts = i-starts;
                    if(counts > maxI)
                    {
                        maxI = counts;

                    }
                    starts = sets[snow] + 1;

                }
                sets[snow] = i ;
            }
        }
        if(sets[snow] >= starts)
        {
            counts = N-starts;
            if(counts > maxI)
            {
                maxI = counts;

            }


        }
        cout << maxI <<endl;
    }
    return 0;
}

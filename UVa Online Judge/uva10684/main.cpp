#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[10050];
int main()
{
    int N;
    while(cin >> N &&N)
    {
        long long int maxI = 0;
        long long int curI = 0;;
        for(int i = 0 ; i < N;++i)
        {
            cin >> arr[i];
            curI += arr[i];
            if(curI >= 0)
            {
                maxI = max(maxI,curI);
            }
            else
            {
                curI = 0;
            }
        }
        if(maxI > 0)
        {
            cout << "The maximum winning streak is " << maxI << "." <<endl;
        }
        else
        {
            cout << "Losing streak." <<endl;
        }
    }
    return 0;
}

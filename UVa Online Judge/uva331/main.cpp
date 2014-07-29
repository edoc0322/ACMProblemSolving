#include <iostream>
#include <algorithm>
using namespace std;
int nums[10];
int N;
int ansN;
void backtrack(int depth)
{
    int status = 1;
    for(int i = 0 ; i < N-1;++i)
    {
        if(nums[i] > nums[i+1])
        {
            status = 0;
            break;
        }
    }
    if(status)
    {
        if(depth > 0)
        {
            ansN++;
        }
        return;
    }
    for(int i = 0 ; i < N-1;++i)
    {
        if(nums[i] > nums[i+1])
        {
            swap(nums[i],nums[i+1]);
            backtrack(depth+1);
            swap(nums[i],nums[i+1]);
        }
    }
}
int main()
{
    int t = 1;
    while(cin >> N)
    {
        if(!N) break;
        for(int i = 0 ; i < N;++i)
            cin >> nums[i];
        ansN = 0;
        backtrack(0);
        cout << "There are " << ansN << " swap maps for input data set " << t++ << "." <<endl;
    }
    return 0;
}

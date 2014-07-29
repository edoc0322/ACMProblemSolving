#include <iostream>

using namespace std;

int N;
int arr[100];
int ans = 0;
int half;
void backtrack(int index,int curVote,int depth)
{
    if(depth == N)
    {
        if(curVote < half &&arr[index]+curVote >= half)
        {
            //cout << curVote <<endl;
            ans++;
        }
        return;
    }
    else
    {
        if(depth != index)
        {
            backtrack(index,curVote+arr[depth],depth+1);

        }
        backtrack(index,curVote,depth+1);


    }
}
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        cin >> N;
        half = 0;
        for(int i = 0 ; i < N;++i)
        {
            cin >> arr[i];
            half += arr[i];
        }
        half = half/2 + 1;
        for(int i = 0 ; i < N;++i)
        {
            ans = 0;
            backtrack(i,0,0);
            cout << "party " << i+1 <<" has power index " << ans <<endl ;
        }
        cout <<endl;
    }
    return 0;
}

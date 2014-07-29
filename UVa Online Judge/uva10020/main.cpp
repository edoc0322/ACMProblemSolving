#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int M;
int cover[5010];
struct node
{
    int L,R;
};
node arr[100002];
bool cmp(node n1,node n2)
{
    if(n1.L < n2.L)
    {
        return true;
    }
    return false;

}
node ansArr[100002];
int main()
{
    int test;
    cin >> test;
    for(int t = 0 ; t < test;++t)
    {
        if(t > 0) cout <<endl;
        cin >> M;
        memset(cover,0,sizeof(cover));
        int counts = 0;
        while(cin >> arr[counts].L && cin >> arr[counts].R){
            if(!arr[counts].L && !arr[counts].R)
            {
                break;
            }
            counts++;
        }
        sort(arr,arr+counts,cmp);
        int ans = 0;
        int findAnsCount = 0;
        int left =0 ;
        int right = 0;
        for(int i = 0 ; i < counts;++i)
        {
            int findAns = -1;
            for(;i < counts && arr[i].L <= left;i++)
            {


                if(arr[i].R > right)
                {
                    findAns = i;
                    right = arr[i].R;
                }
            }
            if(findAns == -1)
            {
                break;
            }
            ansArr[findAnsCount].L = arr[findAns].L;
            ansArr[findAnsCount].R = arr[findAns].R;
            findAnsCount++;
            if(right >= M)
            {
                break;
            }
            left = right;
            i--;

        }
        if(right < M)
        {
            cout << "0\n";
        }
        else
        {
            cout << findAnsCount <<endl;
            for(int i = 0 ; i < findAnsCount;++i)
            {
                cout <<ansArr[i].L << " " << ansArr[i].R <<endl;
            }
        }

    }
    return 0;
}

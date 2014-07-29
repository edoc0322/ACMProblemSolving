#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
double d;
struct node
{
    double start,end;
};

node arr[1005];
bool cmp(node n1,node n2)
{
    if(n1.start != n2.start)
    {
        return n1.start < n2.start;
    }
    else
    {
        return n1.end < n2.end;
    }

}
const double eps = 1e-10;

int main()
{
    int t = 1;
    while(cin >> N && cin >> d)
    {
        if(!N &&d == 0) break;
        int dead = 0;
        for(int i = 0 ; i < N;++i)
        {
            cin >> arr[i].start >> arr[i].end;
            if(fabs(arr[i].end) > d)
            {
                dead = 1;
            }
        }
        if(dead)
        {
            cout << "Case " << t++ << ": " << -1 <<endl;
            continue;
        }
        sort(arr,arr+N,cmp);
        for(int i = 0 ; i < N;++i)
        {
            double newD = sqrt(d*d - arr[i].end*arr[i].end)+eps ;
            double oriX = arr[i].start;
            arr[i].start = oriX-newD;
            arr[i].end = oriX+newD;
            //cout << "fir and sec = " << arr[i].start << " " << arr[i].end <<endl;
        }


        int counts = 0;
        int i = 0,j;
        double right = -(1e+60);
        while(i < N)
        {
            while( i < N && arr[i].start <= right)
            {
                right = min(right,arr[i].end);
                i++;
            }
            if(i == N) break;
            right = arr[i].end;
            //cout << "What's right" << right <<endl;
            counts++;
        }
        cout << "Case " << t++ << ": " << counts  <<endl;

    }
    return 0;
}

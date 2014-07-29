#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
double L,W;
struct node{

    double start,end;
};
node arr[10005];
node ansArr[10005];

bool cmp(node n1,node n2)
{
    if(n1.start < n2.start)
    {
        return true;
    }
    return false;
}
int main()
{
    while(cin >> n && cin >> L && cin >> W)
    {
        int newN = 0;
        for(int i = 0 ; i < n;++i)
        {
            double posi,rad;
            cin >> posi >> rad;
            if(rad <= W/2)
            {
                 continue;
            }
            else
            {

                double len = sqrt((rad*rad)-(W/2)*(W/2));
                //cout << len<<endl;
                arr[newN].start = posi - len;
                arr[newN].end =  posi + len;
                newN++;
            }
        }
        sort(arr,arr+newN,cmp);
        double left = 0,right = 0;
        int can = 0;
        int ansCounts = 0;
        int j;
        for(int i = 0 ; i < newN;++i)
        {
            for(j = i;j < newN && arr[j].start <= left;++j)
            {
                if(arr[j].end > right)
                {
                    right = arr[j].end;
                }
            }

            if(j == i)
            {
                break;

            }
            ansCounts++;
            //cout << "MEI\n";
            left = right;
            //cout << "J = " << j << " LEFT = " << left << endl;
            i = j;
            i--;
            if(left >= L)
            {
                can = 1;
                break;
            }


        }
        if(can == 0) cout << -1 <<endl;
        else cout << ansCounts <<endl;
    }
    return 0;
}

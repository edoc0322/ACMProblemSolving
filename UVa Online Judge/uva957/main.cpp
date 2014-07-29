#include <iostream>
#include <algorithm>
using namespace std;

int num[100005];
int main()
{
    int Y,N;
    while(cin >> Y)
    {
        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            cin >> num[i];
        }

        int maxI = -1;
        int *start =NULL,*end=NULL;
        for(int i = 0 ; i  < N;++i)
        {
            int *up = upper_bound(num,num+N,num[i]+Y-1);
            int *down = &num[i];
            up--;
            //cout << up << " " << down << "  " << up-down <<endl;
            //cout << *up << " " << *down << "  " <<endl;
            int dif = up-down+1;
            if( dif> maxI )
            {

                start = down;
                end =up;
                maxI = dif;
            }
        }
        cout << maxI << " " << *start << " " << *end << endl;
    }
    return 0;
}

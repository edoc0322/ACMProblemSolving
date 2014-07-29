#include <iostream>
#include <set>
using namespace std;

int arr[10000000];
int main()
{

    set<int> sets;
    int n;
    int counts = 1;
    while(cin >> n)
    {
        int status = 1;
        for(int i = 0 ; i < n;++i)
        {
            cin >> arr[i];
            if(arr[i] < 1)
            {
                status = 0;
            }
            if(i > 0)
            {
                if(arr[i] < arr[i-1])
                {
                    status = 0;

                }
            }
        }
        if(status == 0)
        {
            cout << "Case #" << counts++ <<": ";
            cout << "It is not a B2-Sequence.\n\n";
            continue;
        }


        sets.clear();

        for(int i = 0 ; i < n;++i)
        {
            for(int j = i ; j < n;++j)
            {
                int sums = arr[i] + arr[j];
                //cout << sums << endl;
                if(sets.find(sums) != sets.end())
                {
                    status = 0;
                    break;
                }
                sets.insert(sums);
            }
            if(status == 0)
            {
                break;
            }
        }
        cout << "Case #" << counts++ <<": ";
        if(status ) cout << "It is a B2-Sequence.\n\n";
        else cout << "It is not a B2-Sequence.\n\n";
    }
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int R,C,M,N;
int arr[26];
int main()
{
    int T,t;
    cin >> T;
    for(t = 1 ; t <= T;++t)
    {
        for(int i = 0 ; i < 26;++i)
        {
            arr[i] = 0;
        }
        cout << "Case " <<t << ": ";
        cin >> R >> C >> M >> N;
        string s;
        for(int i = 0 ; i < R;++i)
        {
            cin >> s;
            for(int j = 0 ; j < C;++j)
            {
                arr[s[j]-'A']++;
                //cout << s[i]-'A' << " " << arr[s[i]-'A'] <<endl;
            }
        }

        sort(arr,arr+26);
        int maxI = arr[25];
        int sums = 0;
        for(int j = 25;j >= 0;--j)
        {
            if(arr[j] == maxI)
            {
                sums += M * arr[j];
            }
            else
            {
                sums += N * arr[j];
            }
        }
        cout << sums <<endl;

    }
    return 0;
}

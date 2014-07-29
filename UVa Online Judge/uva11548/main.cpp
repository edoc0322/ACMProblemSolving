#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string s1[100];

int findMax(int ind1,int ind2)
{
    int len1 = s1[ind1].length();
    int len2 = s1[ind2].length();
    int maxS = 0;
    for(int i = 0 ; i < len1;++i)
    {
        int sums = 0;
        for(int j = 0,x= i; j < len2 && x < len1;++j,++x)
        {
            if(s1[ind1][x] == s1[ind2][j])
            {
                sums++;
            }
        }
        if(sums > maxS)
        {
            maxS = sums;
        }
    }
    return maxS ;
}
int main()
{
    int test;

    cin >> test;
    while(test--)
    {
        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            cin >> s1[i];
        }
        int ans = 0;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                if(i!= j )
                {
                    ans = max(ans,findMax(i,j));
                }
            }
        }
        cout << ans <<endl;

    }
    return 0;
}

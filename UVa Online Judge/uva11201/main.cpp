#include <iostream>
#include <string>
#include <map>
using namespace std;

string s;
int Len;
int counts = 0;
int maps[3000];
char ans[100000];

double table[26] = {12.53,1.42,4.68,5.86,13.68,0.69,1.01,0.70,6.25,0.44,0.00,4.97,3.15,
6.71,8.68,2.51,0.88,6.87,7.98,4.63,3.93,0.90,0.02,0.22,0.90,0.52};
double average = 0;
void backtrack(int depth)
{
    if(depth == Len)
    {
        ans[depth] = '\0';
        //cout << ans <<endl;
        for(int i = 0 ; i < Len;++i)
        {
            average += (double)(i+1) * table[ans[i]-'a'];
        }
        counts++;
        return;
    }
    for(int i = 'a' ; i <= 'z';++i)
    {
        if(depth &1) //even
        {
            if(i == 'a' || i == 'e' || i == 'o' || i == 'i' || i == 'u')
            {
                if(maps[i] < 2)
                {
                    maps[i-'a']++;
                    ans[depth] = (char)i;
                    backtrack(depth+1);
                    maps[i-'a']--;
                }
            }
        }
        else
        {
            if( !(i == 'a' || i == 'e' || i == 'o' || i == 'i' || i == 'u'))
            {
                if(maps[i] < 2)
                {
                    maps[i-'a']++;
                    ans[depth] = (char)i;
                    backtrack(depth+1);
                    maps[i-'a']--;
                }
            }
        }
    }
}
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        cin >> s;
        Len = s.length();
        for(int i = 0 ; i < 30;++i)
        {
            maps[i] = 0;
        }
        maps[s[0]-'a']++;
        ans[0] = s[0];
        average = 0;
        counts = 0;
        backtrack(1);
        average = average / (double) counts;
        double average2 = 0;
        for(int i = 0 ; i < Len;++i)
        {
            average2 += (double)(i+1) * table[s[i]-'a'];
        }
        if(average2 >= average)
        {
            cout << "above or equal" <<endl;
        }
        else
        {
            cout << "below" <<endl;
        }

    }
    return 0;
}

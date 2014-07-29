#include <iostream>

#include <string>
#include <sstream>
using namespace std;

int ans[10000000];
int checkNoRepeat(int num)
{
    int v[10] = {};
    while(num)
    {
        if(v[num%10]) return 0;
        v[num%10] = 1;
        num /= 10;
    }
    return 1;
}
int check(int num)
{
    string s;
    stringstream ss;

    ss << num;
    ss >> s;
    int len = s.length();
    int visit[s.length()];
    for(int i = 0 ; i < len;++i)
    {
        visit[i] = 0;
    }
    int counts;
    int index = 0;
    counts = s[0] - '0';
   // cout <<"num " << num << endl;
    for(int i = 0 ; i < len;++i)
    {
        counts = counts % len;
        index = (counts + index) % len;
        //cout << "index " << index <<endl;
        visit[index]++;
        if(visit[index] > 1)
        {
            return 0;
        }
        counts = s[index] - '0';
    }
    return 1;
}
int main()
{
    int num;
    int counts = 1;
    for(int i = 9999999;i>=10;--i)
    {
        //cout << i <<endl;
        if(checkNoRepeat(i))
        {
            if(check(i) == 1)
            {
                ans[i] = i;
            }
            else
                ans[i] = ans[i+1];
        }
        else
        {
            ans[i] = ans[i+ 1] ;
        }
    }
    while(cin >> num && num)
    {
        cout << "Case " << counts++ << ": ";
        cout << ans[num] <<endl;
    }
    return 0;
}

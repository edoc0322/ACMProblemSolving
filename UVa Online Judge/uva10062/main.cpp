#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


struct ver
{
    int asi,num;
};

bool cmp(ver v1,ver v2)
{
    if(v1.num == v2.num)
    {
        return v1.asi > v2.asi;
    }
    else
    {
        return v1.num < v2.num;
    }

}

int main()
{
    string s;
    int test = 0;
    while(getline(cin,s))
    {
        if(test > 0)
        {
            cout <<endl;
        }
        test++;
        int ans[300];
        ver arr[300];
        int counts = 0;
        for(int i = 0 ; i < 300;++i)
        {
            ans[i] = 0;
        }
        for(int i = 0 ; i < s.length();++i)
        {
            ans[s[i]]++;
        }
        for(int i = 0 ; i < 300;++i)
        {
            if(ans[i] > 0)
            {
                arr[counts].asi = i;
                arr[counts].num = ans[i];
                counts++;
            }
        }
        sort(arr,arr+counts,cmp);
        for(int i = 0 ; i < counts;++i)
        {
            cout << arr[i].asi << " " << arr[i].num <<endl;
        }
    }
    return 0;
}

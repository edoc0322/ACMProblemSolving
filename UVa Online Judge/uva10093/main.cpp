#include <iostream>
#include <string>
using namespace std;

int ans[250];
int main()
{

    for(int i = 0 ; i < 250;++i)
    {
        ans[i] = -1;
    }
    for(int i = 0 ; i <= 9;++i)
    {
        ans['0'+i] = i;
        //cout <<  ans['0'+i] <<endl;
    }
    for(int i = 0 ; i <= 25;++i)
    {
        ans['A'+i] = i + 10;
        //cout <<  ans['A'+i] <<endl;
    }
    for(int i = 0 ; i <= 25;++i)
    {
        ans['a'+i] = i + 36;
       // cout <<  ans['a'+i] <<endl;
    }
    string s;
    while(cin >> s)
    {
        int maxD = -1;
        int sums = 0;
        for(int i = 0 ;i < s.length();++i)
        {
            if(ans[s[i]] != -1)
            {
                sums += ans[s[i]];
                if(maxD < ans[s[i]])
                {
                    maxD = ans[s[i]];
                }
            }
        }
        if(!maxD)
        {
            maxD = 1;
        }
        int minAns;
        int status = 0;
        for(minAns = maxD ; minAns <= 61;++minAns)
        {
            if(sums % minAns == 0)
            {
                status = 1;
                break;
            }
        }
        if(status)
        {
            cout << minAns+1 <<endl;
        }
        else
        {
            cout << "such number is impossible!\n";
        }
    }
    return 0;
}

#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
    int N;
    while(cin >> N)
    {
        int test;
        string s1,s2;
        getchar();
        for(test = 1 ; test <= N;++test)
        {
            getline(cin,s1);
            getline(cin,s2);
            if(s1 == s2)
            {
                cout << "Case " << test << ": Yes" <<endl;
            }
            else
            {
                string ans1,ans2;
                ans1 = "";
                ans2 = "";
                string temp;
                stringstream ss1(s1);
                stringstream ss2(s2);
                while(ss1 >> temp)
                {
                    ans1 += temp;
                }
                while(ss2 >> temp)
                {
                    ans2 += temp;
                }
                if(ans1 != ans2)
                {

                    cout << "Case " << test <<": Wrong Answer" <<endl;
                }
                else
                {
                    cout << "Case " << test << ": Output Format Error" <<endl;
                }
            }

        }
    }
    return 0;
}

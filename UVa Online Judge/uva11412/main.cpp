#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char pattern[8] = "RGBYOV\0";
string s[2];
int correctA[2],correctB[2];
int ans = 0;
int visit[6];
int num1[200],num2[200];

void backtrack()
{
    for(int n1 = 0 ; n1 < 6;++n1)
    {
        for(int n2 = 0 ; n2 <6;++n2)
        {
            if(n1 == n2) continue;
            for(int n3 = 0 ; n3 < 6;++n3)
            {
                if(n3 == n2|| n3 == n1) continue;
                for(int n4 = 0 ; n4 < 6;++n4)
                {
                    if(n4 == n3 || n4 == n2 || n4 == n1) continue;
                    int ok = 1;
                    for(int i = 0 ; i < 2;++i)
                    {
                        string cmpS = "";
                        int calA = 0,calB = 0;
                        for(int j = 0 ; j < 200;++j)
                        {
                            num1[j] = num2[j] = 0;
                        }
                        cmpS += pattern[n1];
                        cmpS += pattern[n2];
                        cmpS += pattern[n3];
                        cmpS += pattern[n4];

                        for(int j = 0 ; j<4;++j)
                        {
                            if(cmpS[j] == s[i][j]) calA++;
                            num1[cmpS[j]]++;
                            num2[s[i][j]]++;
                        }
                        int sums = 0;
                        for(int j = 0 ; j < 200;++j)
                        {
                            calB += min(num1[j],num2[j]);
                        }
                        calB -= calA;
                        //cout << calB << "  " << calA << " " << cmpS << " " << s[i] <<endl;;
                        if(calA == correctA[i] && calB == correctB[i])
                        {
                            continue;
                        }
                        else
                        {
                            ok = 0;
                            break;
                        }
                    }
                    if(ok)
                    {
                        ans++;
                        return;
                    }
                }
            }
        }
    }


}
int main()
{
    int test;
    cin >> test;
    char temp;
    while(test--)
    {
        for(int i = 0 ; i < 6;++i)
        {
            visit[i] = 0;
        }
        cin >> s[0];
        cin >> correctA[0] >> correctB[0];
        cin >> s[1];
        cin >> correctA[1] >> correctB[1];
        ans = 0;
        backtrack();
        if(ans) cout << "Possible" <<endl;
        else cout << "Cheat" <<endl;
    }
    return 0;
}

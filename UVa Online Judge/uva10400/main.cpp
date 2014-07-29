#include <iostream>
#define MAX 32000
#include <string>
#include <vector>
using namespace std;

int dp[101][64001];
int num[101];
int prev[101][64001][4];
int prev2[101][64001];
int N;
string ope[4] = {"+","-","*","/"};
vector<string> stringAns ;
void printAns(int ans)
{
    stringAns.clear();
    int prevN = ans;
    //cout << prevN <<endl; ;
    for(int i = N-1;i>0;--i)
    {
        for(int k = 0;k < 4 ;++k)
        {
            if(prev[i][prevN][k] == 1)
            {
                if(k == 0)
                {
                    if(prev2[i][prevN]-MAX+num[i] == prevN-MAX)
                    {
                        stringAns.push_back(ope[k]);
                        break;
                    }
                }
                else if(k == 1)
                {
                    if(prev2[i][prevN]-MAX-num[i] == prevN-MAX)
                    {
                        stringAns.push_back(ope[k]);
                        break;
                    }
                }
                else if(k == 2)
                {
                    if((prev2[i][prevN]-MAX)*num[i] == prevN-MAX)
                    {
                        stringAns.push_back(ope[k]);
                        break;
                    }
                }
                else
                {
                    if((prev2[i][prevN]-MAX)/num[i] == prevN-MAX && (prev2[i][prevN]-MAX) % num[i] == 0)
                    {
                        stringAns.push_back(ope[k]);
                        break;
                    }
                }

            }
        }
        prevN = prev2[i][prevN];
        //cout << prevN <<endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            cin >> num[i];
        }
        int ans;
        cin >> ans;
        for(int i = 0 ; i <= 64000;++i)
        {

            for(int j = 0 ; j < 101;++j)
            {
                dp[j][i] = 0;
                prev2[j][i] = -1;
                for(int k = 0 ; k < 4;++k)
                {
                    prev[j][i][k] = 0;
                }

            }
        }
        dp[0][num[0]+MAX] = 1;

        for(int i = 1;i < N;++i)
        {
            int newDp[64001];
            for(int j = 0 ; j <= 64000;++j)
            {
                newDp[j] = 0;
            }
            for(int j = 0 ; j <= 64000;++j)
            {
                if(dp[i-1][j] == 1)
                {
                    int temp;
                    temp = (j-MAX)+num[i];
                    if(temp >= -32000 && temp <= 32000)
                    {
                        newDp[temp+MAX] = 1;
                        prev[i][temp+MAX][0] = 1;
                        //cout << "hi+ " <<(j-MAX) << " "<< i << " " << temp+MAX <<endl;
                        prev2[i][temp+MAX] = j;
                    }
                    temp = (j-MAX)-num[i];
                    if(temp >= -32000 && temp <= 32000)
                    {
                        newDp[temp+MAX] = 1;
                        prev[i][temp+MAX][1] = 1;
                        //cout << "hi- " <<(j-MAX) << " "<< i << " " << temp+MAX <<endl;
                        prev2[i][temp+MAX] = j;
                    }
                    temp = (j-MAX)*num[i];
                    if(temp >= -32000 && temp <= 32000)
                    {
                        newDp[temp+MAX] = 1;
                        prev[i][temp+MAX][2] = 1;
                        //cout << "hi* " <<(j-MAX) << " "<< i << " " << temp+MAX <<endl;
                        prev2[i][temp+MAX] = j;
                    }
                    temp = (j-MAX)/num[i];
                    if((j-MAX) % num[i] == 0)
                    {
                        if(temp >= -32000 && temp <= 32000)
                        {
                            newDp[temp+MAX] = 1;
                            prev[i][temp+MAX][3] = 1;
                            //cout << "hi/ " <<(j-MAX) << " "<< i << " " << temp+MAX <<endl;
                            prev2[i][temp+MAX] = j;
                        }
                    }

                }
            }
            for(int j = 0 ; j <= 64000;++j)
            {
                dp[i][j] = newDp[j];
            }
        }
        if(dp[N-1][ans+MAX] == 1)
        {
            cout << num[0];
            printAns(ans+MAX);
            for(int i = 1; i < N;++i)
            {
                cout <<stringAns[stringAns.size()-(i)] << num[i];
            }
            cout << "=" << ans <<endl;
        }
        else
        {
            cout << "NO EXPRESSION" <<endl;
        }
    }
    return 0;
}

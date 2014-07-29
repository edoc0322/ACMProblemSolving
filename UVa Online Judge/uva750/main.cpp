#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<int> ansV[100000];
int tempAns[900];
int visit[900];
int sr,sc;
int ansN;
int dif;
int changeC[900];
void backtrack(int startR,int depth)
{
    if(depth == 7)
    {
        //cout << "= = ?";

        for(int i = 1 ; i <= 8;++i)
        {
            changeC[tempAns[i]]=i;
        }
        for(int i = 1 ; i <= 8;++i)
        {
            ansV[ansN].push_back(changeC[i]);
        }
        ansN++;
        return;
    }
    for(int i = 1 ; i <= 8;++i)
    {
        int ok = 1;
        for(int j = 1; j <= 8;++j )
        {
            if(visit[j])
            {
                if(i == tempAns[j] || abs(i-tempAns[j]) == abs(j-startR))
                {
                    ok = 0;
                    break;
                }
            }
        }
        if(ok)
        {
            //cout <<depth <<" " << i <<endl;
            tempAns[startR] = i;
            visit[startR] = 1;
            int ny;
            if(startR == 8)
            {
                ny = 1;
            }
            else
            {
                ny = startR +1;
            }
            backtrack(ny,depth+1);
            visit[startR] = 0;
        }
    }
}
bool cmp(vector<int> v1,vector<int> v2)
{
    for(int i = 0 ; i < v1.size();++i)
    {
        if(v1[i] == v2[i]) continue;
        else if(v1[i] < v2[i])return true;
        else return false;
    }
}
int main()
{
    int test;
    cin >> test;
    for(int t = 1 ; t <= test;++t)
    {
        if(t > 1) cout <<endl;
        cin >> sr >> sc;
        for(int i = 1;i<= 8;++i)
        {
            visit[i] = 0;
        }
        for(int i = 0 ; i < 100000;++i)
        {
            ansV[i].clear();
        }
        visit[sr] = 1;
        tempAns[sr] = sc;
        dif = sr - 1;
        ansN = 0;
        int ny;
        if(sr == 8)
        {
            ny = 1;
        }
        else
        {
            ny = sr +1;
        }
        backtrack(ny,0);
        cout << "SOLN       COLUMN" <<endl;
        cout << " #      1 2 3 4 5 6 7 8" <<endl <<endl;
        if(ansN != 0)
            sort(ansV,ansV+ansN,cmp);
        for(int i = 0 ; i < ansN;++i)
        {
            printf("%2d",i+1);
            cout << "     ";
            for(int j = 0 ; j < 8;++j)
            {
                cout << " " << ansV[i][j];
            }
            cout <<endl;
        }
    }
    return 0;
}

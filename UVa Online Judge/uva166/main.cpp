#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#define maxI 9999999
using namespace std;

int coin[6] = {5,10,20,50,100,200};
int coinNum[6];
int target;

int dp2[100000000];
int minAns ;

int findAns(int depth,int curCoin,int useNum)
{
    if(depth == 6)
    {
        if(curCoin >= target)
        {
            //cout << "curCoint - target " << curCoin - target << " " << curCoin << "  " << target<<endl;
            useNum = useNum +dp2[curCoin - target];
            //cout << useNum <<endl;
            minAns = min(minAns,useNum);
        }
        return 0;
    }

    for(int i = 0 ; i <= coinNum[depth];++i)
    {
        findAns(depth+1,curCoin+coin[depth]*i,useNum+i);
    }
}

int main()
{
    for(int i = 0 ; i < 100000000;++i)
    {
        dp2[i] = maxI;
    }
    dp2[0] = 0;
    for(int i = 0 ; i < 6;++i)
    {
        for(int j = coin[i] ; j <= 500;++j)
        {
            dp2[j] = min(dp2[j],dp2[j-coin[i]]+1);
        }
    }
    while(cin >> coinNum[0] && cin >> coinNum[1] &&cin >> coinNum[2] &&cin >> coinNum[3]
          &&cin >> coinNum[4] &&cin >> coinNum[5] )
    {
        if(!coinNum[0]&&!coinNum[1]&&!coinNum[2]&&!coinNum[3]&&!coinNum[4]&&!coinNum[5]) break;
        double s ;
        cin >> s;
        //cout << s*100 <<endl;
        s *=100;
        target = round(s);
        minAns = maxI;
        findAns(0,0,0);
        cout << fixed << setw(3)<<minAns << endl;
    }
    return 0;
}

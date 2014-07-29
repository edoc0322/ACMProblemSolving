#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int oriNum[10000][4];
int main()
{
    for(int i = 0 ; i < 10000;++i)
    {
        int temp = i;
        for(int j = 0 ; j < 4;++j)
        {
            oriNum[i][j] = temp%10;
            temp /= 10;
        }
    }

    int test;
    cin >> test;
    while(test--)
    {
        int N;
        cin >> N;
        int guessNum[N][4];
        bool ans[10000];
        for(int i = 0 ; i < 10000;++i)
        {
            ans[i] = true;
        }

        for(int i = 0 ; i < N;++i)
        {
            int n1,corA,corB;
            char rr;
            cin >> n1;
            //cout << "mei " << n1;
            cin >> corA >> rr >> corB;
            int numArr[4];
            int temp = n1;
            for(int j = 0 ; j < 4 ;++j)
            {
                numArr[j] = temp % 10;
                temp/= 10;
            }
            for(int num = 0 ; num < 10000;++num)
            {

                //cout << "mei 2 " << corB<<endl;
                int number1[10] = {0};
                int number2[10] = {0};

                int curA = 0,curB = 0;
                for(int j = 0 ; j < 4 ;++j)
                {
                    if(oriNum[num][j] == numArr[j])
                    {
                        curA++;
                    }
                    number1[oriNum[num][j]]++;
                    number2[numArr[j]]++;
                }
                for(int j = 0 ; j < 10;++j)
                {
                    curB += min(number1[j],number2[j]);
                }

                curB -= curA;
                //if(num == 3411)
                  //cout << num << " " << curA << " " << curB << " " << corA << " " << corB << " ans = "<< ans[num] << "  " << ( (curA == corA) && (curB == corB)) << endl;

                ans[num] = ans[num] && ( (curA == corA) && (curB == corB));
                //if(num == 3411)
                 //   cout << ans[num];
            }
        }

        int ansNum;
        int counts = 0;
        for(int i = 0 ; i < 10000;++i)
        {
            if(ans[i])
            {
                ansNum = i;
                counts++;
                //cout << ansNum <<endl;
            }
        }
        if(counts == 1)
        {
            printf("%.4d\n",ansNum);
        }
        else if(counts > 1)
        {
            cout << "indeterminate" <<endl;
        }
        else
        {
            cout << "impossible" <<endl;
        }

    }

    return 0;
}

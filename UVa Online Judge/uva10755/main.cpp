#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long int arr[21][21][21];
int A,B,C;

long long int max1DSum(long long sumsArr[21])
{
    long long int subArr[21];
    long long int subAns = -100000000000000LL;
    long long int curI = 0;
    for(int i = 0 ; i < C;++i)
    {

        if(curI >= 0)
        {
            curI += sumsArr[i];
        }
        else
        {
            curI = sumsArr[i];
        }
        subAns = max(subAns,curI);
    }
    //cout << "= =?" << subAns << endl;
    return subAns;
}

long long int max2DSum(long long sumsArr[][21])
{
    long long int subArr[21];
    long long int subAns = -100000000000000LL;
    for(int i = 0 ; i < B;++i)
    {
        memset(subArr,0,sizeof(subArr));
        for(int j = i ; j < B;++j)
        {

            for(int k = 0 ; k < C;++k)
            {
                subArr[k] += sumsArr[j][k];
            }
            subAns = max(subAns,max1DSum(subArr));
        }
    }
    return subAns;
}

long long int max3DSum()
{
    long long int subArr[21][21];
    long long int subAns = -100000000000000LL;
    for(int i = 0 ; i < A;++i)
    {
        memset(subArr,0,sizeof(subArr));
        for(int j = i ; j < A;++j)
        {

            for(int k = 0 ; k < B;++k)
            {
                for(int m = 0 ; m < C;++m)
                {
                    subArr[k][m] += arr[j][k][m];
                }
            }
            subAns = max(subAns,max2DSum(subArr));
        }
    }
    return subAns;
}

int main()
{
    int test;
    cin >> test;
    for(int t = 0 ;t < test;++t)
    {
        if(t > 0 ) cout <<endl;
        cin >> A >> B >>C;
        for(int i = 0 ; i < A;++i)
        {
            for(int j = 0 ; j < B;++j)
            {
                for(int k = 0 ; k < C;++k)
                {
                    cin >> arr[i][j][k];
                }
            }
        }
        //cout << " = =? " << max3DSum() <<endl;
        //ans = max(ans,max3DSum());
        cout << max3DSum()<<endl;

    }
    return 0;
}

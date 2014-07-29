#include <iostream>
#include <string>
#include <sstream>
#define maxI 99999999

using namespace std;
int d[101][101];
int N;

int main()
{
    while(cin >> N)
    {
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                d[i][j] = maxI;
            }
        }
        for(int i= 0 ; i < N;++i)
        {
            d[i][i] = 0;
        }
        for(int i = 1;i < N;++i)
        {
            for(int j = 0 ; j < i ;++j)
            {
                string t;
                cin >> t;
                if(t != "x")
                {
                    int ans;
                    stringstream ss;
                    ss << t;
                    ss >> ans;
                    d[i][j] = d[j][i] = ans;
                }

            }
        }

        for(int k = 0 ; k < N;++k)
        {
            for(int i = 0 ; i < N;++i)
            {
                for(int j = 0 ; j < N;++j)
                {
                    if(d[i][j] > d[i][k] + d[k][j])
                    {
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }

        int sums = 0;
        int minD = 0;
        for(int i = 0 ; i < N;++i)
        {
            if(i != 0 )
            {
                if(d[0][i] > minD && d[0][i] < maxI )
                {
                    minD = d[0][i];
                }
            }
        }
        cout << minD <<endl;

    }
    return 0;
}

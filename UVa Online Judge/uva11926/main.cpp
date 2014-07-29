#include <iostream>
#include <algorithm>
using namespace std;
int maps[2000000];
int main()
{
    int N,M;
    while(cin >> N && cin >> M )
    {
        if(N == 0 && M == 0) break;
        int sums = 0;
        int status = 0;
        for(int i = 0 ; i <1000001;++i)
        {
            maps[i] = 0;
        }
        for(int i = 0 ; i < N;++i)
        {
            int s,t;
            cin >>s >> t;
            if(!status)
            {
                for(int j = s + 1 ; j <= t;++j)
                {
                    if(maps[j] == 1)
                    {
                        status = 1;
                        break;
                    }
                    else
                    {
                        maps[j] = 1;
                    }
                }
            }


        }
        for(int i = 0 ; i < M;++i)
        {
            int s,t,iteral;
            cin >>s >> t >> iteral;
            if(!status)
            {
                while( s <= 1000000 )
                {
                    for(int j = s + 1 ; j <= t ;++j)
                    {
                        if(maps[j] == 1)
                        {
                            status = 1;
                            break;
                        }
                        else
                        {
                            maps[j] = 1;
                        }
                    }
                    s = s + iteral;
                    t = t + iteral;
                    t = min(t,1000000);
                    if(status)
                    {
                        break;
                    }
                }
            }
        }
        if(status)
        {
            cout  << "CONFLICT" <<endl;
        }
        else
        {
            cout << "NO CONFLICT" <<endl;
        }
    }
    return 0;
}

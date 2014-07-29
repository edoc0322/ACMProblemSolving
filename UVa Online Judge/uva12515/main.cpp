#include <iostream>
#include <string>
#define MAX(x,y) ( (x > y) ? (x) : (y))
using namespace std;

string ms[1001];
string qs[501];
int M,Q;
int main()
{
    while(cin >> M && cin >> Q)
    {
        for(int i = 0 ; i < M;++i)
        {
            cin >> ms[i];
        }
        for(int q = 0 ; q < Q;++q)
        {
            string qs2;
            cin >> qs2;
            int maxD = -1;
            int index = -1;
            for(int m = 0; m < M ;++m)
            {

                for(int i = 0 ; i+qs2.length() <= ms[m].length();++i)
                {
                    int counts = 0;
                    for(int j = 0 ; j < qs2.length();++j)
                    {
                        if(qs2[j] == ms[m][i+j])
                        {
                            counts++;
                        }
                    }
                    if(counts > maxD)
                    {
                        maxD = counts;
                        index = m;
                    }
                }
            }

            cout << index+1 <<endl;
        }


    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int N;
    int c = 1;
    while(cin >> N)
    {
        if(!N) break;
        int pn = 0;
        int zn = 0;
        for(int i = 0 ; i < N;++i)
        {
            int temp;
            cin >> temp;
            if(temp > 0)
            {
                pn++;
            }
            else if(temp == 0)
            {
                zn++;
            }

        }
        cout <<"Case "<<c++<<": "<<pn-zn<<endl;
    }
    return 0;
}

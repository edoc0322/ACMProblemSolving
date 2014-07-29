#include <iostream>

using namespace std;

int main()
{
    int K;
    while(cin >> K)
    {
        if(!K) break;
        int M,N;
        cin >> M >> N;
        for(int i = 0 ; i < K;++i)
        {
            int m1,n1;
            cin >> m1 >> n1;
            int md = m1 - M;
            int nd = n1 - N;
            if( md > 0 && nd > 0)
            {
                cout << "NE\n";
            }
            else if(md > 0 && nd < 0)
            {
                cout << "SE\n";
            }
            else if( md < 0 && nd < 0)
            {
                cout << "SO\n";
            }
            else if( md < 0 && nd > 0)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "divisa\n";
            }
        }
    }
    return 0;
}

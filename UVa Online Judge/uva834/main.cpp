#include <iostream>

using namespace std;

int main()
{
    int n,m;

    while(cin >> n && cin >> m)
    {
        cout << "[" << n/m << ";";
        int di,rem;
        rem = n%m;
        n = m;
        m = rem;
        int status = 0;
        while(n != 1)
        {

            di = n/m;
            rem = n%m;
             //cout <<"n m di  "<< n << " " << m << " " << di<<endl;
            if(status)
            {
                cout << ",";
            }
            status = 1;
            cout << di;
            n = m;
            m = rem;
        }
        cout <<"]\n";
    }
    return 0;
}

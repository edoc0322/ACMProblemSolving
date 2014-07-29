#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int N;
string ss[200000];
int main()
{

    int count = 1;
    N = 0;
    int k ;
    string temp;
    int ok = 1;
    while(cin >> temp)
    {
        if(temp[0] == '9')
        {
            if(ok) cout <<"Set "<<count++ <<" is immediately decodable\n";
            else    cout << "Set "<<count++ <<" is not immediately decodable\n";
            N = 0;
            ok = 1;
            continue;
        }
        if(!ok)
        {
            continue;
        }
        for(int i  = 0 ; i < N;++i)
        {
            //cout << ss[i]<<" si" << endl;
            int len = min(ss[i].length(),temp.length());
            //cout << " temp is " << temp<<endl;
            for(k = 0 ; k < len ;++k)
            {
                if(ss[i][k] != temp[k])
                {
                    break;
                }

            }
            if(k == len)
            {
                ok = 0;
                break;
            }

        }
        if(ok)
        {
            ss[N++] = temp;
        }
    }

    return 0;
}

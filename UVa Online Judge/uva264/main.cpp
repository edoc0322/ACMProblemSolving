#include <iostream>

using namespace std;
int scope[10000000];
int main()
{
    int k = 2;
    scope[1] = 1;
    for(int i = 1 ;;i++)
    {
        scope[i+1] = scope[i] + k;
        k++;
        //cout << scope[i+1]<<endl;
        if(scope[i+1] > 10000000)
            break;
    }

    int c;
    while(cin >> c)
    {
        if(c == 1)
            cout << "TERM 1 IS 1/1"<<endl;
        else
        {
            for(int i = 1 ;;i++)
            {
                if(c>scope[i] && c<= scope[i+1])
                {
                    int index = i+1;
                    if(index % 2 == 0){
                        cout << "TERM "<< c << " IS "<< (c-scope[index-1]) <<"/"<<(scope[index]-c + 1)<<endl;
                    }
                    else{
                        cout << "TERM "<< c << " IS "<< (scope[index]-c + 1) <<"/"<< (c-scope[index-1])<<endl;
                    }
                    break;
                }

            }
        }
    }

    return 0;
}

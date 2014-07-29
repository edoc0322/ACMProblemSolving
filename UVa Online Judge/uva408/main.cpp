#include <iostream>

#include <iomanip>
using namespace std;
int re[100001];
int main()
{
    int m,n;
    while((cin >> m) && (cin >> n))
    {
        int step = 0;
        int status = 1;
        for(int i = 0 ; i <n;++i){
            re[i] = 0;
        }
        re[0]++;
        for(int i = 1 ; i < n ;++i)
        {
            step = (step+m) %n;
            if(re[step] >0){
                status = 0;
                break;
            }
            else{
                re[step]++;
            }
        }
        cout << fixed << setw(10) << m;
        cout << fixed << setw(10)<<n;
        cout << "    ";
        if(status)
        {
            cout <<"Good Choice\n\n";
        }
        else
        {
            cout <<"Bad Choice\n\n";
        }


    }
    return 0;
}

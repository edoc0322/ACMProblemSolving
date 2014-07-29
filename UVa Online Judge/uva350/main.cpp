#include <iostream>

using namespace std;
int re[10000];
int main()
{
    int Z,I,M,L;
    int ca = 1;;
    while( (cin >> Z)&& (cin >> I)&& (cin >> M)&& (cin >> L))
    {
        if(!Z && !I && !M && !L) break;
        for(int i = 0 ; i < 10000;++i){
            re[i] = 0;
        }
        re[L]++;
        int status = 1;
        int firstL = L;
        int count = 0;
        do
        {
            L = (Z*L+I)%M;
            count++;
            if(re[L] > 0)
            {
                if(L != firstL){
                    status = 0;
                }
                break;
            }
            else{
                re[L]++;
            }

        }while(L != firstL);
        if(status)
            cout << "Case "<<ca<<": " << count<<endl;
        else
            cout << "Case "<<ca<<": " << count-1<<endl;
        ca++;


    }
    return 0;
}

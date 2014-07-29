#include <iostream>
#include <algorithm>
using namespace std;

struct num
{
    int oriN;
    int rem;
    int OE;
};

bool cmp(num n1 , num n2)
{
    if(n1.rem != n2.rem)
    {
        return n1.rem < n2.rem;
    }
    else if(n1.rem == n2.rem && n1.OE != n2.OE )
    {
        return n1.OE < n2.OE;
    }
    else if(n1.rem == n2.rem && n1.OE == 1 && n2.OE == 1)
    {
        return n1.oriN > n2.oriN;
    }
    else if(n1.rem == n2.rem && n1.OE == 2 && n2.OE == 2)
    {
        return n1.oriN < n2.oriN;
    }
}

int main()
{
    int N , M;
    while (cin >> N && cin >> M && N && M)
    {
        int temp;
        num ns[N];
        for(int i = 0 ; i < N;++i)
        {
            cin >> temp;
            ns[i].oriN = temp;
            ns[i].rem = temp % M;
            ns[i].OE = ( (temp%2 == 0) ? (2) : (1));
        }
        sort(ns,ns+N,cmp);
        cout << N << " " << M <<endl;
        for(int i = 0 ; i < N;++i)
        {
            //cout << ns[i].oriN << " " << ns[i].rem << " " << ns[i].OE <<endl;
            cout << ns[i].oriN<<endl;
        }
    }
    cout << "0 0\n";
    return 0;
}

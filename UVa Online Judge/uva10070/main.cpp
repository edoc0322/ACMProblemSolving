#include <iostream>
#include <string>
using namespace std;

int main()
{
    string Y;
    int counts = 0;
    while(cin >> Y)
    {
        if(counts > 0)
        {
            cout <<endl;
        }
        counts++;
        int leap = 0;
        int mod4, mod100 , mod55,mod15 , mod400;
        mod4 = mod100 = mod55 = mod15 = mod400 = 0;
        for(int i = 0 ; i < Y.length();++i)
        {
            mod4 = (mod4 * 10 + (Y[i]-'0')) % 4;
            mod100 = (mod100 * 10 + (Y[i]-'0')) % 100;
            mod15 = (mod15 * 10 + (Y[i]-'0')) % 15;
            mod55 = (mod55 * 10 + (Y[i]-'0')) % 55;
            mod400 = (mod400 * 10 + (Y[i]-'0')) % 400;
        }

        if( mod4 == 0 && mod100 != 0 || mod400 == 0)
        {
            leap = 1;
        }
        int hulu = 0;
        if(mod15 == 0)
        {
            hulu = 1;
        }

        int bulu = 0;
        if( leap == 1 && mod55 == 0)
        {
            bulu = 1;
        }
        if(leap || hulu || bulu)
        {
            if(leap)
            {
                cout << "This is leap year.\n";
            }
            if(hulu)
            {
                cout << "This is huluculu festival year.\n";
            }
            if(bulu)
            {
                cout << "This is bulukulu festival year.\n";
            }
        }
        else
        {
            cout << "This is an ordinary year.\n";
        }

    }
    return 0;
}

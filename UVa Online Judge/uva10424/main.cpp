#include <iostream>
#include <cctype>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
    char name1[100],name2[100];
    int a1,a2,t1,t2;
    while(gets(name1) )
    {
        gets(name2);
        a1 = 0;
        a2 = 0;
        t1 = 0;
        t2 = 0;
        for(int i = 0 ; i < strlen(name1);i++){
            if(name1[i] >= 'a' && name1[i] <='z'){
                a1 += (int)(name1[i]-'a') + 1;
            }
            else if(name1[i] >= 'A' && name1[i] <='Z')
            {
                a1 += (int)(name1[i]-'A') + 1;
            }
        }

        for(int i = 0 ; i < strlen(name2);i++){
            if(name2[i] >= 'a' && name2[i] <='z'){
                a2 += (int)(name2[i]-'a') + 1;
            }
            else if(name2[i] >= 'A' && name2[i] <='Z')
            {
                a2 += (int)(name2[i]-'A') + 1;
            }
        }
        //cout << a1 << " " << a2 << endl;
        while(a1 != 0){
            t1 += a1 %10;
            a1 /= 10;
            if(a1 == 0 && t1 >= 10){
                a1 = t1;
                t1 = 0;
            }
        }
        while(a2 != 0){
            t2 += a2 %10;
            a2 /= 10;
            if(a2 == 0 && t2 >= 10){
                a2 = t2;
                t2 = 0;
            }
        }
        //cout << t1 << "  " << t2 << endl;
        double x;
        /*
        if(t1 == 0 && t2 == 0)
        {
              x = 0.00;
        }
        else if(t1 == 0 && t2 != 0)
        {
            x = 100.00;
        }
        else
        {
            x = (double) t2*100 / t1;
        }
        */
        if(t1>t2)
            x=(float)t2*100/(float)t1;
        else
            x=(float)t1*100/(float)t2;

        cout << fixed << setprecision(2) << ((x > 100.0) ? 100.00: x) << " %"<<endl;
    }
    return 0;
}

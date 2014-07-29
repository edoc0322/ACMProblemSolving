#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
int num[1005];

int main()
{
    int test;
    cin >> test;
    for(int t= 0 ; t < test;++t)
    {

        if(t > 0) cout <<endl;
        int n;
        cin >> n;
        string s= "";
        for(int i = 0 ; i < n;++i)
        {
            cin >> num[i];
        }

        sort(num,num+n);
        int c;
        int totalT = 0;
        for(c = n-1;c >= 3;c-=2)
        {
            int t1 = num[0] + num[1]*2 + num[c];
            int t2 = num[0]*2 + num[c-1] + num[c];
            if(t1 < t2)
            {
                totalT += t1;
                /*
                cout << 1 << " " << 2<<endl;
                cout << 1 <<endl;
                cout << c << " " << c+1 <<endl;

                cout << 2 <<endl;
                */
                stringstream ss1,ss2,ss3,ss4;
                ss1 << num[0];
                ss2 << num[1];
                ss3 << num[c-1];
                ss4 << num[c];
                string s1,s2,s3,s4;
                ss1 >> s1;
                ss2 >> s2;
                ss3 >> s3;
                ss4 >> s4;
                s +=  s1+ " " + s2 +"\n";
                s +=  s1 + "\n";
                s +=  s3 + " " + s4 +"\n";
                s +=  s2 + "\n";
            }
            else
            {
                totalT += t2;
                /*
                cout << 1 << " " << c+1<<endl;
                cout << 1 <<endl;
                cout << 1 << " " << c <<endl;
                cout << 1 <<endl;
                */
                stringstream ss1,ss2,ss3,ss4;
                ss1 << num[0];
                ss2 << num[1];
                ss3 << num[c-1];
                ss4 << num[c];
                string s1,s2,s3,s4;
                ss1 >> s1;
                ss2 >> s2;
                ss3 >> s3;
                ss4 >> s4;
                s +=  s1+ " " + s4 +"\n";
                s +=  s1 + "\n";
                s +=  s1 + " " + s3 +"\n";
                s +=  s1 + "\n";
            }
        }
        if(c == 2)
        {
            totalT += num[0] + num[1] + num[2];
            /*
            cout << 1 << " " << 3 <<endl;
            cout << 1 << endl;
            cout << 1 << " " << 2 <<endl;
            */

            stringstream ss1,ss2,ss3;
            ss1 << num[0];
            ss2 << num[1];
            ss3 << num[2];
            string s1,s2,s3;
            ss1 >> s1;
            ss2 >> s2;
            ss3 >> s3;
            s += s1 + " " + s3 + "\n";
            s += s1 + "\n";
            s += s1 + " " + s2 + "\n";
        }
        else if(c == 1)
        {
            totalT += num[1];
            //cout << 1 << " " << 2 <<endl;
            stringstream ss1,ss2;
            string s1,s2;
            ss1 << num[0];
            ss2 << num[1];
            ss1 >> s1;
            ss2 >> s2;
            s += s1 + " " + s2 + "\n";

        }
        else
        {
            totalT += num[0] ;
            //cout << 1 <<endl;
             stringstream ss1;
            string s1;
            ss1 << num[0];
            ss1 >> s1;
            s += s1 +"\n";
        }
        cout << totalT <<endl;
        cout << s;
    }
    return 0;
}

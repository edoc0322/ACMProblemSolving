#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{

    string s1,s2;
    int n;
    cin >> n;
    int n1,n2,n3,n4,d1;
    int status;
    string t1,t2;
    string c1,c2;
    string m1,m2;
    getchar();
    while(n>0){
        t1 = "";
        t2 = "";
        status = 0;
        getline(cin,s1);
        getline(cin,s2);
        for(int i = 0 ; i < s1.length();++i)
        {
            if(s1[i] == '<' && status == 0)
            {
                n1 = i;
            }
            else if(s1[i] == '<' && status){
                n3 = i;
            }
            if(s1[i] == '>' && status == 0)
            {
                n2 = i;
                status = 1;
            }
            else if(s1[i] == '>' && status){
                n4 = i;
            }
        }
        for(int i = 0 ; i < s2.length();++i){
            if(s2[i]=='.'){
                d1 = i;
                break;
            }
        }

        t1 = s1.substr(0,n1);
        t2 = s2.substr(0,d1);

        c1 = s1.substr(n1+1,n2-n1-1);
        c2 = s1.substr(n3+1,n4-n3-1);
        //cout << c1 << endl;
        //cout << c2 <<endl;
        m1 = s1.substr(n2+1,n3-n2-1);
        m2 = s1.substr(n4+1,s1.length()-n4-1);
        //cout << t1 <<"!"<< endl << t2<<"!"<<endl;
        cout << (t1+c1+m1+c2+m2)<<endl;
        cout << (t2+c2+m1+c1+m2)<<endl;

        n--;
    }
    return 0;
}

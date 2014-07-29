#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s[10000];
    int count = 0;
    int max = 0;
    while(getline(std::cin,s[count])){
        //if(s[count-1]=="0"){count--;break;}
        if(s[count].length() > max){
            max = s[count].length();
        }
        count++;
    }

    for(int i = 0 ; i < max;++i){
        for(int j = count-1;j>=0;--j){
            /*
            char c = (i<s[j].length())? s[j][i] :  ' ';
            cout << c;
            */

            if(i < s[j].length()){
                cout << s[j][i];
            }
            else{
                cout << ' ';
            }


        }
        cout << '\n';
        //cout << endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    string s1;
    int i , j ,  k , count,start_p,end_p;
    string temp;
    while(getline(std::cin,s1)){
        count = 0;
        start_p = 0;
        end_p = 0;
        for(i = 0 ; i < s1.length();i++){
            if(s1[i] == ' '){
                end_p=i;
                temp = s1.substr(start_p,end_p-start_p);
                reverse(temp.begin(),temp.end());
                cout << temp;
                cout << " ";
                start_p = i+1;
            }
            if(i == s1.length() - 1){
                end_p=i;
                temp = s1.substr(start_p,end_p-start_p+1);
                reverse(temp.begin(),temp.end());
                cout << temp;
            }
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s;
    int str[150];
    while(getline(std::cin,s)){
        for(int i = 0 ; i < 150;i++){
            str[i] = 0;
        }
        for(int i = 0 ; i < s.length();i++){
            if(isalpha(s[i])){
                str[(int)s[i]]++;
            }
        }
        int max = 0;
        for(int i = 'A' ; i <= 'Z';i++){
            if(max < str[i]){
                max = str[i];
            }
        }

        for(int i = 'a' ; i <= 'z';i++){
            if(max < str[i]){
                max = str[i];
            }
        }
        for(int i = 'A' ; i <= 'Z';i++){
            if(max == str[i]){
                cout << (char)i;
            }
        }

        for(int i = 'a' ; i <= 'z';i++){
            if(max == str[i]){
                cout << (char)i;
            }
        }
        cout << " "<<max << endl;
    }
    return 0;
}

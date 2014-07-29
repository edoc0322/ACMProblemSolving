#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;

bool isalphareturn(char c){
    char t = tolower(c);
    return t == 'a' || t== 'e' || t == 'i' || t =='o' || t== 'u';
}
void strprint(string& ss){
    if(ss.size() <=0) return;
    if(!isalphareturn(ss[0]))
    {
        ss += ss[0];
        ss.erase(0,1);
    }
    printf("%say",ss.c_str());
    //cout << ss << "ay";
    ss = "";
}
int main()
{
    string s,line;
    while(getline(std::cin,s))
    {
        line = "";
        for(int i = 0 ; i < s.length();i++){
            if(isalpha(s[i])){
                line += s[i];
            }
            else{
                strprint(line);
                printf("%c",s[i]);
                //cout << s[i];
            }
        }
        strprint(line);
        printf("\n");
        //cout << endl;

    }
    return 0;
}

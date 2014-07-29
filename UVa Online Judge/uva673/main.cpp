#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string s;
    int n;
    cin >> n;
    char stack[130];
    int point;
    char temp;
    temp = getchar();
    while(n > 0){
        int status = 1;
        temp = getchar();
        //cin.get();
        if(temp =='\n'){
            status = 1;
            s = "\n";
        }

        else{
            s= "";
            s = s+ temp;
            int count = 0;
            while(temp = getchar()){
                if(temp == '\n'){
                    break;
                }
                s = s + temp;
            }
            //cout << s;
        }

        //s = temp;

        point = 0;
        int i;

        for(i = 0 ; i < s.length();i++){
            if(s[i] != '[' && s[i] != '(' && s[i] != ')' && s[i] != ']' ){
                continue;
            }
            if(s[i] == '[' || s[i] == '('){
                stack[point] = s[i];
                point++;
            }
            else if(s[i] == ']'){
                if(point == 0){
                    status = 0;
                    break;
                }
                char temp = stack[--point];
                if(temp != '[')
                {
                    status = 0;
                    break;
                }
            }
            else if(s[i] == ')'){
                if(point == 0){
                    status = 0;
                    break;
                }
                char temp = stack[--point];
                if(temp != '(')
                {
                    status = 0;
                    break;
                }
            }

        }
        if(point >0){
            status = 0;
        }
        if(status){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
        n--;
    }
    return 0;
}

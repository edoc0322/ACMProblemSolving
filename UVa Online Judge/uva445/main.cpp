#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

int main()
{
    char a;
    stack<int> stack1;
    while((a = getchar())!= EOF){
        if(a >= '1' && a <= '9'){
            stack1.push((int)(a-'1')+1);
        }
        else
        {
            if(a == '!' || a == '\n'){
                cout << endl;
                continue;
            }
            while(!stack1.empty()){
                int i = stack1.top();
                stack1.pop();
                for(int j = 0 ; j < i ; j++){
                    if(a == 'b')
                        cout << ' ';
                    else if(a == '!' || a== '\n')
                        cout << endl;
                    else
                        cout << a;
                }
            }
        }
    }
    return 0;
}

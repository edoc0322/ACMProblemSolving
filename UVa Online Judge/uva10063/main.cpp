#include <iostream>
#include <string>
using namespace std;

string s;

void backtrack(string curS,int depth)
{
    if(depth == s.length())
    {
        cout << curS <<endl;
        return;
    }
    for(int i = 0 ;i <= depth;++i)
    {
        string temp = "";
        temp += s[depth];
        if(i == depth)
        {
            curS += temp;
        }
        else
            curS.insert(i,temp);
        //cout << "insert " << curS <<endl;
        backtrack(curS,depth+1);
        curS.erase(i,1);
        //cout << "cut " << curS <<endl;
    }
}
int main()
{
    int t = 0;
    while(cin >> s)
    {
        if(t > 0) cout <<endl;
        backtrack("",0);
        t++;
    }
    return 0;
}

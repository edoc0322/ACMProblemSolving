#include <iostream>
#include <string>
using namespace std;
int ansN;
string str;
int index;
string ansS;
void backtrack(string curS,int depth)
{
    if(depth == str.length())
    {
        ansN++;
        if(ansN == index)
        {
            ansS = curS;
            return;
        }
        return;
    }
    for(int i = 0 ; i <= depth;++i)
    {

        string s1 = "";
        s1 += str[depth];
        curS.insert(i,s1);
        backtrack(curS,depth+1);
        curS.erase(i,1);
        if(ansS.length() != 0)
        {
            return;
        }
    }
}

int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        cin >> str;
        cin >> index;
        ansS ="";
        ansN = 0;
        backtrack("",0);

        cout << ansS <<endl;
    }
    return 0;
}

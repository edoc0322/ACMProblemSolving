#include <iostream>
#include <algorithm>
using namespace std;
int num[5];
int ans;
int sums;

void backtrack(int index,int s)
{
    if(index == 5)
    {
        //cout << s <<endl;
        if(s == 23)
        {
            ans = 1;
        }
        else{
            return;
        }
    }
    else
    {
        backtrack(index+1,s+ num[index]);
        backtrack(index+1,s-num[index]);
        backtrack(index+1,s*num[index]);

    }
    return ;
}

int main()
{
    while( (cin >> num[0])  && (cin >> num[1])&& (cin >> num[2]) && (cin >> num[3]) && (cin >> num[4]))
    {
        if(!num[0] && !num[1] &&!num[2] && !num[3] && !num[4])break;
        ans = 0;
        sort(num,num+5);
        do
            backtrack(1,num[0]);
        while(next_permutation(num,num+5));
        if(ans)
        {
            cout <<"Possible\n";
        }
        else
        {
            cout <<"Impossible\n";
        }
    }

    return 0;
}

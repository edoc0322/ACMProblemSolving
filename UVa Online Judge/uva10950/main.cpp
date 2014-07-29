#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int N;
map<string,string> codes;
string str[150];
string target;
int totalAnsN = 0;
map<string,int> ansRepeat;
void backtrack(int depth,string sums,string tarSums)
{
    if(totalAnsN == 100)
    {
        return ;
    }
    if(depth > target.length())
    {
        return ;
    }
    if(depth ==target.length())
    {
        cout << sums <<endl;
        totalAnsN++;
        return;
    }
    int curIndex= depth;
    while(curIndex < target.length() && target[curIndex] == '0')
    {
        curIndex++;
    }
    if(curIndex == target.length()) return;

    for(int i = 0 ; i < N;++i)
    {
        if(codes[str[i]].length() + curIndex <= target.length())
        {
            int ok = 1;
            for(int j = 0 ; j < codes[str[i]].length();++j)
            {
                if(codes[str[i]][j]!= target[curIndex+j])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
            {
                //cout << curIndex << "  " << str[i] << "  " << sums << "  " << tarSums<< "  " << codes[str[i]] <<endl;
                backtrack(curIndex + codes[str[i]].length(),sums + str[i],tarSums + codes[str[i]]);
            }
        }
        if(totalAnsN == 100)
        {
            return ;
        }
    }

}
int main()
{
    int t = 1;
    while(cin >> N && N)
    {
        cout << "Case #" << t++ <<endl;
        string s1,s2;
        codes.clear();
        ansRepeat.clear();
        totalAnsN = 0;
        for(int i = 0 ; i < N;++i)
        {
            cin >> s1 >> s2;
            codes[s1] = s2;
            str[i] = s1;
        }
        sort(str,str+N);
        cin >> target;
        backtrack(0,"","");
        cout <<endl;

    }
    return 0;
}

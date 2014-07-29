#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

set<string> ignore;
struct point
{
    string ori;
    string key;
    string change;
    int index;
    int inputOrder;
};
point strarr[100010];
int counts = 0;
bool cmp(point p1, point p2)
{
    if(p1.key != p2.key)
    {
        return p1.key < p2.key;
    }
    else
    {
        if(p1.ori == p2.ori)
        {
            return p1.index < p2.index;
        }
        else
        {
            return p1.inputOrder < p2.inputOrder;
        }
    }
}
int main()
{
    string s;
    while(getline(cin,s))
    {
        if(s == "::")
        {
            break;
        }
        ignore.insert(s);
    }

    int input = 0;
    while(getline(cin,s))
    {
        string s2 = s;
        for(int i = 0 ; i < s2.length();++i)
        {
            if(s2[i] >= 'A' && s2[i] <= 'Z')
            {
                s2[i] = s2[i] - 'A' + 'a';
            }
        }
        stringstream ss(s2);
        string temp;
        int index = 0;
        int position = 0;
        while(ss >> temp)
        {
            if(ignore.find(temp) == ignore.end())
            {
                strarr[counts].inputOrder = input;
                strarr[counts].ori = s2;
                strarr[counts].key = temp;
                string s3 = temp;
                for(int i = 0 ; i < s3.length();++i)
                {
                    s3[i] = s3[i]- 'a' + 'A';
                }
                string s4 = s2;
                s4.replace(position,temp.length(),s3);
                strarr[counts].change = s4;
                strarr[counts].index = position;
                //cout << strarr[counts].change << " " << strarr[counts].ori <<endl;
                counts++;
            }
            position += temp.length()+1;
        }
        input++;
    }
    sort(strarr,strarr+counts,cmp);
    for(int i = 0 ; i < counts;++i)
    {
        cout << strarr[i].change <<endl;
    }
    return 0;
}

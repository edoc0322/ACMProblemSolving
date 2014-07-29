#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
using namespace std;
string str[100];
int visit[100];
int strN;


void backtrack(int depth,int choose,int target)
{

    if(choose == target)
    {
        int counts = 0;
        for(int i = 0 ; i < strN;++i)
        {
            if(visit[i])
            {
                if(counts == 0)
                {
                    cout << str[i];
                }
                else
                {
                    cout << ", " << str[i];
                }
                counts++;
            }
        }
        cout <<endl;
        return;
    }
    if(depth >= strN) return;
    visit[depth] = 1;
    backtrack(depth+1,choose+1,target);
    visit[depth] = 0;
    backtrack(depth+1,choose,target);
}

int main()
{
    int test;
    cin >> test;
    getchar();
    getchar();
    int start,end;
    for(int t= 0 ; t < test;++t)
    {
        if(t > 0)
        {
            cout <<endl;
        }
        strN = 0;
        string s;
        getline(cin,s);
        int status = 0;
        if(s == "*")
        {
            start = 1;
            status = 1;
        }
        else
        {
            int counts = 0;
            int num;
            stringstream ss;
            ss << s;
            while(ss >> num)
            {
                if(counts == 0)
                {
                    start = num;
                }
                else
                {
                    end = num;
                }
                counts++;
            }
            if(counts == 1)
            {
                end = start;
            }
        }
        while(getline(cin,s))
        {
            //cout << "= =?";
            if(s.length() == 0) break;
            str[strN] = s;
            strN++;
            //cout << "its me " << s <<endl;
        }
        if(status)
        {
            end = strN;
        }

        for(int i = 0 ; i < 100;++i)
        {
            visit[i] = 0;
        }
        for(int i = start;i <= end;++i)
        {
            cout << "Size " <<i <<endl;
            backtrack(0,0,i);
            cout << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int N,M,K;
string str[100];
int visit[100];
set<string> sets[1000];
map<string,int> maps;

bool cmp(string s1,string s2)
{
    if(s1.length()!= s2.length())
    {
        return s1.length() > s2.length();
    }
    else
    {
        return s1 < s2;
    }
}

void backtrack(int depth,int choose)
{
    if(choose == K)
    {
        int counts = 0;
        for(int i = 0 ; i < N;++i)
        {
            if(visit[i] && counts == 0)
            {
                cout << str[i];
                counts++;
            }
            else if(visit[i] && counts)
            {
                cout << " " << str[i];
            }
        }
        cout <<endl;
        return;
    }
    if(depth >= N)
    {
        return;
    }
    int ok = 1;

    if(maps[str[depth]] != 0)
    {
        for(int i = 0 ; i < depth;++i)
        {
            for(int j = 1 ; j <= M;++j)
            {
                if(visit[i]&& sets[j].find(str[i]) != sets[j].end() && sets[j].find(str[depth]) != sets[j].end())
                {
                    ok = 0;
                    break;
                }
            }

        }
    }
    if(ok)
    {
        //cout << "it's me " << str[depth] <<endl;
        visit[depth] = 1;
        backtrack(depth+1,choose+1);
    }
    visit[depth] = 0;
    backtrack(depth+1,choose);



}
int main()
{
    int test;
    cin >> test;
    for(int t= 1 ; t <= test;++t)
    {
        cout << "Set " << t << ":" <<endl;
        maps.clear();
        for(int i = 0 ; i < 1000;++i)
        {
            sets[i].clear();
        }
        cin >> N >> M >> K;
        for(int i = 0 ; i < N;++i)
        {
            cin >> str[i];
            visit[i] = 0;
            for(int j = 0 ; j < str[i].length();++j)
            {
                if(str[i][j] >='a' && str[i][j] <= 'z')
                {
                    str[i][j] = str[i][j] - 'a' + 'A';
                }
            }
        }
        string s1,s2;
        for(int i = 1 ; i <= M;++i)
        {
            cin >> s1 >> s2;
            for(int j = 0 ; j < s1.length();++j)
            {
                if(s1[j] >='a' && s1[j] <= 'z')
                {
                    s1[j] = s1[j] - 'a' + 'A';
                }
            }
            for(int j = 0 ; j < s2.length();++j)
            {
                if(s2[j] >='a' && s2[j] <= 'z')
                {
                    s2[j] = s2[j] - 'a' + 'A';
                }
            }
            maps[s1] = maps[s2] = i;
            sets[i].insert(s1);
            sets[i].insert(s2);
        }
        sort(str,str+N,cmp);
        backtrack(0,0);
        cout <<endl;
    }
    return 0;
}

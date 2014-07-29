#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#define CtoN(x) (x-'A')
#define NtoC(x) ((char)( x + 'A'))

using namespace std;

vector<int> node[30];
int visit[30];


void dfs(int monster,int hero,int step,int k)
{
    step = (step + 1) % k;
    if(step == 0)
    {
        visit[monster] = true;
    }
    for(int i = 0 ;i < node[monster].size();++i)
    {
        //cout << node[NtoC(monster)][i] <<endl;
        if(!visit[node[monster][i]] && node[monster][i] !=hero)
        {
            if(visit[monster]) cout << NtoC(monster) << " ";
            dfs(node[monster][i],monster,step,k);
            return;
        }
    }
    cout << "/" << NtoC(monster) <<endl;
}
int main()
{
    string str;
    while(cin >> str)
    {
        if(str == "#")break;
        char s,t;
        int k;
        cin >> s >> t >> k;
        for(int i = 0 ; i < 30;++i)
        {
            node[i].clear();
        }
        memset(visit,false,sizeof(visit));
        string sep = ";.";
        int start = str.find_first_not_of(sep);
        int end;
        while(start != string::npos)
        {
            end = str.find_first_of(sep,start+1);
            if(end == string::npos)
            {
                end = str.length();
            }
            string subS = str.substr(start,end-start);
            for(int i = 2;i < subS.length();++i)
            {
                node[CtoN(subS[0])].push_back(CtoN(subS[i]));
            }
            start = str.find_first_not_of(sep,end+1);
        }
        dfs(CtoN(s),CtoN(t),0,k);

    }
    return 0;
}

#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
long long int maps[1000][1000];
int visit[1000];
int nodeNum = 0;
map<string,int> nameToNum;
long long int gcd(long long a,long long b)
{
    return b ? gcd(b, a%b) : a;
}

struct rate
{
    long long int n1,n2;
    int p1,p2;
}rates[10000];
int edgeNum = 0;
int st,ed;
vector<int> dfs(int n,vector<int> curAns)
{
    visit[n] = 1;
    if(n == ed)
    {
        return curAns;
    }
    for(int i = 0 ; i < nodeNum;++i)
    {
        if(maps[n][i] && !visit[i])
        {
            curAns.push_back(i);
            return dfs(i, curAns);
        }
    }
    return curAns;
}
int main()
{
    memset(maps,0,sizeof(maps));
    string s;
    while(cin >> s)
    {
        if(s == ".")break;
        if(s == "!")
        {
            long long int n1,n2;
            string s1,s2;
            cin >> n1 >> s1;
            cin >> s2 >> n2 >> s2;
            if(nameToNum.find(s1) == nameToNum.end())
            {
                nameToNum[s1] = nodeNum++;
            }
            if(nameToNum.find(s2) == nameToNum.end())
            {
                nameToNum[s2] = nodeNum++;
            }
            maps[nameToNum[s1]][nameToNum[s2]] = maps[nameToNum[s2]][nameToNum[s1]] = 1;
            rates[edgeNum].p1 = nameToNum[s1];
            rates[edgeNum].p2 = nameToNum[s2];
            rates[edgeNum].n1 = n1;
            rates[edgeNum].n2 = n2;
            edgeNum++;
        }
        else if(s == "?")
        {
            string s1,s2;
            cin >> s1 >> s2 >> s2;
            if(nameToNum.find(s1) == nameToNum.end())
            {
                nameToNum[s1] = nodeNum++;
            }
            if(nameToNum.find(s2) == nameToNum.end())
            {
                nameToNum[s2] = nodeNum++;
            }
            memset(visit,0,sizeof(visit));

            st = nameToNum[s1];
            ed = nameToNum[s2];
            vector<int> zero;
            vector<int> curAns = dfs(st,zero);
            //cout << curAns[0] << " " << curAns[1] <<endl;
            //int c;
            //cin >> c;
            if(visit[ed] == 0)
            {
                cout << "? " << s1 << " = " << "?" << " " << s2 <<endl;
            }
            else
            {

                long long pro1,pro2;
                for(int i = 0 ; i < edgeNum;++i)
                {
                    if(rates[i].p1 == st && rates[i].p2 == curAns[0] )
                    {
                        pro1 = rates[i].n1;
                        pro2 = rates[i].n2;
                        break;
                    }
                    else if(rates[i].p2 == st && rates[i].p1 == curAns[0])
                    {
                        pro1 = rates[i].n2;
                        pro2 = rates[i].n1;
                        break;
                    }
                }
                //cout << "pro1 pro2 " << pro1 << " " << pro2 <<endl;
                for(int i = 0 ; i+1 < curAns.size();++i)
                {
                    for(int j = 0 ; j < edgeNum;++j)
                    {
                       //cout << curAns[i] << "  " << curAns[i+1] <<endl;
                        if(rates[j].p1 == curAns[i] && rates[j].p2 == curAns[i+1] )
                        {
                            pro1 *= rates[j].n1;
                            pro2 = rates[j].n2 * pro2;
                            //cout << "1 = " <<pro1 << "  " << pro2 <<endl;
                            long long gcdn = gcd(pro1,pro2);
                            pro1 /= gcdn;
                            pro2 /= gcdn;
                            break;
                        }
                        else if(rates[j].p1 == curAns[i+1] && rates[j].p2 == curAns[i])
                        {
                            pro1 *= rates[j].n2;
                            pro2 = rates[j].n1 * pro2;
                            //cout << "2 = " << pro1 << " " << pro2 <<endl;
                            long long gcdn = gcd(pro1,pro2);
                            pro1 /= gcdn;
                            pro2 /= gcdn;
                            break;
                        }
                    }
                }
                long long gcdn = gcd(pro1,pro2);
                //cout << gcdn << " gcdn " <<endl;
                cout << pro1/gcdn << " " << s1 << " = " << pro2/gcdn << " " << s2 <<endl;
            }
            zero.clear();
            curAns.clear();
        }
    }
    return 0;
}

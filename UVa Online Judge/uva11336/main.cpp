#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stdio.h>

using namespace std;


struct edge
{
    int p1,p2;
};
map<string,int> nameToNum;

int maps[1000][1000];
int d[1000];
int parent[1000];
int v[1000];
vector<edge> edges;

int dij(int source,int finals,int counts,int oldCounts)
{
    for(int i = 0 ; i < counts;++i)
    {
        v[i] = 0;
        d[i] = 999999;
    }

    parent[source] = source;
    d[source] = 0;
    for(int i = 0 ; i < counts;++i)
    {
        int index = -1,minD = 99999;
        for(int j = 0 ; j < counts;++j)
        {
            if(v[j] == 0 && d[j] < minD)
            {
                index = j;
                minD = d[j];
            }
        }
        if(index == -1) break;
        v[index] = 1;
        for(int j = 0 ; j < counts;++j)
        {
            if(!v[j] && d[index] + (maps[index][j]) < d[j])
            {
                d[j] = d[index] + (maps[index][j]);
                parent[j] = index;
            }
        }
    }
    //cout << source << " " << finals << " " << d[finals] <<endl;
    if(d[finals] == 1 ) return 1;
    int status = 1;
    int temp = finals;
    while(parent[temp] != source)
    {
        //cout << temp <<endl;
        temp = parent[temp];
        if(temp < oldCounts && temp != source)
        {
            status = 0;
            //cout << "FUCK\n";
            break;
        }
    }
    return status;
}

int main()
{
    string name1,name2;
    while(cin >> name1)
    {
        if(name1 == "END") break;
        nameToNum.clear();
        edges.clear();
        string n1,n2;
        string s;
        int counts = 0;
        for(int i = 0 ; i < 1000;++i)
        {

            for(int j = 0 ; j < 1000;++j)
            {
                maps[i][j] = 999999;

            }
        }
        getchar();
        while(getline(cin,s))
        {
            if(s == "* * *")
            {
                break;
            }
            n1 = s.substr(0,s.find_first_of(" "));
            n2 = s.substr(s.find_first_of(" ")+1);
            if(nameToNum.find(n1) == nameToNum.end())
            {
                nameToNum[n1] = counts++;
            }
            if(nameToNum.find(n2) == nameToNum.end())
            {
                nameToNum[n2] = counts++;
            }
            if( nameToNum[n1] !=  nameToNum[n2])
            {
                edge e;
                e.p1 = nameToNum[n1];
                e.p2 = nameToNum[n2];
                edges.push_back(e);
            }

        }
        int oldCounts = counts;
        cin >> name2;
        getchar();
        while(getline(cin,s))
        {
            if(s == "* * *")
            {
                break;
            }
            n1 = s.substr(0,s.find_first_of(" "));
            n2 = s.substr(s.find_first_of(" ")+1);
            if(nameToNum.find(n1) == nameToNum.end())
            {
                nameToNum[n1] = counts++;
            }
            if(nameToNum.find(n2) == nameToNum.end())
            {
                nameToNum[n2] = counts++;
            }
            maps[nameToNum[n1]][nameToNum[n2] ] = 1;
            maps[nameToNum[n2]][nameToNum[n1] ] = 1;

        }
        for(int i = 0 ; i < counts;++i)
        {
            maps[i][i] = 0;
        }
        int status = 1;
        for(int i = 0 ; i < edges.size();++i)
        {
            int a1 = edges[i].p1;
            int a2 = edges[i].p2;
            if(dij(a1,a2,counts,oldCounts) == 0)
            {
                status = 0;
                break;
            }
        }
        if(status)
        {
            cout << "YES: " << name2 << " is a more detailed version of " << name1 << endl;
        }
        else
        {
            cout << "NO: " << name2 << " is not a more detailed version of " << name1 << endl;
        }

    }
    return 0;
}

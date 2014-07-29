#include <iostream>
#include <map>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
    int index;
    map<int, int> edge;
    int edgeNum;
};
int N;
int v[102];
int vcounts;
bool cmp(node n1 , node n2)
{
    return n1.edgeNum > n2.edgeNum;
}

int main()
{
    while(cin >> N && N)
    {

        node nodes[N+1];
        node copyNode[N+1];
        for(int i = 0 ; i <= N;++i)
        {
            v[i] = 1;
            nodes[i].edgeNum = 0;
        }
        vcounts = N;
        getchar();
        string s;
        int over = 0;
        int num;
        while(getline(cin,s) )
        {
            stringstream ss(s);
            ss >> num;
            if(num == 0)
            {
                over = 1;
                break;
            }

            int num2;
            nodes[num].index = num;
            while(ss >> num2)
            {

                nodes[num].edge[num2] = 1;
                nodes[num].edgeNum++;
                nodes[num2].edge[num] = 1;
                nodes[num2].edgeNum++;
                nodes[num2].index = num2;
            }
        }
        for(int i = 0 ;i <= N;++i)
        {
            copyNode[i] = nodes[i];
        }
        sort(copyNode,copyNode+N+1,cmp);
        std::map<int,int>::iterator it;
        int ans = 1;
        for(int i = 0 ; i <= N;++i)
        {
            int ind = copyNode[i].index;
            v[ind] = 0;
            nodes[ind].edgeNum = 0;
            vcounts--;
            if(vcounts == 0)
            {
                break;
            }
            for(it = nodes[ind].edge.begin(); it != nodes[ind].edge.end();++it)
            {
                //cout << "hello";
                int fp = it->first;
                it->second = 0;
                nodes[fp].edge[ind] = 0;
                nodes[fp].edgeNum--;
                if(nodes[fp].edgeNum == 0)
                {
                    v[fp] = 0;
                    vcounts--;
                    if(vcounts == 0)
                    {
                        break;
                    }
                }

            }
            if(vcounts == 0)
            {
                break;
            }

            ans++;

        }
        cout << ans <<endl;


    }


    return 0;
}

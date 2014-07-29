#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int maps[102][102];
int groupNum[2];
int setS[102];
int N,M;
int main()
{
    int test;
    cin >> test;
    for(int t = 1 ; t <= test;++t)
    {
        cin >> N >> M;
        int a,b;
        int totalPair = 0;
        memset(maps,0,sizeof(maps));
        memset(groupNum,0,sizeof(groupNum));
        vector<int> setS[2];
        for(int i = 0 ; i < M;++i)
        {
            cin >> a >> b;
            maps[a][b] = maps[b][a] = 1;
        }
        for(int i = 1 ; i <= N;++i)
        {
            int edge[2] ={0,0};
            for(int j = 0 ; j < 2;++j)
            {
                for(int k = 0 ; k < setS[j].size();++k)
                {
                    if(maps[i][setS[j][k]] == 1)
                    {
                        edge[j]++;
                    }
                }
            }
            //cout << edge1 << " " << edge2 <<endl;
            if(edge[0] < edge[1])
            {
                setS[0].push_back(i);
                totalPair += edge[0];
            }
            else
            {
                //cout << "i put in setS1 " << i <<endl;
                setS[1].push_back(i);
                totalPair += edge[1];
            }
        }
        if(totalPair <= M/2)
        {
            cout << "Case #" << t << ": " << setS[0].size() <<endl;
            int status = 0;
            for(int i = 0 ; i < setS[0].size();++i)
            {
                if(i == 0) cout << setS[0][i];
                else cout << " "<< setS[0][i];
            }
            cout <<endl;
        }
        else
        {
            cout << "Case #" << t << ": Impossible." <<endl <<endl;
        }
    }

    return 0;
}

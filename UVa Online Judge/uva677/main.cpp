#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int M,N;
int maps[1100][1100];
int ansN = 0;
vector<int> ansV[50000];
int visit[1100];
int tempAns[1100];
void backtrack(int start,int depth)
{
    if(depth == N)
    {
        /*
        for(int i = 0 ; i < M;++i)
        {
            if(visit[i])
            cout << i <<endl;
        }
        */
        for(int i = 0 ; i < N+1;++i)
        {
            ansV[ansN].push_back(tempAns[i]+1);
        }
        ansN++;

        return;
    }
    for(int i = 0 ; i < M;++i)
    {
        if(i!= start && maps[start][i] && visit[i]==0)
        {
            //cout << start << "    " <<i <<endl;
            visit[i] = 1;
            tempAns[depth+1] = i;
            backtrack(i,depth+1);
            visit[i] = 0;
        }
    }
}
int main()
{
    int test = 0;
    while(cin >> M && cin >> N)
    {
        if(test > 0)
        {
            cout <<endl;
        }
        for(int i = 0 ; i < M;++i)
        {
            visit[i] = 0;
            for(int j = 0 ; j < M;++j)
            {
                cin >> maps[i][j];
            }
        }
        for(int i = 0 ; i < 50000;++i)
        {
            ansV[i].clear();
        }
        ansN = 0;
        visit[0] = 1;
        tempAns[0] = 0;
        backtrack(0,0);
        if(ansN == 0)
        {
            cout << "no walk of length " << N <<endl;
        }
        else
        {
            for(int i = 0 ; i < ansN;++i)
            {
                cout << "(";
                for(int j = 0 ; j < N+1;++j)
                {
                    if(j == 0) cout << ansV[i][j];
                    else cout << "," << ansV[i][j];
                }
                cout << ")" <<endl;
            }
        }
        int temp;
        cin >> temp;
        test++;
        if(temp == -9999) continue;

    }
    return 0;
}

#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;

int maps[35][35];
int d[35];
int v[35];
int N,M,E;
map<string , int> name;

void bfs(int s ,int e)
{
    queue<int> p;
    v[s] = 1;
    p.push(s);
    while(p.size())
    {
        int point = p.front();
        if(point == e)
        {
            break;
        }
        p.pop();
        for(int i = 0 ;i < N;++i)
        {
            if(maps[point][i] && !v[i])
            {
                v[i] = 1;
                d[i] = d[point] + 1;
                p.push(i);
            }
        }
    }
}
int main()
{
    int test;
    cin >> test;
    cout << "SHIPPING ROUTES OUTPUT\n\n";
    int c = 1;
    while(test--)
    {
        name.clear();
        cout << "DATA SET  "<<c++ <<endl;
        cout <<endl;
        cin >> N;
        cin >> E;
        cin >> M;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                maps[i][j] = 0;
            }
        }
        int c2 = 0;
        string s;
        for(int i= 0;i<N;++i)
        {
            cin >> s;
            name[s] = c2++;
        }

        string s1,s2;
        int n1,n2;
        for(int i = 0 ; i < E;++i)
        {
            cin >> s1;
            cin >> s2;
            n1 = name[s1];
            n2 = name[s2];
            maps[n1][n2] = maps[n2][n1] = 1;
        }
        int money;
        for(int i = 0 ; i < M;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                d[j] = 0;
                v[j] = 0;
            }
            cin >> money;
            cin >> s1;
            cin >> s2;
            n1 = name[s1];
            n2 = name[s2];
            bfs(n1,n2);
            if(d[n2])
            {
                cout << "$" << money*100*d[n2] <<endl;
            }
            else
            {
                cout << "NO SHIPMENT POSSIBLE\n";
            }
        }
        cout <<endl;
    }
    cout << "END OF OUTPUT\n";

    return 0;
}

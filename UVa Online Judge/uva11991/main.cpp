#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N,M;
    while(cin >> N && cin >> M)
    {
        map<int , vector<int> > maps;
        int temp;
        for(int i = 0 ; i < N;++i)
        {
            cin >> temp;
            if(maps[temp].empty() )
            {
                vector<int> v;
                v.push_back(i+1);
                maps[temp] = v;
            }
            else
            {
                maps[temp].push_back(i+1);
            }
        }
        for(int i = 0 ; i < M;++i)
        {
            int k , v;
            cin >> k >> v;
            if(maps[v].empty())
            {
                cout << "0\n";
            }
            else
            {
                if(maps[v].size() < k)
                {
                    cout << "0\n";
                }
                else
                {
                    cout << maps[v][k-1] << endl;
                }
            }
        }
    }
    return 0;
}

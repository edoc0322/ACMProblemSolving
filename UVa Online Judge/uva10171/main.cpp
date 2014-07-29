#include <iostream>
#include <algorithm>
#define CtoN(x) (x -'A')
#define maxD 1e9
#include <vector>
using namespace std;
int maps1[50][50];
int maps2[50][50];
int N;
int main()
{
    while(cin >> N && N)
    {
        char y , u , x, v;
        int w;
        for(int i = 0 ; i < 26 ; ++i)
        {
            for(int j = 0 ; j < 26; ++j)
            {
                if(i!=j)
                {
                    maps1[i][j] = maxD;
                    maps2[i][j] = maxD;
                }

                else
                {
                    maps1[i][j] = 0;
                    maps2[i][j] = 0;
                }

            }
        }
        for(int i = 0 ; i < N; ++i)
        {
            cin >> y >> u >> x >> v >> w;
            if(y == 'Y')
            {
                if(u == 'U')
                {
                    maps1[CtoN(x)][CtoN(v)] = min(maps1[CtoN(x)][CtoN(v)],w);
                }
                else
                {
                    maps1[CtoN(x)][CtoN(v)] = min(maps1[CtoN(x)][CtoN(v)],w);
                    maps1[CtoN(v)][CtoN(x)] = min(maps1[CtoN(v)][CtoN(x)],w);
                }
            }
            else
            {
                if(u == 'U')
                {
                    maps2[CtoN(x)][CtoN(v)] = min(maps2[CtoN(x)][CtoN(v)],w);
                }
                else
                {
                    maps2[CtoN(x)][CtoN(v)] = min(maps2[CtoN(x)][CtoN(v)],w);
                    maps2[CtoN(v)][CtoN(x)] = min(maps2[CtoN(v)][CtoN(x)],w);
                }
            }
        }

        for(int k = 0 ; k < 26;++k)
        {
            for(int i = 0 ; i < 26 ;++i)
            {
                for(int j = 0 ; j < 26 ;++j)
                {
                    maps1[i][j] = min(maps1[i][j],maps1[i][k] + maps1[k][j]);
                }
            }
        }

        for(int k = 0 ; k < 26;++k)
        {
            for(int i = 0 ; i < 26 ;++i)
            {
                for(int j = 0 ; j < 26 ;++j)
                {
                    maps2[i][j] = min(maps2[i][j],maps2[i][k] + maps2[k][j]);
                }
            }
        }

        char d1,d2;
        cin >> d1 >> d2;
        int dd1 = CtoN(d1);
        int dd2 = CtoN(d2);
        int minD = maxD,minIndex = -1;
        for(int i = 0 ; i < 26;++i)
        {
            if(maps1[dd1][i] + maps2[dd2][i] < minD)
            {
                minD = maps1[dd1][i] + maps2[dd2][i];
            }
        }
        vector<int> ansNode;
        if(minD == maxD)
        {
            cout << "You will never meet." << endl;
        }
        else
        {
            for(int i = 0 ; i < 26;++i)
            {
                if(maps1[dd1][i] + maps2[dd2][i] == minD)
                {
                    ansNode.push_back(i);
                }
            }
            cout << minD ;
            for(int i = 0 ; i < ansNode.size();++i)
                cout << " "<< (char) (ansNode[i]+'A');
            cout <<endl;
        }
    }
    return 0;
}

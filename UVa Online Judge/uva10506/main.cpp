#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

long long int M,N;
map<long long int,int> maps;
long long int maxI;
int nm;
int digit[65550];
int findAns = 0;
void backtrack(int depth)
{
    if(findAns) return;
    if(depth == nm)
    {
        for(int i = nm - M + 1;i <= nm-1;++i)
        {
            int honer = 0;
            for(int j = i ,k = 0; k < M;++k )
            {
                honer = honer * N + digit[(j+k)%nm];
            }
            if(maps[honer] == 1)
            {
                return;
            }
        }
        for(int i = 0 ; i < nm;++i)
        {
            cout << digit[i];
        }
        cout << endl;
        findAns = 1;
        return;
    }

    for(int i = 0 ; i < N;++i)
    {
        int honer = 0;
        digit[depth] = i;
        for(int j = M-1;j >= 0;--j)
        {
            honer = honer * N + digit[depth-j];
        }
        //cout << honer << "  "<< depth <<endl;
        if(maps[honer] == 1)
        {
            continue;
        }
        maps[honer] = 1;
        //cout << " I got here " << honer << "  "<< depth <<endl;
        backtrack(depth+1);
        maps[honer] = 0;
        if(findAns) return;
    }
}

int main()
{
    while(cin >> M &&cin >> N)
    {
        findAns = 0;
        maxI = pow((double)N,(double)M);
        maps.clear();
        nm = 1;
        for(int i = 0 ; i < M;++i)
        {
            nm *= N;
        }
        for(int i = 0 ; i < 65536 ;++i)
        {
            digit[i] = 0;
        }
        maps[0] = 1;
        backtrack(M);



    }
    return 0;
}

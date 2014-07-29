#include <iostream>
#include <string>
using namespace std;

int R,C;
string maps[102];

int check(int r,int c,int RL,int CL)
{
    for(int sr = r ; sr < r+RL;++sr)
    {
        for(int sc = c ; sc < c +CL;++sc)
        {
            if(maps[sr][sc] != '1')
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{

    while(cin >> R)
    {
        if(R == 0) break;
        cin >> C;
        int sums = 0;
        for(int i = 0 ; i < R;++i)
        {
            cin >> maps[i];
        }
        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < C;++j)
            {
                for(int lenR = 1 ; lenR<= R;++lenR)
                {
                    for(int lenC = 1 ; lenC <= C;++lenC)
                    {
                        if(i + lenR <= R && j + lenC <= C)
                        {
                            sums += check(i,j,lenR,lenC);
                        }
                    }
                }
            }
        }
        cout << sums <<endl;
    }
    return 0;
}

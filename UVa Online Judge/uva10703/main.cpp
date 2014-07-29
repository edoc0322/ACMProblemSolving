#include <iostream>
#include <algorithm>
using namespace std;

int W,H,N;
int main()
{
    while(cin >> W && cin >> H && cin >> N)
    {
        if(!W && !H && !N) break;
        int board[W+1][H+1];
        for(int i = 1 ; i <= W;++i)
        {
            for(int j = 1 ; j <= H;++j)
            {
                board[i][j] = 1;
            }
        }
        int x1,y1,x2,y2;
        for(int i = 0 ; i < N;++i)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            for(int j = min(x1,x2) ; j <= max(x1,x2);++j)
            {
                for(int k= min(y1,y2); k <= max(y1,y2);++k)
                {
                    board[j][k] = 0;
                }
            }
        }
        int sums= 0;
        for(int i = 1 ; i <= W;++i)
        {
            for(int j = 1 ; j <= H;++j)
            {
                sums+=board[i][j];
            }
        }
        if(sums == 0)
        {
            cout << "There is no empty spots.\n";
        }
        else if(sums == 1)
        {
            cout << "There is one empty spot.\n";
        }
        else
        {
            cout << "There are " << sums << " empty spots.\n";
        }


    }

    return 0;
}

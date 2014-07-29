#include <iostream>
#include <string>
using namespace std;

int R,C,Q;
string maps[101];

int dfs(int mark,int r,int c)
{
    int i;
    int status = 1;
    for(i = 1 ; i <= 100; ++i)
    {

        int x1,y1,x2,y2,x3,y3,x4,y4;
        x1 = c-i;
        y1 = r-i;
        x2 = c+i;
        y2 = r-i;
        x3 = c+i;
        y3 = r+i;
        x4 = c-i;
        y4 = r+i;
       // cout << x1 << "  " << y1 << "  " << x2 << "  " << y2 << "  " << x3 << "  " << y3 << "  " << x4 << "  " << y4 << endl;
        if(x1 < C && x1 >= 0 && x2 < C && x2 >= 0 && x3 < C && x3 >= 0  && x4 < C && x4 >= 0 && y1 < R && y1 >= 0
                && y2 < R && y2 >= 0 && y3 < R && y3>= 0 && y4 < R && y4 >= 0 &&
                mark == maps[y1][x1] && mark == maps[y2][x2] && mark == maps[y3][x3] && mark == maps[y4][x4])
        {


            for(int cx = x1 , cy = y1; cx <= x2; ++cx)
            {
                if(maps[cy][cx] != mark)
                {
                    //cout << cy << "     " << cx << endl;
                    status = 0;
                    break;
                }
            }
            if(status == 0) break;

            for(int cx = x2 , cy = y2; cy <= y3; ++cy)
            {
                if(maps[cy][cx] != mark)
                {
                    //cout << cy << "     " << cx << endl;
                    status = 0;
                    break;
                }
            }
            if(status == 0) break;

            for(int cx = x3 , cy = y3; cx >= x4; --cx)
            {
                if(maps[cy][cx] != mark)
                {
                    //cout << cy << "     " << cx << endl;
                    status = 0;
                    break;
                }
            }
            if(status == 0) break;

            for(int cx = x4 , cy = y4; cy >= y1; --cy)
            {
                if(maps[cy][cx] != mark)
                {
                    //cout << cy << "     " << cx << endl;
                    status = 0;
                    break;
                }
            }
            if(status == 0) break;
        }
        else
        {
            status = 0;
            break;
        }
        if(status == 0) break;
    }
    if(i == 1)
        return i;
    return (i-1)*2+1;
}

int main()
{
    int test;
    cin >> test;
    while(test--)
    {

        cin >> R >> C >> Q;
        for(int i = 0 ; i < R; ++i)
        {
            cin >> maps[i];
        }

        cout << R << " " << C << " " << Q <<endl;

        for(int i = 0 ; i < Q; ++i)
        {
            int r,c;
            cin >> r >> c;
            int mark = maps[r][c];

            cout << dfs(mark,r,c) <<endl;;

        }

    }
    return 0;
}

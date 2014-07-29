#include <iostream>

using namespace std;

int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};
int maps[1000][1000];
int sx,sy,sd;
int main()
{
    while(cin >> sx)
    {
        if(sx == -1)break;
        cin >> sy >> sd;
        int x,y,d;
        for(int i = 0 ; i < 8;++i)
        {
            cin >> x >> y >> d;
            maps[x][y] = d;
        }
        if(sd % 2 == 1)
        {
            int nd;
            nd = sd-2;
            if(nd < 0) nd = 8 + nd;
            if(maps[sx+dx[nd]][sy+dy[nd] ])
            {
                cout << nd << endl;
                continue;
            }

            nd = sd-1;
            if(nd < 0) nd = 8 + nd;
            if(maps[sx+dx[nd]][sy+dy[nd] ])
            {
                cout << nd << endl;
                continue;
            }

            nd = sd;
            if(maps[sx+dx[nd]][sy+dy[nd] ])
            {
                cout << nd << endl;
                continue;
            }

            nd = sd+1;
            nd = nd % 8;
            if(maps[sx+dx[nd]][sy+dy[nd] ])
            {
                cout << nd << endl;
                continue;
            }

            nd = sd+2;
            nd = nd % 8;
            if(maps[sx+dx[nd]][sy+dy[nd] ])
            {
                cout << nd << endl;
                continue;
            }

            nd = sd+3;
            nd = nd % 8;
            if(maps[sx+dx[nd]][sy+dy[nd] ])
            {
                cout << nd << endl;
                continue;
            }

            nd = sd+4;
            nd = nd % 8;
            if(maps[sx+dx[nd]][sy+dy[nd] ])
            {
                cout << nd << endl;
                continue;
            }
        }
        else
        {
            int nd;

            nd = sd-1;
            if(nd < 0) nd = 8 + nd;
            if(maps[sx+dx[nd]][sy+dy[nd] ])
            {
                cout << nd << endl;
                continue;
            }

            nd = sd;
            if(maps[sx+dx[nd]][sy+dy[nd] ])
            {
                cout << nd << endl;
                continue;
            }

            nd = sd+1;
            nd = nd % 8;
            if(maps[sx+dx[nd]][sy+dy[nd] ])
            {
                cout << nd << endl;
                continue;
            }

            nd = sd+2;
            nd = nd % 8;
            if(maps[sx+dx[nd]][sy+dy[nd] ])
            {
                cout << nd << endl;
                continue;
            }

            nd = sd+3;
            nd = nd % 8;
            if(maps[sx+dx[nd]][sy+dy[nd] ])
            {
                cout << nd << endl;
                continue;
            }

            nd = sd+4;
            nd = nd % 8;
            if(maps[sx+dx[nd]][sy+dy[nd] ])
            {
                cout << nd << endl;
                continue;
            }
        }
    }
    return 0;
}

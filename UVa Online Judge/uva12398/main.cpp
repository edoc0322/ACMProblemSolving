#include <iostream>
#include <string>
using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int maps[3][3];
string s;
int main()
{
    int test = 1;
    while(getline(cin,s))
    {
        for(int i = 0 ; i < 3;++i)
        {
            for(int j = 0 ; j < 3;++j)
            {
                maps[i][j] = 0;
            }
        }
        for(int i = s.length()-1;i >= 0;--i)
        {
            int C = (s[i]-'a') % 3;
            int R = (s[i]-'a') / 3;
            for(int dir = 0 ; dir < 4;++dir)
            {
                int ny = dy[dir] + R;
                int nx = dx[dir] + C;
                if(ny < 3 && ny >= 0 && nx < 3 && nx >= 0)
                {
                    maps[ny][nx] = (maps[ny][nx]+1) % 10;
                }
            }
            maps[R][C] = (maps[R][C]+1) % 10;
        }
        cout << "Case #" << test++ << ":" <<endl;
        for(int i = 0 ; i < 3;++i)
        {
            for(int j = 0 ; j < 3;++j)
            {
                if(j == 0)
                {
                    cout << maps[i][j];
                }
                else
                {
                    cout << " " << maps[i][j];
                }
            }
            cout <<endl;
        }
    }
    return 0;
}

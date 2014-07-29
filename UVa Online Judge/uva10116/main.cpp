#include <iostream>
#include <string>
using namespace std;

string maps[100];
int R,C;
int steps[101][101];
int v[101][101];
int pre[101][101][2];
int counts;
int Fc;

int dir[100][2];

int main()
{

    dir['N'][0] = -1;
    dir['N'][1] = 0;
    dir['E'][0] = 0;
    dir['E'][1] = 1;
    dir['S'][0] = 1;
    dir['S'][1] = 0;
    dir['W'][0] = 0;
    dir['W'][1] = -1;

    while(cin >> R && cin >> C && cin >> Fc && R && C && Fc)
    {
        for(int i = 1 ; i <= R;++i)
        {
            string temp;
            cin >> temp;
            maps[i] = " " + temp;
        }
        for(int i = 1 ; i <= 100;++i)
        {
            for(int j = 1 ; j <= 100;++j)
            {
                steps[i][j] = 0;
                v[i][j] = 0;
                pre[i][j][0] = 0;
                pre[i][j][1] = 0;
            }
        }
        int y = 1;
        int x = Fc;
        int status = 1;
        counts = 0;
        //cout << "ori " << y << " " << x <<endl;
        while(status)
        {

            counts++;
            v[y][x]++;
           // cout << "?? "<< y << " " << x << endl;
            steps[y][x] = counts;
            int ny = y + dir[maps[y][x]][0];
            int nx = x + dir[maps[y][x]][1];

            if(v[ny][nx] == 1)
            {
                int preY = pre[ny][nx][0];
                int preX = pre[ny][nx][1];
                //cout << preY << "  " << preX <<endl;
                //cout << steps[y][x] <<endl;
                cout << steps[preY][preX] << " step(s) before a loop of " <<  steps[y][x] - steps[preY][preX] <<" step(s)" <<endl;
                break;
            }
            else if(ny < 1 || ny > R || nx < 1 || nx > C)
            {
                cout << counts << " step(s) to exit" <<endl;
                break;
            }
            pre[ny][nx][0] = y;
            pre[ny][nx][1] = x;
            y = ny;
            x = nx;


        }
    }
    return 0;
}

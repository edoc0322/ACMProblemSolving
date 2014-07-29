#include <iostream>
#include <string>
#include <deque>
using namespace std;

string maps[10];
int numMaps[10][10];

int minS;
struct cor
{
    int x,y;
};

void prinfMap()
{
    for(int i = 0 ; i < 10;++i)
    {
        for(int j = 0 ; j < 10;++j)
        {
            cout << numMaps[i][j];
        }
        cout <<endl ;
    }
    cout << endl;
}

int backtrack(deque<cor> data,int counts,int light)
{
    //cout << counts << "  " << light <<endl;
    //prinfMap();
    if(counts >= 100)
    {
        return -1;
    }
    if(light == 0)
    {
        if(counts < minS)
        {
            minS = counts;
        }
        return 1;
    }
    for(int i = 0 ; i < data.size();++i)
    {

        int x = data.front().x;
        int y = data.front().y;
        //cout << x << " " << y << endl;
        int ux = x;
        int uy = y-1;
        int rx = x+1;
        int ry = y;
        int dx = x;
        int dy = y+1;
        int lx = x-1;
        int ly = y;
        int count2 = -1;
        if(numMaps[y][x] == 1)
        {
            numMaps[y][x] = 0;
            if(uy >= 0)
            {
                if(numMaps[uy][ux] == 0)
                {
                    numMaps[uy][ux] = 1;
                    cor c;
                    c.y = uy;
                    c.x = ux;
                    data.push_back(c);
                    count2++;
                }
                else
                {
                    numMaps[uy][ux] = 0;
                    count2--;
                }
            }

            if(dy < 10)
            {
                if(numMaps[dy][dx] == 0)
                {
                    numMaps[dy][dx] = 1;
                    cor c;
                    c.y = dy;
                    c.x = dx;
                    data.push_back(c);
                    count2++;
                }
                else
                {
                    numMaps[dy][dx] = 0;
                    count2--;
                }
            }

            if(rx < 10)
            {
                if(numMaps[ry][rx] == 0)
                {
                    numMaps[ry][rx] = 1;
                    cor c;
                    c.y = ry;
                    c.x = rx;
                    data.push_back(c);
                    count2++;
                }
                else
                {
                    numMaps[ry][rx] = 0;
                    count2--;
                }
            }

            if(lx >= 0)
            {
                if(numMaps[ly][lx] == 0)
                {
                    numMaps[ly][lx] = 1;
                    cor c;
                    c.y = ly;
                    c.x = lx;
                    data.push_back(c);
                    count2++;
                }
                else
                {
                    numMaps[ly][lx] = 0;
                    count2--;
                }
            }
            //cout << counts+1 << "  " << light+count2 <<endl;
            data.pop_front();
            backtrack(data,counts+1,light+count2);

            numMaps[y][x] = 1;
            if(uy >= 0)
            {
                if(numMaps[uy][ux] == 0)
                {
                    numMaps[uy][ux] = 1;
                    cor c;
                    c.y = uy;
                    c.x = ux;
                    data.push_back(c);
                }
                else
                {
                    numMaps[uy][ux] = 0;
                }
            }

            if(dy < 10)
            {
                if(numMaps[dy][dx] == 0)
                {
                    numMaps[dy][dx] = 1;
                    cor c;
                    c.y = dy;
                    c.x = dx;
                    data.push_back(c);
                }
                else
                {
                    numMaps[dy][dx] = 0;
                }
            }

            if(rx < 10)
            {
                if(numMaps[ry][rx] == 0)
                {
                    numMaps[ry][rx] = 1;
                    cor c;
                    c.y = ry;
                    c.x = rx;
                    data.push_back(c);
                }
                else
                {
                    numMaps[ry][rx] = 0;
                }
            }

            if(lx >= 0)
            {
                if(numMaps[ly][lx] == 0)
                {
                    numMaps[ly][lx] = 1;
                    cor c;
                    c.y = ly;
                    c.x = lx;
                    data.push_back(c);
                }
                else
                {
                    numMaps[ly][lx] = 0;
                }
            }

        }
        else
        {
            data.pop_front();
        }
    }
    return -1;
}

int main()
{

    string s;
    while(cin >> s)
    {
        int light = 0;
        deque<cor> data;
        for(int i = 0 ; i < 10;++i)
        {
            cin >> maps[i];
            for(int j = 0 ; j < 10;++j)
            {
                if(maps[i][j] == 'O')
                {
                    numMaps[i][j] = 1;
                    light++;
                    cor c;
                    c.y = i;
                    c.x = j;
                    data.push_back(c);
                }
                else
                {
                    numMaps[i][j] = 0;
                }
            }
        }
        minS = 99999999;
        int ans;
        backtrack(data,0,light);
        if(minS != 99999999)
        {
            cout << s << " " << minS << endl;
        }
        else
        {
            cout << "GG\n";
        }
    }
    return 0;
}

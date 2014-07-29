#include <iostream>
#include <string>
using namespace std;

char maps[60][60];


int main()
{
    int n;
    int counts = 1;
    cin >> n;
    string s;
    while(n--)
    {
        cin >> s;
        for(int i = 0 ; i <60;++i)
        {
            for(int j = 0 ; j < 60;++j)
            {
                maps[i][j] = ' ';
            }
        }
        int x = 2,y = 1;
        int maxX = s.length() + 1;
        int maxY = y;
        int minY = 1;
        for(int i = 0 ; i < s.length() ; ++i)
        {
            if(s[i] == 'R')
            {
                y++;
            }
            else if(s[i] == 'C')
            {
            }
            else if(s[i] == 'F')
            {
                y--;
                if(minY > y)
                {
                    minY = y;
                }
            }
        }

        int disY = 1-minY;
        x = 2;
        y = 1;
        for(int i = 0 ; i < s.length() ; ++i)
        {
            //cout << x << "  " << y << "  " << disY << endl;
            if(s[i] == 'R')
            {
                if(y+disY > maxY)
                {
                    maxY = y+disY;
                }
                maps[x][y+disY] = '/';
                y++;
                x++;


            }
            else if(s[i] == 'C')
            {
                if(y+disY > maxY)
                {
                    maxY = y+disY;
                }
                maps[x][y+disY] = '_';
                x++;
            }
            else if(s[i] == 'F')
            {

                y--;
                maps[x][y+disY] = '\\';
                if(y+disY > maxY)
                {
                    maxY = y+disY;
                }
                x++;

            }
        }

        maps[0][0] = '+';
        //cout << maxY <<endl;
        for(int i = 1 ; i <= maxX+1 ;++i)
        {
            maps[i][0] = '-';
        }
        for(int i = 1 ; i <= maxY; ++i)
        {
            maps[0][i] = '|';
        }
        cout << "Case #" << counts++ <<":" <<endl;
        int xEnd;
        for(int i = maxY ; i >=0 ;--i)
        {
            int status = 1;
            for(int j = 0 ; j <= maxX+1;++j)
            {
                if(maps[j][i] != ' ')
                {
                    xEnd = j;
                }
            }

            for(int j = 0 ; j <= maxX+1;++j)
            {
                cout << maps[j][i];
                if(j == xEnd)
                {
                    cout <<endl;
                    status = 0;
                    break;
                }
            }
            if(status)
                cout << endl;
            //cout <<endl;
        }

        cout << endl;
    }


    return 0;
}

#include <iostream>

using namespace std;
int maps[9][9];
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        for(int i = 0 ; i < 9 ;i = i + 2)
        {
            for(int j = 0 ; j <= i;j= j +2)
            {
                cin >> maps[i][j];
            }
        }
        for(int i = 0 ; i < 9-2 ;i = i + 2)
        {
            for(int j = 0 ; j <= i;j= j +2)
            {
                int sumsTarget = maps[i][j];
                for(int k = 1 ; k < sumsTarget ;++k)
                {
                    int base1 = k;
                    int base2 = sumsTarget - base1;
                    if(base1-maps[i+2][j] == base2 - maps[i+2][j+2])
                    {
                        maps[i+2][j+1] = base1-maps[i+2][j];
                        maps[i+1][j] = base1;
                        maps[i+1][j+1] = base2;
                        break;
                    }

                }
            }
        }
        for(int i = 0 ; i < 9;++i)
        {
            for(int j = 0 ; j <= i;++j)
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
            cout << endl;
        }
    }

    return 0;
}

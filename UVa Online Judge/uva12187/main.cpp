#include <iostream>

using namespace std;

int N,R,C,K;
int maps[102][102];
int copyMaps[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main()
{
    while(cin >> N && cin >> R && cin >> C && cin
          >> K && N && R && C && K)
    {
        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < C;++j)
            {
                cin >> maps[i][j];
                copyMaps[i][j] = maps[i][j];
            }
        }
        for(int i = 0 ; i < K;++i)
        {
            for(int j = 0 ; j < R;++j)
            {
                for(int k = 0 ; k < C;++k)
                {
                    for(int dir = 0 ; dir < 4;++dir)
                    {
                        int ny = j + dy[dir];
                        int nx = k + dx[dir];
                        if(ny >= 0 && ny < R && nx >= 0 && nx < C)
                        {
                            if(maps[ny][nx] == ((maps[j][k] + 1) % N  ))
                            {
                                copyMaps[ny][nx] = maps[j][k];
                            }
                        }
                    }
                }
            }
            for(int j = 0 ; j < R;++j)
            {
                for(int k = 0 ; k < C;++k)
                {
                    maps[j][k] = copyMaps[j][k];
                }
            }

        }
        for(int j = 0 ; j < R;++j)
        {
            for(int k = 0 ; k < C;++k)
            {
                if(k == 0)
                {
                    cout << maps[j][k];
                }
                else
                {
                    cout << " " << maps[j][k];
                }
            }
            cout << endl;
        }
    }
    return 0;
}

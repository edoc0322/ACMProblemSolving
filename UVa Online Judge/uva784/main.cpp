#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char maps[31][85];
int note[31][85];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int N;
void dfs(int i,int j)
{

    note[i][j] = 2;
    //cout << i << "  " << j << " " << note[i][j]<<endl;
    for(int k = 0 ; k < 4;++k)
    {
        int ny = i+dy[k];
        int nx = j+dx[k];
        if(ny >= 0 && ny < N && nx >= 0 && nx < strlen(maps[ny]))
        {
            if(note[ny][nx] == 1)
            {
                //cout << note[ny][nx] << endl;
                //cout << nx << " " << ny << " ????0\n";
                dfs(ny,nx);
            }
        }
    }
}
int main()
{
    int test;
    cin >> test;
    getchar();
    while( test > 0)
    {
        int sx,sy;
        N = 0;
        while(cin.getline(maps[N],90))
        {
            if(maps[N][0] == '_') break;
            for(int i = 0 ; i < strlen(maps[N]);++i)
            {
                if(maps[N][i] == 'X')
                {
                    note[N][i] = 0;
                }
                else if(maps[N][i] == ' ')
                {
                    note[N][i] = 1;
                }
                else if(maps[N][i] == '*')
                {
                    note[N][i] = 1;
                    sy = N;
                    sx = i;
                }
            }
            N++;
            //cout << N <<endl;
        }

        dfs(sy,sx);

        for(int i = 0 ;i < N;++i)
        {
            for(int j = 0 ; j < strlen(maps[i]);++j)
            {
                if(note[i][j] == 0)
                    cout << "X";
                else if(note[i][j] == 1)
                {
                    cout << " ";
                }
                else
                    cout << "#";
            }
            cout << endl;
        }
        cout << "_____\n";


        test--;
    }
    return 0;
}

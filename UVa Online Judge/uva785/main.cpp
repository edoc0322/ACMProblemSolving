#include <iostream>
#include <cstring>
using namespace std;

char maps[1000][1000];
int note[1000][1000];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int N;

void dfs(int i ,int j,int NN,int mark)
{
    //cout << i << " " << j << endl;
    note[i][j] = mark;
    for(int k = 0 ; k < 4;++k)
    {
        int nx = j+dx[k];
        int ny = i+dy[k];
        //cout << nx << " " << ny << " " << N << " " << strlen(maps[ny]) << " "<<endl;
        if(ny >= 0 && ny < NN && nx >= 0 && nx < strlen(maps[ny]))
        {
            //cout << note[ny][nx] <<endl;
            if(note[ny][nx] == 1)
            {
                dfs(ny,nx,NN,mark);
            }
        }
    }
}

int main()
{
    int N = 0;
    int markNum = 0;
    int markX[10000];
    int markY[10000];
    int markS[10000];
    while(cin.getline(maps[N],1000))
    {
        if(maps[N][0] == '_')
        {
            for(int i = 0 ; i <markNum;++i)
            {
                dfs(markY[i],markX[i],N,markS[i]);
            }

            for(int i = 0 ; i < N;++i)
            {
                for(int j = 0 ; j < strlen(maps[i]);++j)
                {
                    if(note[i][j] == 0)
                    {
                        cout << "X";
                    }
                    else if(note[i][j]==1)
                    {
                        cout << " ";
                    }
                    else
                    {
                        cout << (char) note[i][j];
                    }
                }
                cout <<endl;
            }


            cout << "_____________________________\n";
            N= 0;
            markNum = 0;
        }
        else
        {
            for(int i = 0 ; i < strlen(maps[N]);++i)
            {
                if(maps[N][i] =='X')
                {
                    note[N][i] = 0;
                }
                else if(maps[N][i] == ' ')
                {
                    note[N][i] = 1;
                    //cout << "HI\n";
                }
                else
                {
                    note[N][i] = 1;
                    markY[markNum] = N;
                    markX[markNum] = i;
                    markS[markNum] = maps[N][i];
                    //cout << maps[N][i]<<endl;
                    markNum++;
                }
            }
            N++;
            //cout << N <<endl;
        }
    }
    return 0;
}

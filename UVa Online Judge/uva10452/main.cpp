#include <iostream>
#include <string>
using namespace std;
string maps[9];
int M,N;
int dx[3] = {-1,0,1};
int dy[3] = {0,-1,0};
int ey,ex;
string ansStr[3] = {"left","forth","right"};
int ans[7];
int tempAns[7];
string pattern = "IEHOVA#";
int findAns = 0;
void backtrack(int r,int c,int depth)
{
    if(ey == r && ex == c)
    {
        for(int j = 0 ; j < 7;++j)
        {
            ans[j] = tempAns[j];
        }
        findAns = 1;
        return;
    }

    for(int i = 0 ; i < 3;++i)
    {
        int ny = r + dy[i];
        int nx = c + dx[i];
        //cout << ny << " " << nx <<endl;;
        if(ny >= 0 && ny < M && nx >= 0 && nx < N)
        {
            if(maps[ny][nx] == pattern[depth])
            {
                tempAns[depth] = i;
                //cout << ny << " " << nx <<endl;
                backtrack(ny,nx,depth+1);
                if(findAns) return;
            }
        }
    }
}
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        cin >> M >> N;
        int sy,sx;
        for(int i = 0 ; i < M;++i)
        {
            cin >> maps[i];
            for(int j = 0 ; j < N;++j)
            {
                if(maps[i][j] == '@')
                {
                    sy =i;
                    sx = j;
                    break;
                }
            }
            for(int j = 0 ;  j < N;++j)
            {
                if(maps[i][j] == '#')
                {
                    ey = i;
                    ex = j;
                    break;
                }
            }
        }
        //cout << sy << " " << sx << " " << ey << " " << ex <<endl;
        findAns = 0;
        backtrack(sy,sx,0);
        for(int j = 0 ; j < 7;++j)
        {
            if(j == 0)
            {
                cout << ansStr[ans[j]];
            }
            else
            {
                cout << " " << ansStr[ans[j]];
            }
        }
        cout <<endl;
    }
    return 0;
}

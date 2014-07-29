#include <iostream>
#include <map>
using namespace std;

int R,C,N;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main()
{
    int test = 1;
    while(cin >> R && cin >> C && cin >> N && R && C && N)
    {
        map<int,int> col,row;
        for(int i = 0 ;i < N;++i)
        {
            int r1,c1;
            cin >> r1 >> c1;
            row[r1] = 1;
            col[c1] = 1;
        }
        int sr,sc;
        cin >> sr >> sc;
        int status = 0;
        if(row[sr] == 0 && col[sc] == 0)
        {
            status = 1;
        }
        else
        {
            for(int i = 0 ; i < 4 ;++i)
            {
                int nx = sc + dx[i];
                int ny = sr + dy[i];
                if(nx >= 0 && nx < C && ny >= 0 && ny < R)
                {
                    //cout << (row.find(ny) == row.end()) << "  " << (col.find(nx) == col.end()) <<endl;
                    if(row[ny] == 0 && col[nx] == 0)
                    {
                        status = 1;
                        break;
                    }
                }
            }
        }

        cout << "Case " << test++ << ": ";
        if(status)
        {
            cout << "Escaped again! More 2D grid problems!" << endl;
        }
        else
        {
            cout << "Party time! Let's find a restaurant!" << endl;
        }
    }
    return 0;
}

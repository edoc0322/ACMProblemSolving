#include <iostream>
#include <string>

using namespace std;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
char dirr;
int dir;
int drop[51][51];

string dirs ="ESWN";
int main()
{
    int m,n;
    cin >> m;
    cin >> n;
    int count = 0;
    int locx,locy;
    string command;
    while( (cin >> locx) && (cin >> locy) && (cin >> dirr) && (cin >> command))
    {
        //cout << " input is "<< locx << " " << locy << " "<< dirr << " " << command<<endl;
        int status = 0;
        if(dirr == 'E')
        {
            dir = 0;
        }
        else if(dirr == 'S'){
            //cout << "hi!\n";
            dir = 1;
        }
        else if(dirr == 'W'){
            dir = 2;
        }
        else{
            dir = 3;
        }
        for(int i = 0 ; i < command.length();i++){
            if(command[i] == 'R'){
                dir += 1;
                dir %= 4;
            }
            else if (command[i] == 'L'){
                dir -= 1;
                if(dir == -1){
                    dir = 3;
                }
            }
            else{
                if(drop[locx][locy] && (locx + dx[dir] > m || locx + dx[dir] < 0 || locy + dy[dir] > n || locy + dy[dir] < 0)){
                    continue;
                }
                locx += dx[dir];
                locy += dy[dir];
                if(locx > m || locx < 0 || locy > n || locy < 0){
                    locx -= dx[dir];
                    locy -= dy[dir];
                    drop[locx][locy] = 1;
                    count++;
                    status = 1;
                    break;

                }
            }
        }
        //cout << dir <<" is dir\n";
        cout << locx << " "<< locy << " "<< dirs[dir];
        if(status){
            cout << " LOST";
        }
        cout << endl;
    }
    return 0;
}

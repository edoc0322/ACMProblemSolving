#include <iostream>
#include <string>
using namespace std;

int dir[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int main()
{
    int map[101][101];
    int m , n ,i,j,k;
    int count = 1;
    string maps[101];

    while(1){

        cin >> m;
        cin >> n;

        if(m ==0 && n == 0){
            break;
        }
        if(count !=1){
            cout << endl;
        }
        for(i = 0 ; i < m ;i++){
            for(j = 0 ; j < n ; j++){
                map[i][j] = 0;
            }
        }

        for(i = 0 ;i < m ;i++){
            cin >> maps[i];
        }
        cout << "Field #" << count << ":" << endl;
        for(i = 0 ; i < m ; i++){
            for(j = 0 ; j < n ;j++){
                if(maps[i][j] == '*'){
                    for(k = 0 ; k < 8 ;k++){
                        if(i+dir[k][1] >= 0 && i+dir[k][1]<m && j+dir[k][0] >= 0 && j+dir[k][0]<n){
                            map[i+dir[k][1]][j+dir[k][0]]++;
                        }
                    }
                }
            }
        }

        for(i = 0 ; i < m ; i++){
            for(j = 0 ; j < n ;j++){
                if(maps[i][j] == '*'){
                    cout << "*";
                }
                else{
                    cout << map[i][j];
                }
            }
            cout << endl;
        }
        count++;


    }

    return 0;
}

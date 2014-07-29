#include <iostream>


using namespace std;
int n;
bool visit[201];
int map[201][201];
int vcolor[201];
int status = 0;
bool promising(int i){
    int j;
    bool switch_i;

    switch_i=true;
    j = 1;
    while(j < i && switch_i){
        if(map[i][j] && vcolor[i] == vcolor[j])
            switch_i = false;
        j++;
    }
    return switch_i;
}
void m_coloring(int i){
    int color;
    if(promising(i)){
        if(i == n){
            status = 1;
        }
        else{
            for(color = 1 ; color <= 2;color++){
                vcolor[i+1] = color;
                m_coloring(i+1);
            }
        }
    }

}


void DFS(int i)
{

}

int main()
{



    int m,i,a,b,j;

    while(cin >> n){
        if(n==0) break;
        status = 0;
        cin >> m;
        for(i = 0 ; i <= n;i++){
            vcolor[i] = -1;
        }
        for(i = 0 ; i <= n ; i++){
            for(j = 0 ; j <= n ;j++){
                map[i][j] = 0;
            }
        }
        for (i=0; i<n; i++)
            visit[i] = false;

        for(i = 0 ; i < m;i++){
            cin >> a;
            cin >> b;
            map[a+1][b+1] = map[b+1][a+1] = 1;
        }
        m_coloring(0);
        if(status){
            cout << "BICOLORABLE.\n";
        }
        else{
            cout <<"NOT BICOLORABLE.\n";
        }
        /*
        for (int i=0; i<n; i++)
            if (!visit[i])
            {
                visit[i] = true;
                DFS(i);
            }
        */
    }
    return 0;
}

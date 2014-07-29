#include <iostream>
#include <queue>

using namespace std;
int man[29];
void next(int& p,int n)
{
    //cout << p << endl;
    do
    {
        p++;
        p%=(n+1);
        if(p == 0) p = 1;
    }while(man[p] == 0);
    /*
    while(man[p] == 0)
    {
        ++p;
        p%=n+1;
        if(p == 0) p = 1;
        cout << p << endl;
    }
    */
    //++p;
    //p%=n+1;
    //if(p == 0) p = 1;
}


int whoSaved(int n , int m)
{
    int count = 1;
    for(int i = 1 ; i <= n ;i++)
    {
        man[i] = 1;
    }
    int p = 1;
    int answer;
    int gk = n/2;
    int men;
    for(men = n ; men > 1 ;--men)
    {

        for(int i = 0 ; i <(m-1)%men; ++i)
        {
            next(p,n);
        }
        man[p] = 0;
        answer = p;


        if(answer <= gk && count <= gk){
            return 0;

        }
        if(answer <= gk && count > gk){
            return 1;
        }
        count++;
        next(p,n);

    }
    return answer;
}
int main()
{
    int ans[14];
    for(int i = 1;i <= 13;++i){
        for(int m = 1;;++m){
            if(whoSaved(i*2,m)){
                ans[i] = m;
                break;
            }
        }
    }
    int k;

    while(cin >> k)
    {
        if(k == 0) break;
        cout << ans[k]<<endl;

    }
    return 0;
}

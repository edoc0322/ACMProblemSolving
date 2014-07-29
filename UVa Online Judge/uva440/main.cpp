#include <iostream>

#include <queue>

using namespace std;
int ans[151];
int who(int n,int m)
{
    queue<int> q1;
    vector<int> v1;
    int temp,ans;
    for(int i = 1 ; i <= n;++i){
        q1.push(i);
    }
    q1.pop();
    while(!q1.empty()){
        for(int i = 0 ; i < m-1;++i)
        {
            temp = q1.front();
            q1.pop();
            q1.push(temp);
        }
        ans = q1.front();
        q1.pop();
    }
    return ans;
}
int main()
{
    for(int i = 3;i<150;++i){
        for(int m = 1 ; ;++m){
            if(who(i,m) == 2)
            {
                ans[i] = m;
                break;
            }
        }
    }
    int n;
    while(cin >> n){
        if(!n) break;
        cout << ans[n] << endl;
    }

    return 0;
}

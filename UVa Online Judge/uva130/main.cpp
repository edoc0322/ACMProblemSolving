#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int who(int n,int m)
{
    queue<int> q1;
    vector<int> v1;
    int temp,ans;
    for(int i = 1 ; i <= n;++i){
        q1.push(i);
    }
    while(!q1.empty()){
        for(int i = 0 ; i < m-1;++i)
        {
            temp = q1.front();
            q1.pop();
            q1.push(temp);
        }
        ans = q1.front();
        q1.pop();
        if(q1.empty()){
            break;
        }
        for(int i = 0 ; i < m;++i){
            temp = q1.front();
            q1.pop();
            v1.insert(temp);
        }
        for(i)
    }
}
int main()
{

    return 0;
}

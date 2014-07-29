#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int josephus(int n, int m)
{
    queue<int> queue1;
    for (int i=1; i<=n; ++i)
        queue1.push(i);

    int answer;
    while (!queue1.empty())
    {
        // pop 和 push m-1 人
        //cout << "ans "<<answer << endl;
        answer = queue1.front();
        queue1.pop();
         //cout << answer <<" hi " << endl;
        if(queue1.empty()){
            break;
        }
        for (int i=0; i<m-1; ++i)
        {


            int temp = queue1.front();

            queue1.pop();
            queue1.push(temp);
        }
        // 第 m 個人 pop 出來後就不放回去


    }

    //cout << "存活的人是" << answer << "號" << endl;
    return answer;
}



/*
int josephus(int n, int m)
{
    int answer = 0;
    for (int i=1; i<=n; ++i)
        answer = (answer + m) % i;
    cout << "存活的人是" << answer << "號" << endl;
    return answer;
}
*/
int main()
{
    //cout << josephus(17,5)<<endl;
    //cout << josephus(2,2) << endl;
    int n,i;
    while(cin>>n){
        if(n == 0 )break;
        for(i = 1 ; i < 10000;i++){
            if(josephus(n,i)==13){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}

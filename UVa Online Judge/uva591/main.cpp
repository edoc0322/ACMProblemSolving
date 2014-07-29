#include <iostream>

using namespace std;

int main()
{
    int m,i;
    int wall[101];
    int sum,temp,avg;
    int count = 1;
    while(cin >> m){
        sum = 0;
        if(m == 0 ) break;
        for(i = 0 ; i < m ;i++){
            cin >> wall[i];
            sum += wall[i];
        }
        avg = sum/m;
        int ans = 0;
        for(i = 0 ; i < m ; i++){
            if(wall[i] < avg){
                ans+= avg-wall[i];
            }
        }
        cout <<"Set #"<< count <<endl;
        cout << "The minimum number of moves is " << ans << ".\n";
        cout << endl;
        count++;

    }
    return 0;
}

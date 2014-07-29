#include <iostream>

using namespace std;

int main()
{
    int n,q;
    int i , j;
    while(cin >> n){
        int height[n];

        for(i = 0 ; i < n;i++){
            cin >> height[i];
        }
        cin >> q;
        int query[q];

        for(i = 0 ; i < q;i++){
            cin >> query[i];
        }
        for (i = 0 ; i < q;i++){
            int ans1=0,ans2=0;

            for (j = 0 ; j < n;j++){

                if(height[j]>=query[i]){

                    if(j == 0){
                        ans1 = -1;
                    }
                    else if(ans1 == 0){
                        ans1 = height[j-1];
                    }
                    if(height[j] ==query[i] ){
                        continue;
                    }
                    else if(height[j] > query[i]){
                        ans2 = height[j];
                    }
                }
                if(j == n-1 && ans1 == 0){
                    ans1 = height[j];
                    ans2 = -1;
                }
                if(ans1 != 0 && ans2 != 0){
                    break;
                }
            }
            if(ans1 == -1){
                cout << "X ";
            }
            else{
                cout << ans1 << " ";
            }
            if(ans2 == -1){
                cout << "X" << endl;
            }
            else{
                cout << ans2 << endl;
            }

        }
    }
    return 0;
}

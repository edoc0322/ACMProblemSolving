#include <iostream>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while(test>0){
        int num,i,j ;
        int arr[51];
        cin >> num;
        for(i=0;i<num;i++){
            cin >> arr[i];
        }
        int ans=0;
        for(i = 0 ; i < num-1;i++){
            for(j = 0 ; j < num-1-i;j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    ans++;
                }
            }
        }
        cout << "Optimal train swapping takes " << ans << " swaps.\n";
        test--;
    }

    return 0;
}

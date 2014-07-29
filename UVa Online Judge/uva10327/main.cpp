#include <iostream>

using namespace std;

int main()
{
    int num;
    int i ,j;
    int temp;
    while( cin >> num){
        int numm[num];
        int ans = 0;
        for (i = 0 ; i < num;i++){
            cin >> numm[i];
        }
        for(i = num;i>0;i--){
            for(j = 0 ;j < i-1;j++){
                if(numm[j]>numm[j+1]){
                    temp = numm[j];
                    numm[j] = numm[j+1];
                    numm[j+1] = temp;
                    ans++;
                }
            }
        }
        cout << "Minimum exchange operations : " << ans << endl;
    }
    return 0;
}

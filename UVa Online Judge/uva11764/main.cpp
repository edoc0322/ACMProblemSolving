#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >>T;
    int up,down;
    int k;
    int wall[100];
    int count =1;
    while(T>0){
        up = down = 0;
        cin >> k;
        for(int i = 0 ; i < k;++i){
            cin >> wall[i];
        }

        for(int i = 1 ; i < k;++i){
            if(wall[i]>wall[i-1]){
                ++up;
            }
            else if(wall[i]<wall[i-1]){
                ++down;
            }
        }
        cout << "Case "<<count<<": "<<up<<" "<<down<<endl;
        ++count;
        --T;

    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int n;
    int hn;
    int pageans[101][2];
    while(cin >> n){
        if(!n) break;
        if(n == 1){
            cout << "Printing order for 1 pages:\n";
            cout << "Sheet 1, front: Blank, 1\n";
            continue;
        }
        hn = n / 2;
        if(hn %2){
            hn += 1;
        }
        while(hn*2 < n){
            hn += 2;
        }
        unsigned int bitint = 1;
        int count = 1;
        for(int i = 0 ;i <hn;++i){
            pageans[i][bitint]= count;
            count++;
            bitint = !bitint;
        }
        for(int i = hn-1 ; i >=0;--i){
            if(count > n){
                pageans[i][bitint] = -1;
            }
            else{
                pageans[i][bitint] = count;
                count++;
            }
            bitint = !bitint;
        }
        cout << "Printing order for " << n << " pages:\n";
        count = 1;
        bitint = 0;
        for(int i = 0 ; i < hn ; ++i){
            if(!bitint){
                cout << "Sheet " << count << ", front:";
                if(pageans[i][0] == -1){
                    cout << " Blank";
                }
                else{
                    cout << " " <<pageans[i][0];
                }
                cout << ",";
                if(pageans[i][1] == -1){
                    cout << " Blank";
                }
                else{
                    cout << " " <<pageans[i][1];
                }
                cout << endl;
                bitint = !bitint;
            }
            else{
                cout << "Sheet " << count << ", back :";
                if(pageans[i][0] == -1){
                    cout << " Blank";
                }
                else{
                    cout << " " <<pageans[i][0];
                }
                cout << ",";
                if(pageans[i][1] == -1){
                    cout << " Blank";
                }
                else{
                    cout << " " <<pageans[i][1];
                }
                cout << endl;
                bitint = !bitint;
                count++;
            }
        }
    }
    return 0;
}

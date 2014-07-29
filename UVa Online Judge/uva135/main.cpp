#include <iostream>
#define min(a,b) (((a) < (b)) ? (a) : (b))

using namespace std;

int main()
{
    int i =0;
    int ans = 0;
    int ugnum[1501];
    int cur = 0;
    ugnum[0] = 1;
    int m5,m3,m2;
    for(;;i++){
        int n = cur;
        for(m5 = 0;m5 < n;m5++){
            if(ugnum[m5]*5 > ugnum[cur]){
                break;
            }
        }
        for(m3 = 0;m3 < n;m3++){
            if(ugnum[m3]*3 > ugnum[cur]){
                break;
            }
        }
        for(m2= 0;m2 < n;m2++){
            if(ugnum[m2]*2 > ugnum[cur]){
                break;
            }
        }
        ugnum[++cur] = min(ugnum[m5]*5,min(ugnum[m3]*3,ugnum[m2]*2));
        if(cur == 1499){
            break;
        }
    }
    cout << "The 1500'th ugly number is " << ugnum[cur] << ".\n";
    return 0;
}

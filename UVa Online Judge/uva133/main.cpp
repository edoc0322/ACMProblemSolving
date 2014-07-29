#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int ans[20];
    int N,k,m,count,i,j,starti ,endi,count2;
    while((cin >> N) &&(cin >> k) &&(cin >> m) )
    {
        if(!N && !k && !m) break;
        count = N;
        for(i = 0 ; i < N;++i)
            ans[i] = 1;
        starti = 0;
        endi = N-1;
        while(count != 0){
            count2 = 0;
            for(i = starti ; count2 < k ;++i)
            {
                if(i == N){
                    i = 0;
                }
                if(ans[i]){
                    ++count2;
                }
            }
            //cout << count2 << " " << i <<endl;
            i--;
            count2 = 0;
            for(j = endi ; count2 < m ;--j)
            {
                if(j == -1){
                    j = N-1;
                }
                if(ans[j])
                    ++count2;
            }
            j++;
            if(i == j){
                cout << setw(3) << (i+1);
                ans[i] = 0;
                --count;
                if(count)
                    cout << ",";
                starti = endi = i;
            }
            else{
                cout << setw(3) << (i+1)<< setw(3) << (j+1);
                ans[i] = ans[j] = 0;
                starti = i;
                endi = j;
                count-=2;
                if(count)
                    cout << ",";
            }
        }
        cout << endl;
    }
    return 0;
}

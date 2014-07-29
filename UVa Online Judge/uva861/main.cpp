#include <iostream>
#include <cmath>
using namespace std;

int n,k;
int visit[9][9];
int ans = 0;

const long table[9][65] = { {0},
{1, 1}, {1, 4, 4}, {1, 9, 26, 26, 8}, {1, 16, 92, 232, 260, 112, 16},
{1, 25, 240, 1124, 2728, 3368, 1960, 440, 32},
{1, 36, 520, 3896, 16428, 39680, 53744, 38368, 12944, 1600, 64},
{1, 49, 994, 10894, 70792, 282248, 692320, 1022320, 867328, 389312,
81184, 5792, 128},
{1, 64, 1736, 26192, 242856, 1444928, 5599888, 14082528, 22522960, 22057472,
12448832, 3672448, 489536, 20224, 256}
};
void backtrack(int depth,int choose)
{
    //cout << depth << " " << choose <<endl;
    if(choose > k) return;
    if(depth == n*n && choose == k)
    {
        ans++;
        return;
    }
    if(depth == n*n) return;
    int r = depth/n;
    int c = depth%n;
    visit[r][c] = 1;
    int ok = 1;
    for(int i = 0 ; i < depth;++i)
    {
        int r2 =i / n;
        int c2 = i %n;
        if(visit[r2][c2] == 1 && abs(r2-r) == abs(c2-c) )
        {
            ok = 0;
            break;
        }
    }
    if(ok)
    {
        backtrack(depth+1,choose+1);
    }
    visit[r][c] = 0;
    backtrack(depth+1,choose);


}
int main()
{
    while(cin >> n && cin >> k)
    {
        if(n == 0 && k == 0) break;
        cout << table[n][k] <<endl;
        // 回溯法找完後,網路版本說建答案...
        //或者要用動態規劃Orz
        /*
        for(int i = 0 ; i < n;++i)
        {
            for(int j = 0 ; j < n;++j)
            {
                visit[i][j] = 0;
            }
        }
        ans = 0;
        backtrack(0,0);
        cout << ans <<endl;
        */

    }
    return 0;
}

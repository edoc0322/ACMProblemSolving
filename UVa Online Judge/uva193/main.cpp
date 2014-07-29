#include <iostream>
#include <cstdlib>
using namespace std;

int N;
int ans[101];
int realans[101];
int map1[101][101];
int maxI;
void color(int index)
{
    if(index == N)
    {
        int sum = 0;
        for(int i = 0 ; i < N;++i)
        {
            sum += ans[i];
        }
        if(sum > maxI)
        {
            maxI = sum;
            for(int i = 0 ; i < N;++i)
            {
                realans[i] = ans[i];
            }
        }
        //cout << endl;
    }
    else
    {
        for(int col = 0 ; col <= 1;++col)
        {
            ans[index] = col;
            int ok = 1;
            int c = 0;
            for(int j = 0 ; j < index;++j)
            {
                if(map1[index][j] && ans[j] == ans[index] && ans[index] == 1)
                {

                        ok = 0;
                        break;

                }
            }

            if(ok)
            {
                color(index+1);
            }


        }
    }
    return ;
}

int main()
{
    int test;
    cin >> test;
    int edge;
    int a,b;
    while(test > 0)
    {
        maxI = 0;
        cin >> N;
        cin >> edge;
        for(int i = 0 ;i < N;++i)
        {
            realans[i] = -1;
            ans[i] = -1;
            for(int j = 0 ; j < N;++j)
            {
                map1[i][j] = 0;
            }
        }
        for(int i = 0 ; i < edge;++i)
        {
            cin >> a;
            cin >> b;
            map1[a-1][b-1] = map1[b-1][a-1] = 1;
        }
        color(0);

        cout << maxI <<endl;
        int count = 0;
        for(int i = 0 ; i < N;++i)
        {
            if(realans[i])
            {
                cout << i+1;
                count++;
                if(count != maxI)
                {
                    cout << " ";
                }
            }

        }
        cout << endl;
        test--;
    }
    return 0;
}

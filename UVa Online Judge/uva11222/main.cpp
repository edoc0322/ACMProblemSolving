#include <iostream>
#include <vector>
using namespace std;

int arr[3][10001];
int num[3];
int ans[3][10001];
vector<int> arr2[3];
int main()
{
    int t,T;
    cin >> T;
    for(t = 1 ; t <=T;++t)
    {
        cout << "Case #" << t << ":" <<endl;
        for(int i = 0 ; i < 3;++i)
        {
            arr2[i].clear();
            for(int j = 0 ; j <= 10000;++j)
            {
                arr[i][j] = 0;
                ans[i][j] = 0;
            }
        }
        for(int i = 0 ; i < 3;++i)
        {
            cin >> num[i];
            for(int j = 0 ; j < num[i];++j)
            {
                int temp;
                cin >> temp;
                arr[i][temp] = 1;
                ans[i][temp] = 1;
                arr2[i].push_back(temp);
            }
        }
        for(int i = 0 ; i < 3;++i)
        {
            for(int j = 0 ; j < 3;++j)
            {
                if(i!=j)
                {
                    for(int k = 0 ; k < num[i];++k)
                    {
                        if(arr[j][arr2[i][k]] == 1)
                        {
                            ans[i][arr2[i][k]] = 0;
                        }
                    }
                }
            }
        }
        int maxI = -1;
        int maxN = -1;
        int arrsums[3];
        for(int i = 0 ; i < 3;++i)
        {
            int sums = 0;
            for(int j = 0 ; j < 10001;++j)
            {
                sums+= ans[i][j];
            }
            arrsums[i] = sums;
            if(sums > maxN)
            {
                maxN = sums;
                maxI = i;
            }
        }
        for(int j = 0 ; j < 3;++j)
        {
            if(maxN == arrsums[j])
            {
                cout << j+1 << " " << maxN ;
                for(int i = 0 ; i < 10001;++i)
                {
                    if(ans[j][i])
                    {
                        cout << " " <<i ;
                    }
                }
                cout <<endl;
            }


        }


    }
    return 0;
}

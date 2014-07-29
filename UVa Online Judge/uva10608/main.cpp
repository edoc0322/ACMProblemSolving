#include <iostream>

using namespace std;

int N,M;
int f[30001];
int counts[30001];
int maxI;


int finds(int i)
{
    while(f[i] != i )
    {
        return f[i] = finds(f[i]);
    }
    return i;
}
int unions(int i, int j)
{
    if(i > j)
    {
        f[i] = j;
        counts[j]+= counts[i];
        counts[i]= 0;
        if(counts[j] > maxI)
        {
            maxI = counts[j];
        }
    }
    else
    {
        f[j] = i;
        counts[i]+= counts[j];
        counts[j]= 0;
        if(counts[i] > maxI)
        {
            maxI = counts[i];
        }
    }
}


int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        cin >> N >> M;
        for(int i = 1 ; i <= N;++i)
        {
            f[i] = i;
            counts[i] = 1;
        }
        maxI = 1;
        int p1,p2;
        for(int i = 0 ; i < M;++i)
        {
            cin >> p1 >> p2;
            int f1,f2;
            f1 = finds(p1);
            f2 = finds(p2);
            if(f1 != f2)
            {
                unions(f1,f2);
            }
        }
        cout << maxI <<endl;
    }
    return 0;
}

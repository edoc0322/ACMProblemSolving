#include <iostream>
#define min(x,y) ( (x) < (y) ? (x):(y))
using namespace std;
int N = 5;


int fa[100000],ra[100000];
int getMin()
{
    bool visit[100000] = {false};
    int restB = 0;
    for(int i = 0 ; i < N;++i)
    {
        restB += fa[i];
        for(int j = 0 ; j < N;++j)
        {
            if(fa[i] == ra[j] && !visit[j])
            {
                visit[j] = true;
                break;
            }
        }
    }
    for(int i = 0 ; i < N;++i)
    {
        if(!visit[i])
        {
            restB += ra[i];
        }
    }
    return restB;
}

int getMax()
{
    int restB = 0;
    for(int i = 0 ; i < N;++i)
    {
        for(int j = 0 ; j < N;++j)
        {
            restB += min(fa[i],ra[j]);
        }
    }
    return restB;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            cin >> fa[i];
        }
        for(int i = 0 ; i < N;++i)
        {
            cin >> ra[i];
        }
        int minI = getMin();
        cout << "Matty needs at least " << minI
        << " blocks, and can add at most " << getMax()-minI << " extra blocks." <<endl;
    }

    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int test;
    cin >> test;
    char a,b;
    int N;
    for(int t = 1 ; t <= test;++t)
    {
        cin >>a;
        cin >> b;
        cin >> N;
        long long int maps[N][N];
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                cin >> maps[i][j];
            }
        }
        int status = 1;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = i ; j < N;++j)
            {
                if(maps[i][j] < 0 || maps[N-i-1][N-j-1] < 0)
                {
                    status = 0;
                    break;
                }
                if(maps[N-i-1][N-j-1] != maps[i][j])
                {
                    status = 0;
                    break;
                }
            }
            if(!status ) break;
        }
        cout << "Test #" << t << ": ";
        if(status)
        {
            cout << "Symmetric." <<endl;
        }
        else
        {
            cout << "Non-symmetric." <<endl;
        }
    }
    return 0;
}

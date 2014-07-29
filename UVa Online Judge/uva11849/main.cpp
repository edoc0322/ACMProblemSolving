#include <iostream>
#include <set>

using namespace std;

int main()
{
    long long int N , M;
    while( (cin >> N) && (cin >> M))
    {
        if(!N && !M) break;
        set<long long int> s;
        long long int t;
        for(int i = 0 ; i < N;++i)
        {
            cin >> t;
            s.insert(t);
        }
        for(int i = 0 ; i < M;++i)
        {
            cin >> t;
            s.insert(t);
        }
        cout << N+M-s.size()<<endl;
    }
    return 0;
}

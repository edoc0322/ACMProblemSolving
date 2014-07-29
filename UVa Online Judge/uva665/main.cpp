#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int T,t;
    cin >> T;
    for(t = 1 ; t <= T ;++t)
    {
        if(t > 1)
        {
            cout << endl;
        }
        int N,R;
        cin >> N >> R;
        int visit[N];
        for(int i = 0 ; i < N;++i)
        {
            visit[i] = 0;
        }
        for(int i = 0 ; i < R;++i)
        {
            string s;
            getchar();
            getline(cin,s);
            string ch;
            cin >> ch;
            if(ch[0] == '=')
            {
                int num;
                stringstream ss;
                ss << s;
                ss >> num;
                for(int j = 0 ;j < num*2;++j)
                {
                    int num2;
                    ss >> num2;
                    visit[num2-1] = 1;

                }
            }
        }
        int sums = 0;
        int index = -1;
        for(int i = 0;i < N;++i)
        {
            if(visit[i] == 0)
            {
                sums++;
                index = i+1;
            }
        }
        if(sums != 1)
        {
            cout << 0 <<endl;
        }
        else
        {
            cout << index <<endl;
        }

    }

    return 0;
}

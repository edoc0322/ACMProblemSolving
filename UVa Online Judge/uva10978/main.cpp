#include <iostream>
#include <string>
using namespace std;

string strvisit[10000];
int visit[10000];
int N;
int point;
void mark()
{
    do
    {
        point = (point+1) % N;
    }while(visit[point]);


}
int main()
{
    while(cin >> N && N)
    {
        point = 0;
        for(int i = 0 ; i < N;++i)
        {
            visit[i] = 0;
        }
        string strarr[N];

        for(int i = 0 ; i < N;++i)
        {
            string temp;
            cin >> strarr[i];
            cin >> temp;
            for(int i = 0 ; i < temp.length()-1;++i)
            {
                mark();
            }
            strvisit[point] = strarr[i];
            visit[point] = 1;
            //cout << point<<endl;
            if(i == N-1) break;
            mark();

        }
        for(int i = 0 ; i < N;++i)
        {
            if(i == 0)
            {
                cout << strvisit[i];
            }
            else
            {
                cout << " " << strvisit[i];
            }
        }
        cout << endl;
    }
    return 0;
}

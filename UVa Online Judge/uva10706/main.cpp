#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int len[40000];
int sum[40000];

int findLen(long long  n)
{
    int d= 0;
    while(n > 0)
    {
        n/=10;
        d++;
    }
    return d;

}

int main()
{
    sum[0] = 0;
    for(long long int i = 1,j = 0 ; j <= 2147483647;++i)
    {
        len[i] = findLen(i);
        //cout << i << "  " << len[i] <<endl;
        sum[i] = sum[i-1] + len[i];
        j += sum[i];
        //if(i <= 100) cout << i << "   " << sum[i] << endl;
    }
    int test;
    cin >> test;
    while(test--)
    {
        long long int N;
        cin >> N;
        for(int i = 0 ; N > sum[i]; N-= sum[i++]);
        int i;
        for(i = 1 ; N > len[i]; N-= len[i++]);
        string s;
        stringstream ss;
        ss << i;
        ss >> s;
        cout << s[N-1] <<endl;
    }
    return 0;
}

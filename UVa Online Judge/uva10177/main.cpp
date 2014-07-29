#include <iostream>

using namespace std;

long long int s2[110],s3[110],s4[110],r2[110],r3[110],r4[110];
int main()
{
    s2[0] = s3[0] = s4[0] = r2[0] = r3[0] = r4[0] =0;
    for(int i = 1 ; i <= 100 ;++i)
    {
        long long int r = (i*(i+1)/2);
        s2[i] = s2[i-1] + i*i;
        s3[i] = s3[i-1] + i*i*i;
        s4[i] = s4[i-1] + i*i*i*i;
        r2[i] = r*r-s2[i];
        r3[i] = r*r*r-s3[i];
        r4[i] = r*r*r*r-s4[i];
    }
    int n;
    while(cin >> n)
    {
        cout << s2[n] << " " << r2[n] << " " << s3[n] << " " << r3[n] << " " << s4[n] << " " << r4[n] << endl;
    }
    return 0;
}

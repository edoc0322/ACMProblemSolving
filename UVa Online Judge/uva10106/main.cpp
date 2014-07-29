#include <iostream>
#include <string>
using namespace std;

int n1[252],n2[252],n3[504];
void mul()
{
    for (int i=0; i<503; i++)
        n3[i] = 0;

    for (int i=0; i<250; i++)
        for (int j=0; j<250; j++)
            if (i+j < 500)
                n3[i+j] += n1[i] * n2[j];

    for (int i=0; i<500-1; i++) // 一口氣進位
    {
        n3[i+1] += n3[i] / 10;
        n3[i] %= 10;
    }
}
void print()
{
    int i = 500 - 1;
    while (i >= 0 && n3[i] == 0) i--;

    if (i < 0)
        cout << '0';
    else
        while (i >= 0) cout << n3[i--];
}

int main()
{
    string a,b;
    while((cin >> a) && (cin >> b))
    {
        for(int i = 0 ; i < 251;i++){
            n1[i] = n2[i] = 0;
        }
        int count = 0;
        for(int i = a.length()-1 ; i >=0 ;i--){
            n1[count++] = (int)(a[i]-'0');
        }
        count = 0;
        for(int i = b.length()-1 ; i >= 0;i--){
            n2[count++] = (int)(b[i]-'0');
        }
        mul();
        print();
        cout << endl;

    }
    return 0;
}

#include <iostream>

using namespace std;
int num[1001][2569];
int c[2569];
int maxI = 2569;
void mul(int a[], int b[], int c[])
{
    for (int i=0; i<maxI; i++)
    {
        //cout << "hi";
        c[i] = 0;
    }


    for (int i=0; i<maxI; i++)
        for (int j=0; j<maxI; j++)
            if (i+j < maxI)
                c[i+j] += a[i] * b[j];

    for (int i=0; i<maxI-1; i++)
    {
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }
}
void print(int a[])
{
    int i = maxI - 1;            // 要印的數字位置
    while (a[i] == 0) i--;      // 數字開頭的零都不印
    while (i >= 0) cout << a[i--];
}
int main()
{
    num[0][0] = 1;
    num[1][0] = 1;
    int count=1;
    int c2 = 0;
    int status = 0;
    int temp ;
    //print(num[1]);
    for(int i = 1; i<=1000;i++){
        for(int j = 0 ; j < maxI;++j)
        {
            c[j] = 0;
        }
        for(int j = 0 ;j<maxI-1 ;++j){
            c[j+1] = (i*num[i-1][j]+c[j])/10;
            //cout << c[j+1]<< endl;
            num[i][j] = (i*num[i-1][j]+c[j])%10;
        }

    }
    //print(num[1000]);
    int N;
    while(cin >> N){
        cout << N <<"!\n";
        print(num[N]);
        cout <<endl;
    }

    return 0;
}

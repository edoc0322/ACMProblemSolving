#include <iostream>
#include <cstdio>
using namespace std;

int maps[5000][5000];
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
         int N,E;
         cin >> N >> E;

         for(int i = 1 ; i <= N;++i)
         {
             for(int j = 1 ; j <= N;++j)
             {
                 maps[i][j] = 0;
             }
         }
         int a,b;
         for(int i = 0 ; i < E;++i)
         {
             scanf("%d %d",&a,&b);
             maps[a][b] = 1;
             maps[b][a] = 1;
         }
         int sums = 0;
         for(int i = 1 ; i <= N;++i)
         {
             for(int j = i+1 ; j <= N;++j)
             {
                 if(maps[i][j] == 0) continue;
                 for(int k = j +1;k <= N;++k)
                 {
                     if(maps[j][k] == 1 && maps[i][k] == 1)
                     {
                         sums++;
                     }
                 }
             }
         }
         cout << sums <<endl;
    }
    return 0;
}

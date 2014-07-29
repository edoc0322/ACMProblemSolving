#include <iostream>
#include <string>
#include <map>

using namespace std;
int M,N,D[100],B[100],Addr[100];
int Lb[100][10],Ub[100][10];
int diffb[100][10];
string name[100];
map<string,int> nameH;
int main()
{
    while(cin >> M && cin >> N)
    {
        for(int i = 0 ; i < M;++i)
        {
            cin >> name[i];
            nameH[name[i]] = i;
            cin >> Addr[i];
            cin >> B[i];
            cin >> D[i];
            for(int j = 0 ; j < D[i] ;++j)
            {
                cin >> Lb[i][j];
                cin >> Ub[i][j];
            }
            for(int j = 0 ; j < D[i] ;++j)
            {
                int sum = 1;
                for(int k = D[i]-1 ; k> j ;--k)
                {
                    sum *= Ub[i][k] - (Lb[i][k]-1);
                }
                diffb[i][j] = sum;
            }
        }
        for(int i = 0 ; i < N;++i)
        {
            string tn;
            cin >> tn;
            int index = nameH[tn];
            int Di = D[index];
            int sums = 0;
            int temps[10];
            for(int j = 0 ; j < Di;++j)
            {
                cin >> temps[j];
                sums += (temps[j]-Lb[index][j])* diffb[index][j];
            }
            cout << tn<<"[";
            for(int j = 0 ; j < Di;++j)
            {
                cout << temps[j];
                if(Di > 1 && j != Di-1)
                {
                    cout << ", ";
                }
                else
                {

                }
            }
            cout << "] = ";
            cout << Addr[index] + sums*B[index] <<endl;
        }
    }

    return 0;
}

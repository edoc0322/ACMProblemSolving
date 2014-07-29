#include <iostream>
#include <algorithm>
using namespace std;
int N;
int maps[102][102];

void build1(int rs)
{
    int half = N/2;
    for(int i = rs ; i < N - rs;++i)
    {
        swap(maps[rs][i] , maps[N-rs-1][i]);
    }
    for(int i = rs+1;i < half;++i)
    {
        swap( maps[i][rs] , maps[N-i-1][rs] );
        swap( maps[i][N-1-rs] , maps[N-i-1][N-1-rs]  );
    }
}

void build2(int rs)
{
    int half = N/2;
    for(int i = rs ; i < N - rs;++i)
    {
        swap(maps[i][rs] , maps[i][N-1-rs]);
    }
    for(int i = rs+1;i < half;++i)
    {
        swap( maps[rs][i] , maps[rs][N-i-1] );
        swap( maps[N-1-rs][i] , maps[N-1-rs][N-i-1] );
    }
}

void build3(int rs)
{
    int rightCor = N - rs -1;
    for(int i = rs+1 ; i <= rightCor;++i)
    {
        swap(maps[rs][i],maps[i][rs]);
    }
    for(int i = rs+1; i < rightCor;++i)
    {
        swap(maps[rightCor][i],maps[i][rightCor]);
    }

}

void build4(int rs)
{
    int rightCor = N - rs -1;
    for(int i = rs ;i < rightCor ;++i)
    {
        swap(maps[rs][i], maps[N-i-1][rightCor]);
    }
    for(int i = rs+1 ; i < rightCor;++i)
    {
        swap(maps[rightCor][i], maps[N-i-1][rs]);
    }
}


int main()
{

    int test;
    cin >> test;
    while(test--)
    {
        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                cin >> maps[i][j];
            }
        }
        int rings = N / 2;
        if(N %2 == 0)
        {
            rings--;
        }
        int opN,op;
        //cout << rings << " rings\n";
        for(int r = 0 ; r <= rings;++r)
        {
            cin >> opN;

            for(int i = 0 ; i < opN;++i)
            {
                cin >> op;
                if(op == 1)
                {
                    build1(r);
                }
                else if(op == 2)
                {
                   build2(r);
                }
                else if(op == 3)
                {
                    build3(r);
                }
                else if(op == 4)
                {
                    build4(r);
                }
                /*
                cout << "op " << op << " " << endl;
                for(int j = 0 ; j < N;++j)
                {
                    for(int k = 0 ; k < N;++k)
                    {
                        cout << maps[j][k] << " ";
                    }
                    cout <<endl ;
                }
                cout << endl;
                */


            }
        }
        for(int j = 0 ; j < N;++j)
        {
            for(int k = 0 ; k < N;++k)
            {
                if(k == 0)
                {
                    cout << maps[j][k];
                }
                else
                {
                    cout << " " << maps[j][k];
                }

            }
            cout <<endl;
        }

    }
    return 0;
}

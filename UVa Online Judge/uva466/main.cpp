#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int N;
char r[10][10];
char vr[10][10];
char pat[10][10];

bool checkOri()
{
    for(int i = 0 ; i < N;++i)
    {
        for(int j = 0 ; j<N;++j)
        {
            if(pat[i][j] != r[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
bool checkV()
{
    for(int i = 0 ; i < N;++i)
    {
        for(int j = 0 ; j<N;++j)
        {
            if(pat[i][j] != vr[i][j])
            {
                return false;
            }
        }
    }
    return true;
}


int checkRot()
{
    char tempR90[N][N];
    char tempR180[N][N];
    char tempR270[N][N];
    for(int i = 0 ; i < N;++i)
    {
        for(int j = 0 ; j < N;++j)
        {
            tempR90[i][j] = r[N-j-1][i];
        }
    }


    for(int i = 0 ; i < N;++i)
    {
        for(int j = 0 ; j < N;++j)
        {
            tempR180[i][j] = tempR90[N-j-1][i];
        }
    }

    for(int i = 0 ; i < N;++i)
    {
        for(int j = 0 ; j < N;++j)
        {
            tempR270[i][j] = tempR180[N-j-1][i];
        }

    }
    int status = 1;
    for(int i = 0 ; i < N;++i)
    {
        for(int j = 0 ; j<N;++j)
        {
            if(pat[i][j] != tempR90[i][j])
            {
                status = 0;
            }
        }
    }
    if(status)
    {
        return 90;
    }
    status = 1;
    for(int i = 0 ; i < N;++i)
    {
        for(int j = 0 ; j<N;++j)
        {
            if(pat[i][j] != tempR180[i][j])
            {
                status = 0;
            }
        }
    }
    if(status)
    {
        return 180;
    }

    status = 1;
    for(int i = 0 ; i < N;++i)
    {
        for(int j = 0 ; j<N;++j)
        {
            if(pat[i][j] != tempR270[i][j])
            {
                status = 0;
            }
        }
    }
    if(status)
    {
        return 270;
    }
    return 0;
}

int checkVRot()
{
    char tempR90[N][N];
    char tempR180[N][N];
    char tempR270[N][N];
    for(int i = 0 ; i < N;++i)
    {
        for(int j = 0 ; j < N;++j)
        {
            tempR90[i][j] = vr[N-j-1][i];
        }
    }

    for(int i = 0 ; i < N;++i)
    {
        for(int j = 0 ; j < N;++j)
        {
            tempR180[i][j] = tempR90[N-j-1][i];
        }
    }

    for(int i = 0 ; i < N;++i)
    {
        for(int j = 0 ; j < N;++j)
        {
            tempR270[i][j] = tempR180[N-j-1][i];
        }

    }
    int status = 1;
    for(int i = 0 ; i < N;++i)
    {
        for(int j = 0 ; j<N;++j)
        {
            if(pat[i][j] != tempR90[i][j])
            {
                status = 0;
            }
        }
    }
    if(status)
    {
        return 90;
    }
    status = 1;
    for(int i = 0 ; i < N;++i)
    {
        for(int j = 0 ; j<N;++j)
        {
            if(pat[i][j] != tempR180[i][j])
            {
                status = 0;
            }
        }
    }
    if(status)
    {
        return 180;
    }

    status = 1;
    for(int i = 0 ; i < N;++i)
    {
        for(int j = 0 ; j<N;++j)
        {
            if(pat[i][j] != tempR270[i][j])
            {
                status = 0;
            }
        }
    }
    if(status)
    {
        return 270;
    }
    return 0;
}



int main()
{
    int test = 1;
    while(cin >> N)
    {
        string s;
        getchar();
        for(int i = 0 ; i < N;++i)
        {
            getline(cin,s);
            for(int j = 0 ; j < N;++j)
            {
                r[i][j] = s[j];
            }
            for(int j = N+1,k=0;j <= 2*N;++j,++k)
            {
                pat[i][k] = s[j];
            }
        }


        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                vr[j][i] = r[N-j-1][i];
            }
        }
        int rats;

        if(checkOri())
        {
            cout << "Pattern " << test++ << " was preserved.\n";
        }
        else if(rats = checkRot())
        {
            cout << "Pattern " << test++ << " was rotated " << rats << " degrees.\n";
        }
        else if(checkV())
        {
            cout << "Pattern " << test++ << " was reflected vertically.\n";
        }
        else if(rats = checkVRot())
        {
            cout << "Pattern " << test++ << " was reflected vertically and rotated " << rats << " degrees.\n";
        }
        else
        {
            cout << "Pattern " << test++ << " was improperly transformed.\n";
        }


    }

    return 0;
}

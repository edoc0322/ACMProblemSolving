#include <iostream>

using namespace std;
int N;
int ticket;
int money[4];
int ticketball[1000][5][5];
int ans;
int ballHash[101];
int ballIndex[101];
void calculateMoney(int m)
{
    ans = 0;
    int visit[5][5];
    for(int i = 0 ; i < 5;++i)
    {
        for(int j = 0 ; j < 5;++j)
        {
            visit[i][j] = 0;
        }
    }
    for(int i = 0 ; i < 5;++i)
    {
        for(int j = 0 ; j < 5;++j)
        {
            visit[i][j] = ballHash[ticketball[m][i][j]];
        }
    }
    if(visit[0][0]
       && ballIndex[ticketball[m][0][0]] < 35
       && visit[0][4]
       && ballIndex[ticketball[m][0][4]] < 35
       && visit[4][0]
       && ballIndex[ticketball[m][4][0]] < 35
       && visit[4][4]
       && ballIndex[ticketball[m][4][4]] < 35
       )
    {
        ans += money[0];
    }

    int temp = 0;
    for(int i = 0 ; i < 5;++i)
    {
        if(ballIndex[ticketball[m][2][i]] >= 40) break;
        temp+= visit[2][i];
    }
    if(temp == 5)
    {
        ans += money[1];
    }

    temp = 0;
    for(int i = 0 ; i < 5;++i)
    {
        if(ballIndex[ticketball[m][i][i]] >= 45) break;
        temp += visit[i][i];
    }
    for(int i = 0 ; i < 5;++i)
    {
        if(i != 2)
        {
            if(ballIndex[ticketball[m][i][5-i-1]] >= 45) break;
            temp += visit[i][5-i-1];
        }
    }
    if(temp == 9)
    {
        ans+= money[2];
    }

    temp = 0;
    for(int i = 0 ; i <5;++i)
    {
        for(int j = 0 ; j < 5;++j)
        {

            temp+= visit[i][j];
        }
    }
    if(temp == 25)
    {
        ans+= money[3];
    }
    cout << ans <<endl;
}
int main()
{
    int T;
    cin >> T;
    for(int t = 1 ; t <= T;++t)
    {
        if(t > 1)
        {
            cout << endl;
        }

        cin >> N;
        cin >> ticket;
        int ball[N];

        for(int i = 1 ; i <= 75;++i)
        {
            ballHash[i] = 0;
            ballIndex[i] = 0;
        }
        for(int i = 0 ; i < N;++i)
        {
            cin >> ball[i];
            ballHash[ball[i]] = 1;
            ballIndex[ball[i]] = i;
        }
        for(int i = 0 ; i < 4;++i)
        {
            cin >> money[i];
        }
        cout << "Case " << t << ":" <<endl;
        for(int i = 0 ; i < ticket;++i)
        {
            for(int j = 0 ; j < 5;++j)
            {
                for(int k = 0 ; k < 5;++k)
                {
                    cin >> ticketball[i][j][k];
                }
            }
            calculateMoney(i);
        }

    }
    return 0;
}

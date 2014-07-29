#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <algorithm>

using namespace std;

int con[101][10];
int sol[101][10];

struct ranks
{
    int team,pn,time;
};

bool cmp(ranks r1, ranks r2)
{
    if(r1.pn > r2.pn)
    {
        return true;
    }
    else if(r1.pn == r2.pn)
    {
        if(r1.time < r2.time)
        {
            return true;
        }
        else if(r1.time == r2.time)
        {
            if(r1.team < r2.team)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int main()
{
    int test;
    cin >> test;
    getchar();
    getchar();
    int counts = 0;
    char line[10000];
    while(test--)
    {


        ranks rk[101];
        for(int i= 1 ; i <= 100;++i)
        {
            for(int j = 1 ; j <= 9;++j)
            {
                con[i][j] = 0;
                sol[i][j] = -1;
            }
        }
        while(gets(line) && *line)
        {
            stringstream ss(line);
            int team;
            ss >> team;

            int p ;
            ss >> p;

            int time;
            ss >> time;

            char e;
            ss >> e;

            //cout <<"char " <<  e << endl;
            if(e == 'C')
            {
                if(sol[team][p] != 1)
                {
                    sol[team][p] = 1;
                    con[team][p] += time;
                }
            }
            else if(e == 'I')
            {
                if(sol[team][p] != 1)
                {
                    sol[team][p] = 0;
                    con[team][p] += 20;
                }
            }
            else
            {
                if(sol[team][p] == -1)
                {
                    sol[team][p] = 0;
                }
            }
        }

        if(counts > 0)
        {
            cout << endl;
        }
        counts++;
        int rn = 0;
        for(int i = 1 ; i<= 100;++i)
        {
            int sols = 0;
            int times = 0;
            int status = 0;
            for(int j = 1 ; j <= 9;++j)
            {
                if(sol[i][j] == 1)
                {
                    sols++;
                    times+= con[i][j];
                    status = 1;
                }
                else if(sol[i][j] == 0)
                {
                    status = 1;
                }
            }
            if(status == 1)
            {
                rk[rn].team = i;
                rk[rn].pn = sols;
                rk[rn].time = times;
                rn++;

                //cout << i << " " << sols << " " << times <<endl;
            }
        }

        sort(rk,rk+rn,cmp);
        for(int i = 0 ; i < rn;++i)
        {
            cout << rk[i].team << " " << rk[i].pn << " " << rk[i].time <<endl;
        }
    }
    return 0;
}

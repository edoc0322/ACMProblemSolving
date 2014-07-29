#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int press[200][11];
int main()
{

    press['c'][2] = 1;
    press['c'][3] = 1;
    press['c'][4] = 1;
    press['c'][7] = 1;
    press['c'][8] = 1;
    press['c'][9] = 1;
    press['c'][10] = 1;

    press['d'][2] = 1;
    press['d'][3] = 1;
    press['d'][4] = 1;
    press['d'][7] = 1;
    press['d'][8] = 1;
    press['d'][9] = 1;


    press['e'][2] = 1;
    press['e'][3] = 1;
    press['e'][4] = 1;
    press['e'][7] = 1;
    press['e'][8] = 1;

    press['f'][2] = 1;
    press['f'][3] = 1;
    press['f'][4] = 1;
    press['f'][7] = 1;

    press['g'][2] = 1;
    press['g'][3] = 1;
    press['g'][4] = 1;

    press['a'][2] = 1;
    press['a'][3] = 1;

    press['b'][2] = 1;

    press['C'][3] = 1;

    press['D'][1] = 1;
    press['D'][2] = 1;
    press['D'][3] = 1;
    press['D'][4] = 1;
    press['D'][7] = 1;
    press['D'][8] = 1;
    press['D'][9] = 1;

    press['E'][1] = 1;
    press['E'][2] = 1;
    press['E'][3] = 1;
    press['E'][4] = 1;
    press['E'][7] = 1;
    press['E'][8] = 1;

    press['F'][1] = 1;
    press['F'][2] = 1;
    press['F'][3] = 1;
    press['F'][4] = 1;
    press['F'][7] = 1;

    press['G'][1] = 1;
    press['G'][2] = 1;
    press['G'][3] = 1;
    press['G'][4] = 1;

    press['A'][1] = 1;
    press['A'][2] = 1;
    press['A'][3] = 1;

    press['B'][1] = 1;
    press['B'][2] = 1;

    int test;
    cin >> test;
    getchar();
    while(test--)
    {
        string s;
        getline(cin,s);
        int fin[11];
        int counts[11];
        for(int i = 1 ; i <= 10;++i)
        {
            counts[i] = 0;
            fin[i] = 0;
        }

        for(int i = 0 ; i < s.length();++i)
        {
            for(int j = 1 ; j <= 10 ;++j)
            {
                if(press[s[i]][j] == 1)
                {
                    if(fin[j] == 0)
                    {
                        fin[j] = 1;
                        counts[j]++;
                    }
                    else
                    {

                    }
                }
                else
                {
                    if(fin[j] == 0)
                    {

                    }
                    else
                    {
                        fin[j] = 0;
                    }
                }
            }
        }
        for(int j = 1 ; j <= 10;++j)
        {
            if(j > 1)
            {
                cout << " " << counts[j];
            }
            else
            {
                cout << counts[j];
            }
        }
        cout <<endl;
    }



    return 0;
}

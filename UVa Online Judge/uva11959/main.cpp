#include <iostream>

#include <string>
using namespace std;

struct dice
{
    int T,B,L,R,F,K;
};

dice d1;
dice d2;

void rotateTopToLeft()
{
    int temp = d1.T;
    d1.T = d1.R;
    d1.R = d1.B;
    d1.B = d1.L;
    d1.L = temp;
}
void rotateFrontToUp()
{
    int temp = d1.T;
    d1.T = d1.F;
    d1.F = d1.B;
    d1.B = d1.K;
    d1.K = temp;
}

void rotateFrontToLeft()
{
    int temp = d1.F;
    d1.F = d1.R;
    d1.R = d1.K;
    d1.K = d1.L;
    d1.L = temp;
}

bool check()
{
    if(d1.B == d2.B && d1.F == d2.F && d1.K == d2.K && d1.L == d2.L && d1.R == d2.R && d1.T == d2.T)
    {
        return true;
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
    while(test--)
    {
        string s1,s2;
        cin >> s1 >> s2;

        d1.T = s1[0]-'0';
        d1.B = s1[1]-'0';
        d1.F = s1[2]-'0';
        d1.L = s1[3]-'0';
        d1.K = s1[4]-'0';
        d1.R = s1[5]-'0';

        d2.T = s2[0]-'0';
        d2.B = s2[1]-'0';
        d2.F = s2[2]-'0';
        d2.L = s2[3]-'0';
        d2.K = s2[4]-'0';
        d2.R = s2[5]-'0';
        int status = 0;
        if(status == 0)
        {
            for(int i = 0 ; i < 4 ; ++i)
            {
                rotateTopToLeft();
                if(check())
                {
                    status = 1;
                    break;
                }
            }
        }

        rotateFrontToUp();

        if(status == 0)
        {
            for(int i = 0 ; i < 4 ; ++i)
            {
                rotateFrontToLeft();
                if(check())
                {
                    status = 1;
                    break;
                }
            }
        }

        rotateFrontToUp();

        if(status == 0)
        {
            for(int i = 0 ; i < 4 ; ++i)
            {
                rotateTopToLeft();
                if(check())
                {
                    status = 1;
                    break;
                }
            }
        }

        rotateFrontToUp();

        if(status == 0)
        {
            for(int i = 0 ; i < 4 ; ++i)
            {
                rotateFrontToLeft();
                if(check())
                {
                    status = 1;
                    break;
                }
            }
        }

        rotateFrontToUp();
        rotateFrontToLeft();

        if(status == 0)
        {
            for(int i = 0 ; i < 4 ; ++i)
            {
                rotateFrontToUp();
                if(check())
                {
                    status = 1;
                    break;
                }
            }
        }

        rotateFrontToLeft();
        rotateFrontToLeft();
        if(status == 0)
        {
            for(int i = 0 ; i < 4 ; ++i)
            {
                rotateFrontToUp();
                if(check())
                {
                    status = 1;
                    break;
                }
            }
        }
        if(status)
        {
            cout << "Equal" <<endl;
        }
        else
        {
            cout << "Not Equal" <<endl;
        }
    }
    return 0;
}

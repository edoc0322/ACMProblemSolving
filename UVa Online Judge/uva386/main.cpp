#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d;
    for(a = 1;a<=200;++a)
    {
        for(b = 2;b<a;++b)
        {
            for(c = b+1;c<a;++c)
            {
                for(d = c+1;d<a;++d)
                {
                    if(a*a*a == b*b*b +c*c*c +d*d*d)
                    {
                        cout << "Cube = " << a <<", Triple = ("<<b<<","<<c<<","<<d<<")\n";
                        break;
                    }
                }
            }
        }
    }
    return 0;
}

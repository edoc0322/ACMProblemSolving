#include <iostream>
#include <string>
using namespace std;
int N,L,C;
int main()
{
    while(cin >> N && cin >> L && cin >> C)
    {
        string s = "";
        string temp;
        for(int i = 0 ; i < N;++i)
        {
            cin >> temp;
            if(i == 0)
            {
                s = temp;
            }
            else
            {
                s += " " + temp;
            }
        }
        int pages = 0;
        int counts = 0;
        while(s.length() > 0)
        {
            //cout << "curs = " << s <<endl;
            if(s.length() > C)
            {
                if(s[C-1] == ' ')
                {
                    s = s.substr(C);
                    counts++;
                    if(counts == L)
                    {
                        pages++;
                        counts = 0;
                    }
                }
                else
                {
                    if(s[C] == ' ')
                    {
                        s = s.substr(C+1);
                        counts++;
                        if(counts == L)
                        {
                            pages++;
                            counts = 0;
                        }
                    }
                    else
                    {
                        int j;
                        for(j = C-1;j>=0;--j)
                        {
                            if(s[j] == ' ')
                            {
                                s = s.substr(j+1);
                                counts++;
                                if(counts == L)
                                {
                                    pages++;
                                    counts = 0;
                                }
                                break;
                            }
                        }
                        if(j == -1)
                        {
                            s = s.substr(C);
                            counts++;
                            if(counts == L)
                            {
                                pages++;
                                counts = 0;
                            }
                        }
                    }

                }
                //cout << "s = " << s <<endl;
            }
            else
            {
                counts++;
                break;
            }
        }
        if(counts > 0) cout << pages+1 <<endl;
        else cout << pages <<endl;
    }
    return 0;
}

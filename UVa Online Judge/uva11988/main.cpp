#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        deque<string> que;
        int fronts = 1;
        int len = s.length();
        string s1 = "",s2;
        for(int i = 0 ; i < len;++i)
        {
            if(s[i] == '[')
            {
                if(fronts == 1)
                {
                    que.push_front(s1);
                }
                else
                {
                    que.push_back(s1);
                }

                s1 = "";
                fronts = 1;

            }
            else if(s[i] == ']')
            {
                if(fronts == 1)
                {
                    que.push_front(s1);
                }
                else
                {
                    que.push_back(s1);
                }
                s1 = "";
                fronts = 0;
            }
            else
            {
                s1 += s[i];
            }
        }
        if(fronts == 1)
        {
            que.push_front(s1);
        }
        else
        {
            que.push_back(s1);
        }
        for(int i = 0 ; i < que.size();++i)
        {
            cout << que[i];
        }
        cout <<endl;

    }
    return 0;
}

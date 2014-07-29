#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string s;
    while(N--)
    {
        cin >> s;
        int w1[5];
        int w2[5];
        int w3[5];
        for(int i = 0 ; i < 5;++i)
        {
            w1[i] = w2[i] = w3[i] = 0;
        }
        for(int i = 0 ;i < s.length();++i)
        {
            if(s[i] == 'o' && w1[0] == 0)
            {
                w1[0]++;
            }
            else if(s[i] == 'n' && w1[1] == 0)
            {
                w1[1]++;
            }
            else if(s[i] == 'e' && w1[2] == 0)
            {
                w1[2]++;
            }

            if(s[i] == 't' && w2[0] == 0)
            {
                w2[0]++;
            }
            else if(s[i] == 'w' && w2[1] == 0)
            {
                w2[1]++;
            }
            else if(s[i] == 'o' && w2[2] == 0)
            {
                w2[2]++;
            }

            if(s[i] == 't' && w3[0] == 0)
            {
                w3[0]++;
            }
            else if(s[i] == 'h' && w3[1] == 0)
            {
                w3[1]++;
            }
            else if(s[i] == 'r' && w3[2] == 0)
            {
                w3[2]++;
            }
            else if(s[i] == 'e' && w3[3] <= 1)
            {
                w3[3]++;
                if(w3[3] == 2)
                {
                    w3[3]-=1;
                }
            }
        }

        int ans[3] = {0,0,0};
        for(int i = 0 ; i < 4;++i)
        {
            ans[0]+=w1[i];
            ans[1]+=w2[i];
            ans[2]+=w3[i];
        }

        int maxI = -1;
        int index = 0;
        for(int i = 0 ; i < 3;++i)
        {
            if(ans[i] > maxI)
            {
                maxI = ans[i];
                index = i+1;
            }
        }
        cout << index<<endl;


    }
    return 0;
}

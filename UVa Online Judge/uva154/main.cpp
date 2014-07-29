#include <iostream>
#include <string>
using namespace std;
string ans[101];

int main()
{
    int over = 0;
    while(1)
    {
        int count = 0;
        string temp;
        int ans2 = 0;
        int com[150];
        int minI = 99999;
        int minI2 = -1;
        while(getline(cin,temp))
        {
            if(temp[0] == 'e')
            {
                for(int i = 0 ; i < count;++i)
                {
                    com[ans[i][2]] = ans[i][0];
                    com[ans[i][6]] = ans[i][4];
                    com[ans[i][10]] = ans[i][8];
                    com[ans[i][14]] = ans[i][12];
                    com[ans[i][18]] = ans[i][16];
                    int sums = 0;
                    for(int j = 0 ; j < count;++j)
                    {
                        if(i != j)
                        {
                            for(int k = 2 ; k <= 18 ;k+=4)
                            {
                                if(com[ans[j][k]] != ans[j][k-2])
                                {
                                    sums++;
                                }
                            }
                        }
                    }
                    if(sums < minI)
                    {
                        minI = sums;
                        minI2 = i;
                    }
                }
                cout << minI2+1<<endl;
                break;
            }
            else if(temp[0] == '#')
            {
                over = 1;
                break;
            }
            ans[count++] = temp;
        }
        if(over) break;

    }
    return 0;
}

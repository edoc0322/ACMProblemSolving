#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;

map<string,int> maps;
int main()
{
    string s;
    int sums = 0;
    while(getline(cin,s))
    {
        if(s == "****END_OF_INPUT****")
        {
            break;
        }
        else if(s == "****END_OF_TEXT****")
        {

            map<string,int>::iterator iter;
            double ans = 0;
            for(iter = maps.begin();iter != maps.end();++iter)
            {
                ans += (double)iter->second * (log10((double) sums) - log10((double)iter->second));
            }
            ans /= sums;
            double ans2;
            ans2 = ans / log10((double)sums) * 100;

            cout << sums ;
            cout << " " << fixed << setprecision(1) << ans;
            cout << " " << fixed << setprecision(0) <<  ans2 <<endl;

            sums = 0;
            maps.clear();
        }
        else
        {
            string sep = ",.:;!?\"()\n\t ";
            int start = s.find_first_not_of(sep);
            int end;
            while(start != string::npos)
            {
                end = s.find_first_of(sep,start + 1);
                if(end == string::npos)
                {
                    end = s.length();
                }
                string cutS =  s.substr(start,end-start);
                for(int j = 0 ; j < cutS.length();++j)
                {
                    if(cutS[j] >= 'A' && cutS[j] <= 'Z')
                    {
                        cutS[j] = cutS[j]- 'A' + 'a';
                    }
                }
                maps[cutS]++;
                sums++;
                start = s.find_first_not_of(sep,end+1);
            }
        }
    }
    return 0;
}

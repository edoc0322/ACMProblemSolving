#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;



int main()
{
    char s1[1001];
    char s2[1001];
    while( (cin.getline(s1,1001) ) && (cin.getline(s2,1001)))
    {
        map<char,int> m1,m2;
        for(int i = 0 ; i < strlen(s1);++i)
        {
            m1[s1[i]]++;
        }

        for(int i = 0 ; i < strlen(s2);++i)
        {
            m2[s2[i]]++;
        }

        char temp[1000];
        strcpy(temp,"");
        for(int i = 'a' ; i <= 'z';++i)
        {
            int minI = min(m1[(char) i] , m2[(char) i]);
            //cout << i << " " << minI << endl;;
            for(int j = 0 ; j < minI;++j)
            {
                char temp2[2];
                temp2[0] = (char) i;
                temp2[1] = '\0';
                strcat(temp,temp2);
            }
        }
        strcat(temp,"\0");
        cout << temp <<endl;

    }

    return 0;
}

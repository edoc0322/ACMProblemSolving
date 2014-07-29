#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int ok = 0;
    string s2 = "";
    while(getline(cin,s))
    {
        if(s[0] == '_' && ok ==0)
        {
            ok = 1;
        }
        else if(s[0] == '_' && ok==1)
        {
            cout <<s2;;
            break;
        }
        else
        {
            int sum = 0;
            if(s[1]=='o')
            {
                sum += 128;
            }
            if(s[2]=='o')
            {
                sum+=64;
            }
            if(s[3]=='o')
            {
                sum+=32;
            }
            if(s[4]=='o')
            {
                sum+=16;
            }
            if(s[5]=='o')
            {
                sum+=8;
            }
            if(s[7]=='o')
            {
                sum+=4;
            }
            if(s[8]=='o')
            {
                sum+=2;
            }
            if(s[9]=='o')
            {
                sum+=1;
            }
            char temp[2];
            temp[0] = (char) sum;
            temp[1] = '\0';
            s2 += string(temp);
            //cout <<(char)sum;
        }
    }
    return 0;
}

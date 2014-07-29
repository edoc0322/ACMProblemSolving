#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <cctype>
using namespace std;

int main()
{
    char s[205];
    int i;
    char *temp;
    set<string> ans;
    set<string>::iterator iter;
    while(cin.getline(s,205))
    {
        if(*s)
        {
            temp = strtok(s," ");
            while(temp != NULL)
            {
                //cout << temp << endl;
                string s1;
                s1.resize(205);
                int count = 0;
                int start = 0;
                for(i = 0 ; i < strlen(temp); ++i)
                {
                    if(isalpha(temp[i]))
                    {
                        s1[count++] = tolower(temp[i]);
                    }
                    else
                    {

                        if(count > 0)
                        {
                            s1[count] = '\0';
                            s1 = s1.substr(0,count);
                            ans.insert(s1);
                            s1.resize(205);
                            count = 0;
                        }
                        /*
                        if(i-start > 0)
                        {
                            s1 = s1.substr(0,i-start);
                            start = i+1;

                            //cout << i << " and start "<<start <<endl;
                            cout << s1 << " is the first s1\n";
                            if(count != 0)
                            {

                            }


                        }
                        */

                    }
                }
                if(count > 0)
                {
                    s1[count] = '\0';
                    s1 = s1.substr(0,count);
                    ans.insert(s1);
                    s1.resize(205);
                    count = 0;
                }




                temp = strtok(NULL," ");
            }
        }
    }
    for(iter = ans.begin(); iter != ans.end(); ++iter)
    {
        cout << *iter <<endl;
    }

    return 0;
}

#include <iostream>
#include <set>
#include <string>
using namespace std;

int number[300];
int main()
{
    string s;
    while(cin >> s)
    {
        if(s == "0") break;
        number['p'] = number['r'] = number['s'] = number['q'] = number['t'] = 0;
        number['0'] = 0;
        number['1'] = 1;
        int status = 1;
        for(int i = 0 ; i < 2 ;++i)
        {
            number['p'] = i;
            for(int j = 0 ; j < 2;++j)
            {
                number['q'] = j;
                for(int k = 0 ; k < 2 ; ++k)
                {
                    number['r'] = k;
                    for(int m = 0 ; m < 2 ;++m)
                    {
                        number['s'] = m;
                        for(int n = 0 ; n < 2 ;++n)
                        {
                            number['t'] = n;
                            string s2 = s;
                            while(s2 != "1" && s2 != "0")
                            {
                                int index = 0;
                                char command;
                                for(index = s2.length()-1;index >= 0 ;--index)
                                {
                                    if(s2[index] == 'C' || s2[index] == 'A' || s2[index] == 'N' || s2[index] == 'E' || s2[index] == 'K')
                                    {
                                        command = s2[index];
                                        break;
                                    }
                                }
                                //cout << index <<endl;
                                if(index >= 0)
                                {
                                    if(command == 'N')
                                    {
                                        int ans = !number[s2[index+1]];
                                        string tempS = "";
                                        tempS += (char)(ans+'0');
                                        s2.replace(index,2,tempS);
                                    }
                                    else if(command  == 'E')
                                    {
                                        int ans = !(number[s2[index+1]]^number[s2[index+2]]);
                                        string tempS = "";
                                        tempS += (char)(ans+'0');
                                        s2.replace(index,3,tempS);
                                    }
                                    else if(command == 'C')
                                    {
                                        int ans;
                                        if(number[s2[index+1]] == 1 && number[s2[index+2]] == 0)
                                        {
                                            ans = 0;
                                        }
                                        else
                                        {
                                            ans = 1;
                                        }
                                        string tempS = "";
                                        tempS += (char)(ans+'0');
                                        s2.replace(index,3,tempS);
                                    }
                                    else if(command == 'A')
                                    {
                                        int ans = number[s2[index+1]] | number[s2[index+2]];
                                        string tempS = "";
                                        tempS += (char)(ans+'0');
                                        s2.replace(index,3,tempS);
                                    }
                                    else if(command == 'K')
                                    {
                                        int ans = number[s2[index+1]] & number[s2[index+2]];
                                        string tempS = "";
                                        tempS += (char)(ans+'0');
                                        s2.replace(index,3,tempS);
                                    }
                                }
                                else
                                {
                                    int ans = number[s2[0]] ;
                                    string tempS = "";
                                    tempS += (char)(ans+'0');
                                    s2.replace(0,1,tempS);
                                }
                                //cout << "current s2 = " << s2 <<endl;

                            }
                            if(s2 == "0")
                            {
                                status = 0;
                                break;
                            }
                        }
                        if(status == 0) break;
                    }
                    if(status == 0) break;
                }
                if(status == 0) break;
            }
            if(status == 0) break;
        }
        if(status)
        {
            cout << "tautology" <<endl;
        }
        else
        {
            cout << "not" <<endl;
        }
    }

    return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[21];
    char keyword[300];
    int staword[300];
    keyword[(int)'A'] = 'A';
    keyword[(int)'B'] = '0';
    keyword[(int)'C'] = '0';
    keyword[(int)'D'] = '0';
    keyword[(int)'E'] = '3';
    keyword[(int)'F'] = '0';
    keyword[(int)'G'] = '0';
    keyword[(int)'H'] = 'H';
    keyword[(int)'I'] = 'I';
    keyword[(int)'J'] = 'L';
    keyword[(int)'K'] = '0';
    keyword[(int)'L'] = 'J';
    keyword[(int)'M'] = 'M';
    keyword[(int)'N'] = '0';
    keyword[(int)'O'] = 'O';
    keyword[(int)'P'] = '0';
    keyword[(int)'Q'] = '0';
    keyword[(int)'R'] = '0';
    keyword[(int)'S'] = '2';
    keyword[(int)'T'] = 'T';
    keyword[(int)'U'] = 'U';
    keyword[(int)'V'] = 'V';
    keyword[(int)'W'] = 'W';
    keyword[(int)'X'] = 'X';
    keyword[(int)'Y'] = 'Y';
    keyword[(int)'Z'] = '5';
    keyword[(int)'1'] = '1';
    keyword[(int)'2'] = 'S';
    keyword[(int)'3'] = 'E';
    keyword[(int)'4'] = '0';
    keyword[(int)'5'] = 'Z';
    keyword[(int)'6'] = '0';
    keyword[(int)'7'] = '0';
    keyword[(int)'8'] = '8';
    keyword[(int)'9'] = '0';


    /* 1 is real mirror
    2 is fack mirror
    -1 is no mirror
    */
    staword[(int)'A'] = 1;
    staword[(int)'B'] = -1;
    staword[(int)'C'] = -1;
    staword[(int)'D'] = -1;
    staword[(int)'E'] = 2;
    staword[(int)'F'] = -1;
    staword[(int)'G'] = -1;
    staword[(int)'H'] = 1;
    staword[(int)'I'] = 1;
    staword[(int)'J'] = 2;
    staword[(int)'K'] = -1;
    staword[(int)'L'] = 2;
    staword[(int)'M'] = 1;
    staword[(int)'N'] = -1;
    staword[(int)'O'] = 1;
    staword[(int)'P'] = -1;
    staword[(int)'Q'] = -1;
    staword[(int)'R'] = -1;
    staword[(int)'S'] = 2;
    staword[(int)'T'] =  1;
    staword[(int)'U'] = 1;
    staword[(int)'V'] = 1;
    staword[(int)'W'] = 1;
    staword[(int)'X'] = 1;
    staword[(int)'Y'] = 1;
    staword[(int)'Z'] = 2;
    staword[(int)'1'] = 1;
    staword[(int)'2'] = 2;
    staword[(int)'3'] = 2;
    staword[(int)'4'] = -1;
    staword[(int)'5'] = 2;
    staword[(int)'6'] = -1;
    staword[(int)'7'] = -1;
    staword[(int)'8'] =  1;
    staword[(int)'9'] = -1;

    while(cin.getline(s,21))
    {
        int status = -1;
        int h,le;
        le = strlen(s);
        if(le == 1)
        {
            if(staword[(int)s[0]] == 1){
                cout << s << " -- is a mirrored palindrome.\n\n";
            }
            else{
                cout << s << " -- is a regular palindrome.\n\n";
            }
        }
        else if(le %2)
        {
            h = le / 2;
            for(int i = 0 ; i < h; ++i)
            {
                if(s[i] == s[le-i-1])
                {
                    if(staword[(int)s[i]] == -1)
                    {
                            status = 1;

                    }
                    else if(staword[(int)s[i]] == 1)
                    {
                        if(status != 1 && status != 2)
                        {
                            status = 3;
                        }
                    }
                    else
                    {
                        if(status == 3 || status == -1)
                        {
                            status = 1;
                        }
                    }
                }
                else if(keyword[(int)s[i]] == s[le-i-1])
                {
                    if(status == 1)
                    {
                        status = 0;
                        break;

                    }
                    else if(status != 2)
                    {
                        status = 2;
                    }
                }
                else
                {
                    status = 0;
                    break;
                }
            }
            if(status == 0)
            {
                cout << s << " -- is not a palindrome.\n\n";
            }
            else
            {

                if(staword[(int)s[h]] == 2 || staword[(int)s[h]] == -1)
                {
                    status = 1;
                }

                if(status == 1)
                {
                    cout << s << " -- is a regular palindrome.\n\n";
                }
                else if(status == 2)
                {
                    cout << s << " -- is a mirrored string.\n\n";
                }
                else if(status == 3)
                {
                    cout << s << " -- is a mirrored palindrome.\n\n";
                }

            }
        }
        else
        {
            h = le / 2;
            for(int i = 0 ; i < h; ++i)
            {
                if(s[i] == s[le-i-1])
                {
                    if(staword[(int)s[i]] == -1)
                    {
                        status = 1;

                    }
                    else if(staword[(int)s[i]] == 1)
                    {
                        if(status != 1 && status != 2)
                        {
                            status = 3;
                        }

                    }
                    else
                    {
                        if(status == 3 || status == -1)
                        {
                            status = 1;
                        }
                    }
                }
                else if(keyword[(int)s[i]] == s[le-i-1])
                {
                    if(status == 1)
                    {
                        status = 0;
                        break;

                    }
                    else if(status != 2)
                    {
                        status = 2;
                    }
                }
                else
                {
                    status = 0;
                    break;
                }
            }
            if(status == 0)
            {
                cout << s << " -- is not a palindrome.\n\n";
            }
            else
            {

                if(status == 1)
                {
                    cout << s << " -- is a regular palindrome.\n\n";
                }
                else if(status == 2)
                {
                    cout << s << " -- is a mirrored string.\n\n";
                }
                else if(status == 3)
                {
                    cout << s << " -- is a mirrored palindrome.\n\n";
                }
            }
        }
    }
    return 0;
}

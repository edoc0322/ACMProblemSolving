#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;


int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,-1,-1,-1,0,1,1,1};
int main()
{
    int testcase;
    cin >> testcase;
    int m,n;
    int k;
    int status ;
    string s[20];
    string map1[50];
    int ansx,ansy;
    int sl;
    while(testcase > 0)
    {
        getchar();
        cin >> m;
        cin >> n;
        for(int i = 0 ; i < m; ++i)
        {
            cin >> map1[i];
        }
        cin >> k;
        for(int i = 0 ; i < k ; ++i)
        {
            cin >> s[i];
        }
        int curx,cury;
        for(int i = 0 ; i  < k ; ++i)
        {
            status = 0;
            for(int j = 0 ; j < m; ++j)
            {
                for(int p = 0 ; p < n; ++p)
                {

                    //cout << tolower(s[i][0]) << " " << tolower(map1[j][p]) <<endl;
                    if(tolower(s[i][0])==tolower(map1[j][p]))
                    {

                        for(int r = 0 ; r< 8; ++r)
                        {
                            curx = p;
                            cury = j;
                            for(sl = 0 ; sl < s[i].length()-1; ++sl)
                            {
                                if(curx+dx[r]>=0 && curx+dx[r]<n && cury + dy[r]<m&& cury+ dy[r]>=0)
                                {
                                    curx += dx[r];
                                    cury += dy[r];
                                }
                                if(tolower(map1[cury][curx]) != tolower(s[i][sl+1]))
                                {
                                    break;
                                }
                            }
                            if(sl == s[i].length()-1)
                            {
                                ansx = j;
                                ansy = p;
                                status = 1;
                                break;
                            }
                        }
                    }
                    if(status){
                        break;
                    }
                }
                if(status)
                    break;
            }
            cout << (ansx+1) << " " << (ansy+1)<<endl;;

        }
        if(testcase > 1){
            cout << endl;
        }

        testcase--;
    }
    return 0;
}

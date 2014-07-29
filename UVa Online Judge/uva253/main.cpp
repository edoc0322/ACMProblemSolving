#include <iostream>
#include <string>
using namespace std;


int rotateA[6][6] = {{1,2,3,4,5,6},{2,6,3,4,1,5},{3,2,6,1,5,4},{4,2,1,6,5,3}, {5,4,1,6,3,2},{6,2,4,3,5,1} };
int rotateSub[4][4] = {{2,3,4,5}, {4,2,5,3} , {5,4,3,2} , {3,5,2,4} };
int main()
{
    string s;
    while(cin >>s)
    {
        string r,pat;
        r = s.substr(0,6);
        pat = s.substr(6,6);
        int status = 0;
        string rtemp = r;
        string temp2 = rtemp;
        for(int i = 0 ; i < 6;++i)
        {
            temp2 = rtemp;
            for(int j = 0 ; j < 6;++j)
            {
                rtemp[j] = r[rotateA[i][j]-1];
            }
            //cout << i << " " <<rtemp<<endl;
            for(int j = 0 ; j < 4;++j)
            {
                string subs = rtemp.substr(1,4);
                for(int k = 1 ; k <= 4 ; ++k)
                {
                    rtemp[k] = subs[rotateSub[j][k-1]-2];
                }
                /*
                rtemp[1] = subs[3];
                rtemp[2] = subs[0];
                rtemp[3] = subs[1];
                rtemp[4] = subs[2];
                */
                if(rtemp == pat)
                {
                    status = 1;
                    break;
                }

            }
            if(status == 1)
                break;



        }
        if(status == 1)
        {
            cout << "TRUE\n";
        }
        else
        {
            cout << "FALSE\n";
        }
    }

    return 0;
}

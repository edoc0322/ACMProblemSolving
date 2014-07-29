#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int exNum;
string exString[105];
int startTime[105];
int duration[105];
string target[105];
string startS;
string ansS;
int status = 0;
void backtrack(string s,int time,int depth)
{
    int status = 0;
    for(int i = 0 ; i < exNum;++i)
    {
        if(exString[i] ==s)

        {
            if(time >= startTime[i] && time <= startTime[i]+duration[i])
            {
                if(target[i] != startS)
                {
                    //cout << "hello!"<<endl;
                    backtrack(target[i],time,depth+1);
                    status = 1;
                }
                else
                {
                    ansS = "9999";
                    status = 1;
                    return ;
                }

            }
        }
    }
    if(status == 0)
    {
        ansS = s;
        status = 1;
        return ;
    }

}

int main()
{
    int test;
    cin >> test;
    cout << "CALL FORWARDING OUTPUT" <<endl;
    for(int t = 1 ;t <= test;++t)
    {
        exNum = 0;
        while(cin >> exString[exNum])
        {
            if(exString[exNum] == "0000")break;
            cin >> startTime[exNum];
            cin >> duration[exNum];
            cin >> target[exNum];
            exNum++;
        }
        string inputS;
        int time;
        cout << "SYSTEM " << t <<endl;
        while(cin >> time)
        {
            if(time == 9000)break;
            cin >> inputS;
            startS = inputS;
            status = 0;
            backtrack(inputS,time,0);
            cout << "AT ";
            printf("%.4d ",time);
            cout << "CALL TO " << inputS << " RINGS " << ansS <<endl;

        }
    }
    cout <<"END OF OUTPUT" <<endl;
    return 0;
}

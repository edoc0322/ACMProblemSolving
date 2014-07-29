#include <iostream>
#include <algorithm>
using namespace std;
long long int square[99999];
long long int base[99999];
int sqN = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int dir;
int main()
{
    for(long long int i = 1;i<=99999;i+=2)
    {
        square[sqN] = i*i;
        base[sqN] = i;
        sqN++;
    }
    int N;
    long long int num;

    while(cin >> N && cin >> num && N && num)
    {
        int R,C;
        int position = lower_bound(square,square+sqN,num) - square;
        R = N/2 + 1 + position;
        C = N/2 + 1 + position;
        //cout << R << "    " << C <<endl;
        int status = 0;
        int counts1 = 0;
        int counts2 = 0;
        long long int curNum = square[position];
        //cout << curNum <<endl;
        dir = 1;
        long long int countsTarger =  base[position] - 1;
        long long int countsSteps = curNum - 1;
        while(1)
        {
            if(curNum == num)
            {
                break;
            }
            if(status == 0)
            {
                R += dy[dir];
                C += dx[dir];
                //cout << "cur R C " <<dir << " " << R << " " << C <<" " << countsTarger<<endl;
                counts1++;
                curNum--;
                if(counts1 == countsTarger)
                {
                    dir = (dir + 1)% 4;
                    counts1 = 0;
                    counts2++;
                    if(counts2 == 3)
                    {
                        status = 1;
                        counts2 = 0;
                        countsTarger--;
                    }
                }
            }
            else if(status == 1)
            {
                R += dy[dir];
                C += dx[dir];
                counts1++;
                curNum--;
                //cout << "2 cur R C " << dir << " " << R << " " << C <<" " << countsTarger<<endl;
                if(counts1 == countsTarger)
                {
                    dir = (dir + 1)% 4;
                    counts1 = 0;
                    counts2++;
                    if(counts2 == 2)
                    {
                        counts2 = 0;
                        countsTarger--;
                    }
                }
            }
        }
        cout << "Line = " << R <<", column = " << C << "." <<endl;


    }


    return 0;
}

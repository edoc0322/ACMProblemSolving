#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct light
{
    int status;
    int counts;
    int cycle;
};

int main()
{
    string s;
    int t = 1;
    while(getline(cin,s))
    {
        light sets[11];
        int N = 0;
        int num;
        stringstream ss;
        ss << s;
        while(ss >> num)
        {
            sets[N].status = 1;
            sets[N].cycle = num;
            sets[N].counts = num-5;
            N++;
        }
        int status = 0;
        int ansCount = 0;
        int green = 1;
        for(int i = 0;i <= 3600;++i)
        {
            green = 1;
            for(int j = 0 ; j < N;++j)
            {
                if(sets[j].status != 1)
                {
                    green = 0;
                    if(status == 1 && sets[j].status == 2)
                    {
                        status = 2;
                    }
                }
            }
            if(green == 1 && status == 0)
            {
                //cout << i << endl;
                status = 1;
            }
            else if(green == 1 && status == 2)
            {
                ansCount = i;
                status = 3;
                break;
            }

            for(int j = 0 ; j < N;++j)
            {
                sets[j].counts--;
                if(sets[j].counts == 0)
                {
                    if(sets[j].status == 0)
                    {
                        sets[j].status = 1;
                        sets[j].counts = sets[j].cycle-5;
                    }
                    else if(sets[j].status == 1)
                    {
                        sets[j].status = 2;
                        sets[j].counts = 5;
                    }
                    else
                    {
                        sets[j].status = 0;
                        sets[j].counts = sets[j].cycle;
                    }
                }
            }
        }
        if(status == 3)
        {
            cout << "Set " << t++ << " synchs again at " << ansCount/60 <<
            " minute(s) and " << ansCount % 60 << " second(s) after all turning green." <<endl;
        }
        else
        {
            cout << "Set " << t++ << " is unable to synch after one hour." <<endl;
        }
    }
    return 0;
}

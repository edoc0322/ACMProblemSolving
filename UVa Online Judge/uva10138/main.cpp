#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <iomanip>
#include <map>
#include <cmath>
using namespace std;


struct car{

    string name;
    int time;
    int enterExit;
    int startH;
    int loc;
};
bool cmp(car c1,car c2)
{
    if(c1.name != c2.name)
        return c1.name < c2.name;
    return c1.time < c2.time;
}
int timeBlock[24];
car cars[1000000];
int counts = 0;
int main()
{
    int test1;
    int t = 0;
    cin >> test1;
    getchar();
    while(test1--)
    {
        //cout << "first test = = " << test1 <<endl;

        counts = 0;
        map<string,int> bill;
        for(int i = 0 ;i < 24;++i)
        {
            cin >> timeBlock[i];
        }
        if(t > 0)
        {
            cout << endl;
        }
        getchar();
        string s;
        while(getline(cin,s) && s.length() != 0)
        {
            char temp[10000] ;
            strcpy(temp,s.c_str());
            char name[10000];
            int MM,dd,hh,mm;
            char enter[100];
            int loc;
            sscanf(temp,"%s %d:%d:%d:%d %s %d",name,&MM,&dd,&hh,&mm,enter,&loc);
            cars[counts].name = name;
            cars[counts].time = MM*31*24*60 + dd * 24 * 60 + hh*60 + mm;
            if(enter[1] == 'n')
            {
                cars[counts].enterExit = 0;
            }
            else
            {
                cars[counts].enterExit = 1;
            }

            cars[counts].startH = hh;
            cars[counts].loc = loc;
            //cout << cars[counts].name << " " << cars[counts].time << " " << cars[counts].enterExit <<endl;
            counts++;
        }
        sort(cars,cars+counts,cmp);
        for(int i = 0 ; i < counts;++i)
        {
            int j;
            for(j = i + 1 ;j< counts;++j)
            {
                //cout << cars[i].name << " " << cars[j].name <<endl;
                if(cars[i].name == cars[j].name)
                {
                    //cout << cars[i].enterExit << " " << cars[j].enterExit <<endl;
                    //cout << cars[i].loc << " " << cars[j].loc <<endl;
                    if( (cars[i].enterExit == 0) && (cars[j].enterExit == 1))
                    {
                        //cout << "I am your father!" <<endl;
                        if(bill.find(cars[i].name) == bill.end())
                        {
                            bill[cars[i].name] = 0;
                        }
                        //cout << "cars[j].loc - cars[i].loc = " << cars[j].loc << " - " <<  cars[i].loc <<endl;
                        //cout << "fabs((double)(cars[j].loc - cars[i].loc))*(double)timeBlock[cars[i].startH] + 100.0; " <<  fabs((double)(cars[j].loc - cars[i].loc))*(double)timeBlock[cars[i].startH] + 100.0 <<endl;
                        //cout << "(double)timeBlock[cars[i].startH] " << (double)timeBlock[cars[i].startH] <<endl;
                        bill[cars[i].name] += abs((cars[j].loc - cars[j-1].loc))*timeBlock[cars[j-1].startH] + 100;
                        //cout << "bill[cars[i].name] = " << bill[cars[i].name] <<endl;
                        //cout << bill[cars[i].name] << " = = >> " <<endl;
                        i = j-1;
                        break;
                    }
                }
            }

        }
        map<string,int>::iterator iter;
        for(iter = bill.begin();iter != bill.end();++iter)
        {
            //cout << iter->first << " $" << fixed << setprecision(2) << (iter->second+200)/100 <<endl;
            cout << iter->first << " $" ;
            printf("%d.%02d\n", (iter->second+200)/100, (iter->second+200)%100);
        }
        t++;
        //cout << "test = ? " << test1 <<endl;
    }
    return 0;
}

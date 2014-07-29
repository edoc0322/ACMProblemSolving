#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct profile
{
    string title,Fn,Ln,addr,dep,hp,wp,box;
};

bool cmp(profile p1, profile p2)
{
    return p1.Ln < p2.Ln;
}

int main()
{

    int N;
    while(cin >> N)
    {
        profile prof[10000];
        int counts = 0;
        string dep;
        getchar();
        getline(cin,dep);
        int restN = N-1;
        char temp[10000];
        while(gets(temp) && *temp)
        {
            char *temps = strtok(temp,",");

            string title = string(temps);

            temps = strtok(NULL,",");
            string firstN = string(temps);

            temps = strtok(NULL,",");
            string lastN = string(temps);

            temps = strtok(NULL,",");
            string addr = string(temps);

            temps = strtok(NULL,",");
            string hp = string(temps);

            temps = strtok(NULL,",");
            string wp = string(temps);

            temps = strtok(NULL,",");
            string box = string(temps);

            prof[counts].title = title;
            prof[counts].Fn = firstN;
            prof[counts].Ln = lastN;
            prof[counts].addr = addr;
            prof[counts].hp = hp;
            prof[counts].wp = wp;
            prof[counts].box = box;
            prof[counts].dep = dep;
            counts++;
        }

        while(restN--)
        {
            getline(cin,dep);
            while(gets(temp) && *temp)
            {
                char *temps = strtok(temp,",");

                string title = string(temps);

                temps = strtok(NULL,",");
                string firstN = string(temps);

                temps = strtok(NULL,",");
                string lastN = string(temps);

                temps = strtok(NULL,",");
                string addr = string(temps);

                temps = strtok(NULL,",");
                string hp = string(temps);

                temps = strtok(NULL,",");
                string wp = string(temps);

                temps = strtok(NULL,",");
                string box = string(temps);

                prof[counts].title = title;
                prof[counts].Fn = firstN;
                prof[counts].Ln = lastN;
                prof[counts].addr = addr;
                prof[counts].hp = hp;
                prof[counts].wp = wp;
                prof[counts].box = box;
                prof[counts].dep = dep;
                counts++;
            }
        }
        sort(prof,prof+counts,cmp);

        for(int i = 0 ; i < counts;++i)
        {
            cout << "----------------------------------------\n";
            cout << prof[i].title << " " << prof[i].Fn << " " << prof[i].Ln <<endl;
            cout << prof[i].addr <<endl;
            cout << "Department: " << prof[i].dep <<endl;
            cout << "Home Phone: " << prof[i].hp <<endl;
            cout << "Work Phone: " << prof[i].wp <<endl;
            cout << "Campus Box: " << prof[i].box <<endl;
        }

    }
    return 0;
}

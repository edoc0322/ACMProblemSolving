    #include <iostream>
    #include <algorithm>
    #include <string>
    #include <map>
    #include <stdio.h>

    using namespace std;
    struct country
    {
        string name;
        int t;
    };

    bool cmp(country c1,country c2)
    {
        return c1.name < c2.name;
    }
    int main()
    {

        int n;
        char t[2002];
        while(cin >> n){
            getchar();
            string na;
            string n2;
            country countrys[2002];
            map<string ,int> map1;
            int count = 1;
            for(int i = 0 ; i < n ;++i){
                cin.getline(t,2002);
                na = string(t);
                int status = 1;
                for(int j = 0 ; j < na.length();++j)
                {
                    if(na[j] ==' ')
                    {
                        n2 = na.substr(0,j);
                        status = 0;
                        break;
                    }
                }
                if(status){
                    n2 = na;
                }
                //cout << n2 <<"!"<<endl;
                if(map1[n2] == 0){
                    countrys[count-1].name = n2;
                    countrys[count-1].t = 1;
                    map1[n2] = count;
                    count++;
                }
                else
                {
                    countrys[map1[n2]-1].t++;
                }
            }
            sort(countrys,countrys+count-1,cmp);
            for(int i = 0 ; i < count-1 ;++i){
                cout << countrys[i].name << " " << countrys[i].t<<endl;
            }
        }
        return 0;
    }

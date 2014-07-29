#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
using namespace std;



int main()
{
    int test;
    cin >> test;
    getchar();
    while(test--)
    {
        map<string,string> maps;
        map<string,int> exist;
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        string clearS1,clearS2;
        clearS1 = s1.substr(1,s1.length()-2);
        clearS2 = s2.substr(1,s2.length()-2);

        int start,end;
        string sep = ",";
        start = clearS1.find_first_not_of(sep);
        end = 0;
        while(start != string::npos)
        {
            end = clearS1.find_first_of(sep,start+1);
            if(end == string::npos)
            {
                end = clearS1.length();
            }
            string tempS = clearS1.substr(start,end-start);
            char ss1[10000];
            char ss2[10000];
            //cout << tempS <<endl;
            string classS1,classS2;
            int index = tempS.find_last_of(":");
            classS1 = tempS.substr(0,index);
            classS2 = tempS.substr(index+1);
            //cout << "classS1 and classS2 = " << classS1 << " + " << classS2 <<endl;
            maps[classS1] = classS2;
            exist[classS1] = 1;
            start = clearS1.find_first_not_of(sep,end+1);
        }

        set<string> addS,deleteS,changeS;

        start = clearS2.find_first_not_of(sep);
        end = 0;
        while(start != string::npos)
        {
            end = clearS2.find_first_of(sep,start+1);
            if(end == string::npos)
            {
                end = clearS2.length();
            }
            string tempS = clearS2.substr(start,end-start);
            char ss1[10000];
            char ss2[10000];
            string classS1,classS2;
            int index = tempS.find_last_of(":");
            //cout << "index = " << index <<endl;
            classS1 = tempS.substr(0,index);
            classS2 = tempS.substr(index+1);
            //cout << "classS1 and classS2 = " << classS1 << " + " << classS2 <<endl;
            if(maps.find(classS1) == maps.end())
            {
                //cout << "insert " << classS1<<endl;
                addS.insert(classS1);
            }
            else
            {
                if(maps[classS1] != classS2)
                {
                    changeS.insert(classS1);
                    exist[classS1] = 0;
                }
                else
                {
                    exist[classS1] = 0;
                }
            }

            start = clearS2.find_first_not_of(sep,end+1);
        }
        map<string,int>::iterator iter;
        for(iter = exist.begin(); iter!=exist.end();++iter)
        {
            if(iter->second == 1)
            {
                deleteS.insert(iter->first);
            }
        }
        if(addS.size() + deleteS.size() + changeS.size() > 0)
        {
            int counts = 0;
            set<string>::iterator iter2;
            for(iter2 = addS.begin(); iter2 != addS.end();++iter2)
            {
                if(counts== 0)
                {
                    cout << "+" << *iter2;
                }
                else
                {
                    cout << "," << *iter2;
                }
                counts++;
            }
            if(addS.size() > 0)
                cout <<endl;

            counts = 0;
            for(iter2 = deleteS.begin(); iter2 != deleteS.end();++iter2)
            {
                if(counts== 0)
                {
                    cout << "-" << *iter2;
                }
                else
                {
                    cout << "," << *iter2;
                }
                counts++;
            }
            if(deleteS.size() > 0)
                cout <<endl;

            counts = 0;
            for(iter2 = changeS.begin(); iter2 != changeS.end();++iter2)
            {
                if(counts== 0)
                {
                    cout << "*" << *iter2;
                }
                else
                {
                    cout << "," << *iter2;
                }
                counts++;
            }
            if(changeS.size() > 0)
                cout <<endl;

        }
        else
        {
            cout << "No changes" <<endl;
        }
        cout <<endl;

    }
    return 0;
}

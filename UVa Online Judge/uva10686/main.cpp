#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;



int counts = 0;
int N;
int main()
{
    int test;
    cin >> test;
    while(test--)
    {

        counts = 0;

        int need[31];
        string names[31];
        map<string,int> category[31];
        cin >> N;

        for(int i = 0 ; i < N;++i)
        {
            string s;
            cin >> s;
            int n1,n2;
            cin >> n1 >> n2;
            string s2;
            names[i] = s;
            need[i] = n2;
            for(int j = 0 ; j < n1; ++j)
            {
                cin >> s2;
                category[i][s2] = 0;
            }
        }
        string line;

        getchar();
        while(getline(cin,line) && line.length() >0)
        {
            for(int j = 0 ; j < line.length();++j)
            {
                if(line[j] >= 'A' && line[j] <= 'Z' || line[j] >= 'a' && line[j] <= 'z')
                {
                    string cat = "";
                    int index =0;
                    while(j < line.length() && line[j] >= 'A' && line[j] <= 'Z' || line[j] >= 'a' && line[j] <= 'z')
                    {
                        cat += line[j++];
                    }
                    for(int i = 0 ; i < N;++i)
                    {
                        if(category[i].find(cat) != category[i].end())
                        {
                            category[i][cat] = 1;
                        }
                    }

                }
            }
            /*
            string sep = "1234567890`~!@#$%^&*()_+|{}\"<>?-=\\[];',./ ";
            int start = line.find_first_not_of(sep);
            int end = 0;
            while(start != string::npos)
            {
                end = line.find_first_of(sep,start+1);
                if(end == string::npos)
                    end = line.length();
                string cutS = line.substr(start,end-start);
                for(int i = 0 ; i < N;++i)
                {
                    if(category[i].find(cutS) != category[i].end())
                    {
                        category[i][cutS] = 1;
                    }
                }



                //cout << cutS <<endl;
                start = line.find_first_not_of(sep,end+1);
            }
            */

        }
        int counts = 0;
        for(int i = 0 ; i < N;++i)
        {
            int sums = 0;
            map<string,int>::iterator it;
            for(it = category[i].begin();it != category[i].end();++it)
            {
                sums += it->second;
                //cout << sums <<endl;
            }
            if(sums >= need[i])
            {
                if(counts == 0)
                {
                    cout << names[i] ;
                }
                else
                {
                    cout << "," << names[i];
                }
                counts++;
            }
        }
        if(counts == 0)
        {
             cout << "SQF Problem.";
        }
        cout <<endl;


    }
    return 0;
}

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<string,int> personNum;
map<string,string> child;
int counts;
struct person
{
    string name,mychild,myparent1,myparent2;
    int generation;
    string hasGene;
};
person persons[10000000];
int main()
{
    int N;
    string s1,s2;
    while(cin >> N)
    {
        counts = 0;
        personNum.clear();
        for(int t = 0 ; t < N;++t)
        {
            cin >> s1 >> s2;
            if(s2 == "dominant" || s2 == "recessive" || s2 == "non-existent")
            {
                if(personNum.find(s1) == personNum.end())
                {
                    personNum[s1] = counts++;
                }
                persons[personNum[s1]].name = s1;
                persons[personNum[s1]].hasGene = s2;
            }
            else
            {
                if(personNum.find(s1) == personNum.end())
                {
                    personNum[s1] = counts++;
                }
                if(personNum.find(s2) == personNum.end())
                {
                    personNum[s2] = counts++;
                }
                persons[personNum[s1]].name = s1;
                persons[personNum[s2]].name = s2;
                if(persons[personNum[s1]].hasGene == "" && persons[personNum[s2]].hasGene == "")
                {
                    persons[personNum[s1]].hasGene = "unknown";
                    persons[personNum[s2]].hasGene = "unknown";
                }
                if(child.find(s2) == child.end())
                {
                    child[s2] = s1;
                }
                else
                {
                    //cout << "p1 p2 " << person[s1] << "  " << person[child[s2]] <<endl;
                    if((person[s1] == "dominant" && person[child[s2]] == "dominant") ||
                        (person[s1] == "dominant") ||
                         person[child[s2]] == "dominant" ||
                         (person[s1] == "recessive" && person[child[s2]] == "recessive"))
                    {
                        if( (person[s1] == "dominant" && person[child[s2]] == "dominant") ||
                           (person[s1] == "recessive" && person[child[s2]] == "dominant") ||
                            (person[s1] == "dominant" && person[child[s2]] == "recessive") )
                        {
                            person[s2] = "dominant";
                        }
                        else
                        {
                             person[s2] = "recessive";
                        }
                    }
                    else
                    {
                        person[s2] = "non-existent";
                    }
                }
            }
        }
        map<string,string>::iterator iter;
        for(iter = person.begin();iter != person.end();++iter)
        {
            cout << iter->first << " " << iter->second <<endl;
        }

    }
    return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
struct pairs
{
    string s;
    int num;
};

bool cmp(pairs p1 , pairs p2)
{
    if(p1.num != p2.num)
    {
        return p1.num > p2.num;
    }
    else
    {
        return p1.s < p2.s;
    }
}

int main()
{
    map<string, vector<string> > softmaps;
    map<string, int > stumaps;
    map<string, string> stuHasSoft;
    string s;
    string curSoftS;
    int counts = 0;
    while(getline(cin,s))
    {
        if(s == "1")
        {
            map<string,vector<string> >::iterator iter;
            pairs sets[counts];
            int i2 = 0;
            for(iter = softmaps.begin(); iter!=softmaps.end();++iter)
            {
                //cout << iter->first <<" " << iter->second.size() <<endl;
                sets[i2].num = iter->second.size();
                sets[i2].s = iter->first;
                i2++;
            }
            sort(sets,sets + counts,cmp);
            for(int i = 0 ; i < counts;++i)
            {
                cout << sets[i].s << " " << sets[i].num <<endl;
            }
            counts = 0;
            softmaps.clear();
            stumaps.clear();
            stuHasSoft.clear();
        }
        else if(s == "0")
        {
            break;
        }
        else
        {
            if(s[0]>= 'A' && s[0]<='Z')
            {
                curSoftS = s;
                vector<string> newV;
                //cout << "new soft " << curSoftS <<endl;
                softmaps[curSoftS] = newV;
                counts++;
            }
            else
            {
                string stus= s;
                if(stumaps[stus] == NULL)
                {
                    vector<string> curV = softmaps[curSoftS];
                    curV.push_back(stus);
                    stumaps[stus] = 1;
                    softmaps[curSoftS] = curV;
                    stuHasSoft[stus] = curSoftS;
                }
                else
                {
                    string softS = stuHasSoft[stus];
                    if(curSoftS != softS)
                    {
                        vector<string> curV = softmaps[softS];
                        int i;
                        for(i = 0 ; i < curV.size();++i)
                        {
                            if(curV[i] == stus)
                                break;
                        }
                        if(i <curV.size())
                        {
                            curV.erase(curV.begin()+i);
                        }
                        softmaps[softS] = curV;
                    }


                }
            }
        }
    }
    return 0;
}

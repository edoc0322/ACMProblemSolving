#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>
#include <fstream>
using namespace std;


set<string> sets;
map<string,int> locMap;
map<string,int> locMapMaxNum;
string wordPosition[100010];

int main()
{
    //ofstream fout("test.txt");
    int test;
    cin >> test;
    getchar();
    for(int t = 1 ; t <= test;++t)
    {
        string s;
        locMap.clear();
        locMapMaxNum.clear();
        int smallestDistance = 100000000;
        int biggestSize = 0;
        int locIndex = 1;
        while(getline(cin,s))
        {
            if(s == "END")
            {
                //fout << "IamBreak" <<endl;
                break;
            }
            int len = s.length();
            for(int i = 0 ; i < len;++i)
            {
                if(s[i] >= 'a' && s[i] <= 'z')
                {
                    string emptyS = "";
                    while(i < len && s[i] >= 'a' && s[i] <= 'z')
                    {
                        emptyS += s[i++];
                    }
                    locMap[emptyS]++;
                    //cout << "emptyS " << emptyS << " " << locMap[emptyS]<<endl;
                    if(locMapMaxNum.find(emptyS) == locMapMaxNum.end())
                    {
                        locMapMaxNum[emptyS] = 0;
                    }
                    if(locMapMaxNum[emptyS] < locMap[emptyS])
                    {
                        int temp = locMap[emptyS];
                        locMapMaxNum[emptyS] = temp;
                    }
                    //cout << " locMapMaxNum[emptyS] " << locMapMaxNum[emptyS]<<endl;
                    wordPosition[locIndex] = emptyS;
                    locIndex++;
                }
            }
        }
        /*
        map<string,int>::iterator iter;
        for(iter = locMapMaxNum.begin(); iter != locMapMaxNum.end();++iter)
        {
            //fout << iter->second <<endl;
            cout << iter->second <<endl;
        }
        */

        int maxNum = locMap.size();
        int status = 0;
        int minStart = -1,minEnd = -1;
        sets.clear();
        int k = 1,m = 1;
        while(k <= locIndex && m <= locIndex)
        {
            if(status == 0)
            {
                //fout << " status = 0  k m " << k << "  " << m <<endl;

                if(sets.size() == maxNum)
                {
                    m--;
                    status = 1;
                    continue;
                }
                else
                {
                    //cout << " status = 0  k m " << k << "  " << m <<endl;
                    sets.insert(wordPosition[m]);
                    locMap[wordPosition[m]]--;
                    //cout << " status = 0 , cut the word " << wordPosition[m] << " " << locMap[wordPosition[m]]<<endl;
                    m++;
                }

            }
            else
            {
                //cout << m << "  " << k <<endl;
                //fout << "status = 1 " << m << " " << k <<endl;
                if(m - k < smallestDistance)
                {
                    smallestDistance = m - k;
                    minStart = k;
                    minEnd = m;
                }
                locMap[wordPosition[k]]++;
                //cout << "word is " << wordPosition[k] <<endl;
                //cout << locMap[wordPosition[k]] << "  max is ... ? " << locMapMaxNum[wordPosition[k]]<<endl;
                //fout << locMap[wordPosition[k]] << "  max is ... ? " << locMapMaxNum[wordPosition[k]]<<endl;
                if(locMap[wordPosition[k]] == locMapMaxNum[wordPosition[k]])
                {
                    sets.erase(wordPosition[k]);
                    status = 0;
                    k++;
                    m++;
                    //cout << "Hi\n";
                    continue;
                }
                k++;

            }

        }
        if(minStart == -1 && minEnd == -1)
        {
            minStart = 1;
            minEnd = locIndex-1;
        }
        cout << "Document " << t << ": " <<minStart << " " << minEnd <<endl;
        //fout << "Document " << t << ": " <<smallestDistance <<endl;

    }
    //fout.close();
    return 0;
}

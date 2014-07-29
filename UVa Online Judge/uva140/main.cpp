#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
int maps[30][30];
int arr[30];
int charArr[30];
int nodes = 0;
int main()
{
    string s;
    while(cin >> s)
    {
        map<char,int> hashNum;
        nodes = 0;
        if(s=="#") break;
        for(int i = 0 ; i < 26;++i)
        {
            for(int j = 0 ; j < 26;++j)
            {
                if(i == j)
                {
                    maps[i][j] = 0;
                }
                else
                    maps[i][j] = 1e9;
            }
        }

        int start = s.find_first_not_of(";");
        int end = 0;
        while(start != string::npos)
        {
            end = s.find_first_of(";",start+1);
            if(end == string::npos)
            {
                end = s.length();
            }
            string subs = s.substr(start,end-start);
            //cout << subs <<endl;
            int index= subs.find_first_of(":");
            if(hashNum.find(subs[0]) == hashNum.end())
            {
                hashNum[subs[0]] = nodes;
                charArr[nodes] = subs[0];
                nodes++;
            }
            for(int i = index+1;i < subs.length() ;++i)
            {
                if(hashNum.find(subs[i]) == hashNum.end())
                {
                    hashNum[subs[i]] = nodes;
                    charArr[nodes] = subs[i];
                    nodes++;
                }
                maps[hashNum[subs[0]]][hashNum[subs[i]]] = maps[hashNum[subs[i]]][hashNum[subs[0]]] = 1;
            }
            start = s.find_first_not_of(";",end+1);
        }
        for(int i = 0 ; i < nodes;++i)
        {
            arr[i] = i;
        }
        int totalMin = 1e9;
        int finalAns[30];
        do
        {
            int maxS = 0;
            for(int i = 0 ; i < nodes;++i)
            {
                int sums = 0;
                for(int j = 0 ; j < nodes;++j)
                {
                    if(i!=j)
                    {
                        if(  maps[hashNum[charArr[arr[i]]]][hashNum[charArr[arr[j]]]] == 1 )
                        {
                            //cout << j << " j an i " << i <<endl;
                            sums = max(sums,abs(j-i));
                        }
                    }
                }
                maxS = max(maxS,sums);
            }
            if(totalMin > maxS)
            {
                for(int i = 0 ; i < nodes;++i)
                {
                    finalAns[i] = arr[i];
                }

                totalMin = maxS;
            }
            else if(totalMin == maxS)
            {
                /*
                cout << "arr ";
                for(int i = 0 ; i <nodes;++i)
                {
                    cout << (char)charArr[ arr[i] ] << " ";
                }
                cout <<endl;
                cout << "final ";
                for(int i = 0 ; i <nodes;++i)
                {
                    cout << (char)charArr[ finalAns[i] ] << " ";
                }
                cout <<endl;
                */


                int status = 0;
                for(int i = 0 ; i < nodes;++i)
                {
                    if ( (char)charArr[ arr[i] ] == (char)charArr[ finalAns[i] ] )
                    {
                        continue;
                    }
                    else if((char)charArr[ arr[i] ] < (char)charArr[ finalAns[i] ] )
                    {
                        //cout << (char)charArr[ arr[i] ] << " cmp " << (char)charArr[ finalAns[i]]<<endl;
                        status = 1;
                        break;
                    }
                    else if((char)charArr[ arr[i] ] > (char)charArr[ finalAns[i]] )
                    {
                        break;
                    }
                }
                if(status)
                {
                    for(int i = 0 ; i < nodes;++i)
                    {
                        finalAns[i] = arr[i];
                    }
                }
            }
        }while(next_permutation(arr,arr+nodes));

        for(int i = 0 ; i < nodes;++i)
        {
            cout << (char)charArr[ finalAns[i] ] << " ";
        }
        cout << "-> " << totalMin <<endl;
    }
    return 0;
}

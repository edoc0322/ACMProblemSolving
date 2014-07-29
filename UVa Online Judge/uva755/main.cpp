#include <iostream>
#include <cctype>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <map>
using namespace std;

int sti[200];

int main()
{
    sti['A'] = sti['B'] = sti['C'] = 2;
    sti['D'] = sti['E'] = sti['F'] = 3;
    sti['G'] = sti['H'] = sti['I'] = 4;
    sti['J'] = sti['K'] = sti['L'] = 5;
    sti['M'] = sti['N'] = sti['O'] = 6;
    sti['P'] = sti['R'] = sti['S'] = 7;
    sti['T'] = sti['U'] = sti['V'] = 8;
    sti['W'] = sti['X'] = sti['Y'] = 9;
    int testcase;
    cin >> testcase;
    while(testcase > 0){
        getchar();

        map<string,int> map1;
        map<string,int>::iterator iter;
        int n;
        string s;
        cin >> n;
        for(int i = 0 ; i < n;++i){
            cin >> s;
            int count = 0;
            string s2 = "";
            for(int j = 0 ; j < s.length();++j)
            {
                if(isdigit(s[j]))
                {
                    s2 += s.substr(j,1);
                    count++;
                    if(count == 3){
                        s2 += "-";
                    }
                }
                else if(isalpha(s[j]))
                {
                    char temp[10];
                    //itoa(sti[s[j]],temp,10);
                    sprintf( temp, "%d", sti[s[j]] );
                    s2 += string(temp);
                    count++;
                    if(count == 3){
                        s2 += "-";
                    }
                }
            }
            map1[s2]++;
        }
        int status = 1;
        for(iter = map1.begin();iter != map1.end();++iter){
            if(iter->second  > 1)
            {
                status = 0;
                cout << iter->first << " "<<iter->second << endl;
            }
        }
        if(status)
        {
            cout << "No duplicates."<<endl;
        }


        if(testcase>1)cout << endl;
        testcase--;
    }
    return 0;
}

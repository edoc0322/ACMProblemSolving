#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
#include <map>
#include <cstdlib>
#include <cctype>
using namespace std;


struct team
{
    string name;
    int big_point;
    int win_score;
    int game;
    int win;
    int tie;
    int lose;
    int lose_score;
};
bool cmp(team t1,team t2)
{
    if(t1.big_point > t2.big_point)
    {
        return true;
    }
    if(t1.big_point < t2.big_point)
    {
        return false;
    }
    if(t1.big_point == t2.big_point)
    {
        if(t1.win > t2.win){
            return true;
        }
        if(t1.win < t2.win){
            return false;
        }
        if(t1.win == t2.win)
        {
            if(t1.win_score - t1.lose_score > t2.win_score - t2.lose_score){
                return true;
            }
            if(t1.win_score - t1.lose_score < t2.win_score - t2.lose_score){
                return false;
            }
            if(t1.win_score - t1.lose_score == t2.win_score - t2.lose_score)
            {
                if(t1.win_score > t2.win_score){
                    return true;
                }
                if(t1.win_score < t2.win_score){
                    return false;
                }
                if(t1.win_score == t2.win_score){
                    if(t1.game < t2.game){
                        return true;
                    }
                    if(t1.game < t2.game){
                        return false;
                    }
                    if(t1.game == t2.game){
                        string a,b;
                        a = t1.name;
                        b = t2.name;
                        for(int i = 0 ; i < a.length();++i){
                            a[i] = tolower(a[i]);
                        }
                        for(int i = 0 ; i < b.length();++i){
                            b[i] = tolower(b[i]);
                        }
                        return a < b;
                    }
                }
            }
        }
    }
}
int main()
{
    int testcase;
    cin >>testcase;
    getchar();
    while(testcase > 0){
        char title[1001];
        cin.getline(title,1001);
        //cout <<"FU?";
        cout << title<<endl;
        map<string,int> map1;
        team teams[31];
        int n;
        cin >> n ;

        string na;
        getchar();
        for(int i = 0 ; i < n;++i){
            char tt[2001];
            cin.getline(tt,2000);
            na = string(tt);
            map1[na] = i;
            teams[i].name = na;
            teams[i].lose = teams[i].lose_score = teams[i].game = teams[i].tie = teams[i].win = teams[i].win_score = teams[i].big_point = 0;
        }
        int games;
        cin >> games;
        int x1,x2,x3;
        string t1,t2;
        int p1,p2;
        char na2[2000];
        getchar();
        for(int i = 0 ; i < games;++i){
            cin.getline(na2,2000);
            na = string(na2);
            //cout << na<<endl;;
            x1 = x2 = x3 = 0;
            for(int j = 0 ; j < na.length();++j){
                if(na[j] == '#' && x1 == 0){
                    x1 = j;
                }
                else if(na[j] == '#' && x1 != 0){
                    x3 = j;
                }
                else if(na[j] == '@'){
                    x2 = j;
                }
            }
            p1 = atoi(na.substr(x1+1,x2-x1-1).c_str());
            p2 = atoi(na.substr(x2+1,x3-x2-1).c_str());
            t1 = na.substr(0,x1);
            t2 = na.substr(x3+1,na.length()-x3-1);
            //cout << t1 << " "<<p1 << " " << t2 << " "<<p2<<endl;
            teams[map1[t1]].game++;
            teams[map1[t2]].game++;

            if( p1 > p2)
            {
                teams[map1[t1]].win++;
                teams[map1[t2]].lose++;
                teams[map1[t1]].big_point += 3;
                teams[map1[t1]].lose_score+= p2;
                teams[map1[t1]].win_score+= p1;
                teams[map1[t2]].win_score+= p2;
                teams[map1[t2]].lose_score+= p1;
            }
            else if(p1 == p2)
            {
                teams[map1[t1]].tie++;
                teams[map1[t2]].tie++;
                teams[map1[t1]].big_point += 1;
                teams[map1[t2]].big_point += 1;
                teams[map1[t1]].lose_score+= p2;
                teams[map1[t1]].win_score+= p1;
                teams[map1[t2]].win_score+= p2;
                teams[map1[t2]].lose_score+= p1;
            }
            else
            {
                teams[map1[t1]].lose++;
                teams[map1[t2]].win++;
                teams[map1[t2]].big_point += 3;
                teams[map1[t2]].lose_score+= p1;
                teams[map1[t2]].win_score+= p2;
                teams[map1[t1]].win_score+= p1;
                teams[map1[t1]].lose_score+= p2;
            }
        }
        sort(teams,teams+n,cmp);
        for(int i = 0 ; i < n ;++i)
        {
            cout << i+1 << ") ";
            cout << teams[i].name<<" ";
            cout << teams[i].big_point<<"p, ";
            cout << teams[i].game<<"g (";
            cout << teams[i].win <<"-"<<teams[i].tie <<"-"<<teams[i].lose<<"), ";
            cout << (teams[i].win_score-teams[i].lose_score)<<"gd (";
            cout << (teams[i].win_score) << "-" << teams[i].lose_score <<")\n";

        }

        if(testcase > 1){
            cout << endl;
        }
        testcase--;
    }
    return 0;
}

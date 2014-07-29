#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

struct rec
{
    string name;
    int cost;
};

bool cmp(rec r1,rec r2)
{
    if(r1.cost != r2.cost)
    {
        return r1.cost < r2.cost;
    }
    else
    {
        return r1.name < r2.name;
    }
}

int main()
{
    int test;
    cin >> test;
    string title;
    getchar();
    int budget,M,N;
    for(int t = 0 ; t < test;++t)
    {
        getline(cin,title);
        cin >> M >> N >> budget;
        string s;
        int cost;
        map<string,int> sets;
        map<string,int> recipe;
        vector<rec> ans;
        for(int i = 0 ; i < M;++i)
        {
            cin >> s;
            cin >> cost;
            sets[s] = cost;
        }
        getchar();
        int k;
        for(int i = 0 ; i < N;++i)
        {
            getline(cin,s);
            recipe[s] = 0;
            cin >> k;
            string s2;
            int num;
            for(int j = 0 ; j < k;++j)
            {
                cin >> s2;
                cin >> num;
                recipe[s] += sets[s2] * num;
            }
            rec r1;
            r1.cost = recipe[s];
            r1.name = s;
            ans.push_back(r1);
            getchar();
        }

        sort(ans.begin(),ans.end(),cmp);
        for(int i = 0 ; i < title.length();++i)
        {
            if(title[i] >= 'a' && title[i] <= 'z')
            {
                cout << (char)(title[i]-'a'+'A');
            }
            else
            {
                cout << title[i];
            }
        }
        cout <<endl;

        int sums = 0;
        if(ans[0].cost > budget)
        {
            cout << "Too expensive!" <<endl;
        }
        else
        {
            for(int i = 0 ; i < N;++i)
            {
                if(ans[i].cost <= budget)
                {
                    cout << ans[i].name <<endl;

                }
                else
                {
                    break;
                }
            }
        }
        cout <<endl;

    }
    return 0;
}

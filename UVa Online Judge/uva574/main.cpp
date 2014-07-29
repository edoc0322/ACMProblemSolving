#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;
int w[14];
int N;
int maxW;
int ans[14];
map<int,int> his[10050];
multiset<int> his2[10050];
vector<int> his3[10050];
int tot;
int prin[14];

bool cmp1(int a, int b)
{
    return a > b;
}
bool cmp2(vector<int> a,vector<int> b)
{
    /*
    if(a.size() < b.size())
    {
        return true;
    }
    else if(a.size() > b.size())
    {
        return false;
    }
    else
    {
    */
        vector<int>::iterator t1,t2;
        t1 = a.begin();
        t2 = b.begin();
        while(t1 != a.end())
        {
            if(*t1 != *t2)
            {
                return *t2 < *t1;
            }
            t1++;
            t2++;
        }

/*
    }*/
}

void backtracvk(int cur,int W)
{
    if(cur == N && W != maxW)
    {
        return;
    }
    else if(W == maxW)
    {
        int ok = 1;
        map<int ,int> a1;
        for(int i = 0 ; i < N; ++i)
        {
            if(ans[i])
            {
                a1[w[i]]++;
            }
        }
        int sum = 0;
        for(int i = 0 ; i < tot; ++i)
        {
            ok = 1;
            for(int j = 0 ; j < N; ++j)
            {
                if(ans[j])
                {
                    if(his[i][w[j]] != a1[w[j]])
                    {
                        ok = 0;
                        break;
                    }
                }

            }
            sum+=ok;
            if(sum) break;
        }

        if(!sum||tot == 0)
        {
            int count = 0;
            for(int i =0 ; i < N; ++i)
            {
                if(ans[i])
                    his[tot][w[i]]++ ;
                if(ans[i])
                    prin[count++] = w[i];
            }
            for(int i = 0 ; i < count-1; i++)
            {

                int temp = (prin[i]);
                his3[tot].push_back(temp);

            }

            his3[tot].push_back(prin[count-1]);

            tot++;
        }


        return;
    }
    else
    {
        ans[cur] = 1;
        backtracvk(cur+1,W+w[cur]);
        ans[cur] = 0;
        backtracvk(cur+1,W);
        return ;

    }
}
int main()
{

    while(cin >> maxW)
    {
        cin >> N;
        if(!N) break;
        for(int i = 0 ; i < N; ++i)
        {
            cin >> w[i];
        }
        tot = 0;
        for(int i = 0 ; i < 1001;++i)
        {
            his[i].clear();
            //his2[i].clear();
            his3[i].clear();
        }

        vector<int>::iterator iter;
        cout << "Sums of "<<maxW<<":"<<endl;
        if(maxW == 0)
        {
            cout << "NONE\n";
        }
        else
        {
            backtracvk(0,0);
            if(tot == 0)
            {
                cout << "NONE\n";
            }
            else
            {
                for(int i = 0 ; i < tot;++i){
                    sort(his3[i].begin(),his3[i].end(),cmp1);
                }
                sort(his3,his3+tot,cmp2);
                for(int i = 0 ; i < tot;++i){
                    int count = 0;
                    for(iter = his3[i].begin();iter!= his3[i].end();++iter)
                    {

                        cout << *iter;
                        //cout << "size is " << his2[i].size() <<endl;
                        if( count != his3[i].size()-1)
                        {
                            cout << "+";
                        }
                        count++;
                    }
                    cout << endl;
                }
            }
        }



    }

    return 0;
}

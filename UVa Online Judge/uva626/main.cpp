#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int maps[100][100];
int N;
int totalC = 0;
struct pairs
{
    int num[3];
};
set<string> checkAns;
pairs ans[162000];
void addAns(int nums[])
{
    int x,y,z;
    x = nums[0]+1;
    y = nums[1]+1;
    z = nums[2]+1;
    //cout << x << y << z <<endl;
    string s;
    if(x > y && y > z)
    {
        stringstream ss;
        stringstream ss2;
        stringstream ss3;
        ss << x;
        string s2;
        ss >> s2;
        s += s2 +" ";
        ss2 << y ;
        ss2 >> s2;
        s += s2 +" ";
        ss3 << z;
        ss3 >> s2;
        s += s2;
        if(checkAns.find(s) == checkAns.end())
        {
            checkAns.insert(s);
            ans[totalC].num[0] = x;
            ans[totalC].num[1] = y;
            ans[totalC].num[2] = z;
            totalC++;
        }
    }
    else if(x > y && y < z)
    {
        if( x > z)
        {
            int temp = x;
            x = y;
            y = z;
            z = temp;
        }
        else
        {
            int temp = z;
            z = y;
            y = x;
            x = temp;
        }
        stringstream ss;
        stringstream ss2;
        stringstream ss3;
        ss << x;
        string s2;
        ss >> s2;
        s += s2 +" ";
        ss2 << y ;
        ss2 >> s2;
        s += s2 +" ";
        ss3 << z;
        ss3 >> s2;
        s += s2;
        if(checkAns.find(s) == checkAns.end())
        {
            checkAns.insert(s);
            ans[totalC].num[0] = x;
            ans[totalC].num[1] = y;
            ans[totalC].num[2] = z;
            totalC++;
        }
    }
    else if(x < y && y < z)
    {
        stringstream ss;
        stringstream ss2;
        stringstream ss3;
        ss << x;
        string s2;
        ss >> s2;
        s += s2 +" ";
        ss2 << y ;
        ss2 >> s2;
        s += s2 +" ";
        ss3 << z;
        ss3 >> s2;
        s += s2;
        if(checkAns.find(s) == checkAns.end())
        {
            checkAns.insert(s);
            ans[totalC].num[0] = x;
            ans[totalC].num[1] = y;
            ans[totalC].num[2] = z;
            totalC++;
        }
    }
    else if(x < y && y > z)
    {
        if(x < z)
        {
            int temp = x;
            x = y;
            y = z;
            z = temp;
        }
        else
        {
            int temp = z;
            z = y;
            y = x;
            x = temp;
        }
        stringstream ss;
        stringstream ss2;
        stringstream ss3;
        ss << x;
        string s2;
        ss >> s2;
        s += s2 +" ";
        ss2 << y ;
        ss2 >> s2;
        s += s2 +" ";
        ss3 << z;
        ss3 >> s2;
        s += s2;
        if(checkAns.find(s) == checkAns.end())
        {
            checkAns.insert(s);
            ans[totalC].num[0] = x;
            ans[totalC].num[1] = y;
            ans[totalC].num[2] = z;
            totalC++;
        }
    }
    //cout << s <<endl;
}

bool cmp(pairs p1,pairs p2)
{
    if(p1.num[0] != p2.num[0])
    {
        return p1.num[0] < p2.num[0];
    }
    else
    {
        if(p1.num[1] != p2.num[1])
        {
            return p1.num[1] < p2.num[1];
        }
        else
        {
            if(p1.num[2] != p2.num[2])
            {
                return p1.num[2] < p2.num[2];
            }
        }
    }
}
int main()
{
    while(cin >> N)
    {
        checkAns.clear();
        totalC = 0;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                cin >> maps[i][j];
            }
        }
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                int num2[3];
                int next1;
                if(maps[i][j] == 1)
                {
                    //cout << "i = " <<i <<endl;
                    num2[0] = i;
                    next1 = j;
                    for(int k = 0;k < N;++k)
                    {
                        if(maps[next1][k] == 1 && k != i)
                        {
                            //cout << "k = " << k <<endl;
                            int next2;
                            num2[1] = next1;
                            next2 = k;
                            for(int m = 0 ; m < N;++m)
                            {
                                //cout << "next2 = " << next2 <<endl;
                                if(maps[next2][m] == 1 && m == i)
                                {
                                   // cout << num2[2] <<endl;
                                    num2[2] = next2;
                                    //cout << num2[0] << num2[1] << num2[2]<<endl;;
                                    addAns(num2);
                                }
                            }
                        }
                    }
                }
            }
        }
        sort(ans,ans + totalC,cmp);
        for(int i = 0 ; i < totalC;++i)
        {
            cout << ans[i].num[0] << " " << ans[i].num[1] << " " << ans[i].num[2] <<endl;
        }
        cout << "total:" <<totalC <<endl << endl;


    }
    return 0;
}

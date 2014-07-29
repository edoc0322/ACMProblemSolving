#include <iostream>
#include <string>

using namespace std;

string ans;
void backtrack(int index,string s,string command,int N)
{
    if(index == N)
    {
        cout << ans<<endl;
        return;
    }
    else
    {
        if(command[index] == '#')
        {
            //cout << s;
            ans += s;
            backtrack(index+1,s,command,N);
            ans = ans.substr(0,ans.length() - s.length());

        }
        else{
            for(int i = 0 ; i <=9;++i )
            {
                char n[2];
                n[0] = i+'0';
                n[1] = '\0';
                string temp(n);
                ans += temp;
                //cout << i ;
                backtrack(index+1,s,command,N);
                ans =ans.substr(0,ans.length()-1);
            }
        }
    }
    return;
}

int main()
{
    int sn,cn;
    string s[10001],cm[10001];
    while(cin >> sn)
    {
        cout << "--\n";
        for(int i = 0 ; i < sn;++i)
        {
            cin >> s[i];
        }
        cin >> cn;
        for(int i = 0 ; i < cn;++i)
        {
            cin >> cm[i];
        }
        for(int i = 0 ; i < sn;++i)
        {
            for(int j = 0 ; j < cn;++j)
            {
                ans = "";
                backtrack(0,s[i],cm[j],cm[j].length());
            }
        }
    }

    return 0;
}

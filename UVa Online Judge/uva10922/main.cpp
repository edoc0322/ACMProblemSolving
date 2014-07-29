#include <iostream>

#include <string>
#include <sstream>

using namespace std;

int find9(int depth,string n)
{
    int sums = 0;
    for(int i = 0 ; i < n.length() ;++i)
    {
        sums += n[i] - '0';
    }
    if(depth== 1 && sums%9 != 0)
    {
        return -1;
    }
    if(sums % 9 != 0 || sums == 9)
    {
        return depth;
    }
    //sums /= 9;
   // cout << sums <<endl;
    stringstream ss;
    ss << sums;
    string n2;
    ss >> n2;
    return find9(depth+1,n2);
}
int main()
{
    string s;
    while(cin >> s && s != "0")
    {
        int ans = find9(1,s);
        if(ans == -1)
        {
            cout << s <<" is not a multiple of 9."<<endl;
        }
        else
        {
            cout << s << " is a multiple of 9 and has 9-degree " << ans << "." <<endl;
        }
    }
    return 0;
}

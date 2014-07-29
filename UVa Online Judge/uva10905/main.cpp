#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string a , string b)
{
    return (a < b && a.length() > b.length());
}
int main()
{

    int n;
    while(cin >> n)
    {
        if (!n) break;

        vector<string> num1;
        for(int i = 0 ; i < n ; i++){
            string temp;
            cin >> temp;
            num1.push_back(temp);
        }
        sort(num1.begin(),num1.end(),cmp);
        for(int i =  num1.size()-1; i >=0 ; i--)
        {
            cout << num1.at(i);
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n)
    {
        int tempn = n;
        int sums = 0;
        stack<int> st;
        while(tempn)
        {
            st.push(tempn & 1);
            sums += tempn & 1;
            //cout << tempn;
            tempn = tempn >> 1;
        }
        cout << "The parity of ";
        while(!st.empty())
        {
            cout << st.top();
            st.pop();
        }
        cout << " is " << sums << " (mod 2)." <<endl;
    }
    return 0;
}

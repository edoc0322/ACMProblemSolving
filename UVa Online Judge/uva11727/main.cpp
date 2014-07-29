    #include <iostream>
    #include <algorithm>
    using namespace std;

    int main()
    {
        int n;
        cin >> n;
        int count = 1;
        while(n > 0){
            int a[3];
            cin >> a[0];
            cin >> a[1];
            cin >> a[2];
            sort(a,a+3);
            cout <<"Case " <<count++ <<": " << a[1]<<endl;
            n--;
        }
        return 0;
    }

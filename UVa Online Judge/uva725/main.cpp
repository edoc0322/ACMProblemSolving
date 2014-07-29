#include <iostream>
#include <map>
using namespace std;
int N;
int main()
{
    int count = 0;
    while(cin >> N && N)
    {
        int ok = 0;
        int temp;
        if(count > 0)
            cout << endl;
        for(int i = 1;i<=99999;++i)
        {
            temp = N*i;
            if(temp >= 10000)
            {
                if(temp >99999)
                {
                    break;
                }
                map<int,int> check;
                int ans[10];
                ans[0] = temp%10;
                ans[1] = temp/10%10;
                ans[2] = temp /100 %10;
                ans[3] = temp/1000%10;
                ans[4] = temp/10000%10;

                ans[5] = i%10;
                ans[6] = i/10%10;
                ans[7] = i/100 %10;
                ans[8] = i/1000%10;
                ans[9] = i/10000%10;
                int ok2 = 1;
                for(int i = 0 ; i < 10;++i)
                {
                    if(check[ans[i]] == 0)
                    {
                        check[ans[i]]++;
                    }
                    else{
                        ok2 = 0;
                        break;

                    }
                }

                if(ok2)
                {
                    ok = 1;
                    cout << temp << " / " ;
                    if(i <10000)
                    {
                        cout << "0";
                    }
                    cout << i <<" = "<<N<<endl;
                }
            }
        }
        if(!ok)
        {
            cout << "There are no solutions for "<<N<<".\n";
        }
        count++;
    }

    return 0;
}

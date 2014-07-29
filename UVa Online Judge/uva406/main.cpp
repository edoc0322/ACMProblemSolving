#include <iostream>

using namespace std;
bool prime[1002];

void eratosthenes()
{
    for (int i=0; i<1002; i++)
        prime[i] = true;
    prime[0] = false;
    prime[1] = true;
    for (int i=2; i<1002; i++)
        if (prime[i])

            for (int j=i+i; j<1002; j+=i)
                prime[j] = false;
}

int main()
{
    eratosthenes();
    int count = 0;
    int prime_arr[1003];
    prime[1] = true;
    for(int i = 1 ; i <= 1000; i++)
    {
        if(prime[i])
        {
            prime_arr[count] = i;
            count++;
        }
    }
    int N,C;
	//cout << "count is " << count << endl;
    while((cin >> N)&& (cin >> C))
    {
        int p = -1;
        for(int i = 0 ; i < count;i++){
			//cout << i << endl;
            if(prime_arr[i]> N){
                p = i-1;
                break;
            }
            else if(prime_arr[i]==N){
                p = i;
                break;
            }
        }
        if(p == -1 ) p = count-1;
        int mid = p / 2;
        cout << N << ' ' << C<<":" ;
		//cout << p << endl;
        if(p%2){
            int starti = mid - (C-1);
            if(starti < 0) starti = 0;
            int endi = C*2;
            if(endi >= count){

                endi = count;
            }
            for(int i = starti , j = 1; j <= endi;i++,j++ ){
                if(prime_arr[i] > prime_arr[p]) break;
                cout << ' ' << prime_arr[i];
            }
        }
        else{
            int starti = mid - (C-1);
            if(starti < 0) starti = 0;
            int endi = C*2-1;
            if(endi >= count){
                endi = count;
            }
            for(int i = starti , j = 1; j <= endi;i++,j++ ){
                if(prime_arr[i] > prime_arr[p]) break;
                cout << ' ' << prime_arr[i];
            }
        }
        cout <<"\n\n";
    }
    return 0;
}

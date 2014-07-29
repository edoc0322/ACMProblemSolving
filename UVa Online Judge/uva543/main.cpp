#include <iostream>
bool prime[1000001];

void eratosthenes()
{
    for (int i=0; i<1000001; i++)  // ��l��
        prime[i] = true;

    prime[0] = false;   // 0 �M 1 ���O���
    prime[1] = false;

    // ��U�@�ӥ��Q�R�����Ʀr
    for (int i=2; i<1000001; i++)
        if (prime[i])
            // �R�����i�����ơA�q�⭿�}�l�C�O�d�쥻��ơC
            for (int j=i+i; j<1000001; j+=i)
                prime[j] = false;
}
using namespace std;

int main()
{
    eratosthenes();
    int n;
    while(cin >> n){
        if(!n) break;
        int hn = n/2;
        for(int i = 2 ;i <= n;i++){
            if(i > hn){
                cout << "Goldbach's conjecture is wrong.\n";
                break;
            }
            if(prime[i] && prime[n-i]){
                cout << n << " = " <<i << " + " << (n-i)<<endl;
                break;
            }
        }
    }
    return 0;
}

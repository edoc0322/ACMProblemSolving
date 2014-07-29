#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
bool prime[1000002];

void eratosthenes()
{
    for (int i=0; i<1000002; i++)  // ��l��
        prime[i] = true;

    prime[0] = false;   // 0 �M 1 ���O���
    prime[1] = false;

    // ��U�@�ӥ��Q�R�����Ʀr
    for (int i=2; i<1000002; i++)
        if (prime[i])
            // �R�����i�����ơA�q�⭿�}�l�C�O�d�쥻��ơC
            for (int j=i+i; j<1000002; j+=i)
                prime[j] = false;
}

string Reverse(string theWord)
{
    // Reverse the string contained in theWord.

    string backup = theWord;
    int i;
    char temp;

    for (i=0; i<backup.length()/2; i++)
    {
        temp = backup[i];
        backup[i] = backup[backup.length()-i-1];
        backup[backup.length()-i-1] = temp;
    }
    return backup;
}
int main()
{
    eratosthenes();
    string s;
    string p;
    int a1,a2;
    while(cin >> s)
    {
        a1 = atoi(s.c_str());
        p = Reverse(s);
        a2 = atoi(p.c_str());
        if(prime[a1]&&prime[a2] && a1 != a2){
            cout << a1 << " is emirp.\n";
        }
        else if (prime[a1]&&!prime[a2] || prime[a1] && a1 == a2){
            cout << a1 << " is prime.\n";
        }
        else{
            cout << a1 << " is not prime.\n";
        }
    }


    return 0;
}

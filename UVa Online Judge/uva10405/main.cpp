#include <iostream>
#include <string>
using namespace std;
int array[1002][1002];

void LCS(string s1, string s2)
{
    s1 = " " + s1;
    s2 = " " + s2;
    for(int i = 0 ; i <1001;i++){
        array[i][0] = array[0][i] = 0;
    }
    for (int i = 1; i <= s1.length(); i++)
        for (int j = 1; j <= s2.length(); j++)
            if (s1[i] == s2[j] && s1[i]!= '\0'){
                // 這裡加上的 1 是指 e1 的長度為 1
                //cout << s1[i] << " HELL! " << s2[j]<<endl;
                array[i][j] = array[i-1][j-1] + 1;
                //cout << array[i][j] <<endl;
            }
            else
                array[i][j] = max(array[i-1][j], array[i][j-1]);

    cout << array[s1.length()][s2.length()] <<endl;
}
int main()
{
    string s1,s2;
    while( (std::getline(std::cin,s1)) && (std::getline(std::cin,s2))){
          LCS(s1,s2);
    }
    return 0;
}

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    int n,i,j;
    string a;

    while(cin>>n){
        char temp;
        cin >> temp;
        int s[27],s2[27];
        for(i = 0 ; i < 26;i++){
            s[i] = 0;
        }
        if(isalpha(temp)){
            if(temp>='a' && temp<='z'){
                s[temp-'a']++;
            }
            else if(temp>='A' && temp<='Z'){
                s[temp-'A']++;
            }
        }
        for(i = 0 ; i < n ; i++){
            getline(std::cin,a);
            for(j = 0 ; j < a.length() ; j++){
                if(isalpha(a[j])){
                    if(a[j]>='a' && a[j]<='z'){
                        s[a[j]-'a']++;
                    }
                    else if(a[j]>='A' && a[j]<='Z'){
                        s[a[j]-'A']++;
                    }
                }
            }
        }
        for(i = 0 ; i <26;i++){
            s2[i] = s[i];
        }
        int p[27];
        for(i = 0 ; i < 26;i++){
            p[i] = i;
        }

        int tempn;
        for(i = 0 ; i < 26-1;i++){
            for(j = 0 ; j < 26-1-i;j++){
                if(s[j]>s[j+1]){
                    tempn = s[j];
                    s[j] = s[j+1];
                    s[j+1] = tempn;
                    tempn = p[j];
                    p[j] = p[j+1];
                    p[j+1] = tempn;
                }
            }
        }

        int siz[26];
        siz[0]=s[25];
        int count = 1;
        for(i = 24 ; i >= 0 ;i--){
            if(siz[count-1] != s[i] && s[i]>0){
                siz[count] = s[i];
                count++;
            }
        }
        /*
        for(i = 0 ; i < count;i++){
            cout << siz[i]<<endl;
        }
*/
        for(i = 0 ; i < count;i++){
            for(j = 0 ; j <=25 ;j++){
                if(s2[j] == siz[i]){
                    cout << (char) (j+'A') << " " << s2[j]<< endl;
                }
            }
        }



    }
    return 0;
}

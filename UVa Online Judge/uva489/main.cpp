#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int main()
{

    char s1[1000],s2[1000];
    int keyword[200];
    int ccount;
    int testc;
    int deadc;
    int status;
    while(cin >> testc){
        getchar();
        if(testc==-1) break;
        deadc = 0;
        ccount = 0;
        status = 1;
        cin.getline(s1,1000);
        cin.getline(s2,1000);
        for(int i = 'a' ; i <= 'z';++i){
            keyword[i] = -1;
        }
        for(int i = 0 ; i < strlen(s1);++i){
            if(keyword[(int)s1[i]]==-1)
            {
                ccount++;
            }
            keyword[(int)s1[i]] += 2;
        }
        for(int i = 0 ; i < strlen(s2);++i){
            if(keyword[(int)s2[i]] > 0  )
            {
                keyword[(int)s2[i]] = 0;
                ccount--;
            }
            else if (keyword[(int)s2[i]] == -1)
            {
                //cout << s2[i] << endl;
                deadc++;
                keyword[(int)s2[i]] = 0;
            }
            if(ccount == 0 && deadc <7){
                status = 2;
                break;
            }
            if(deadc == 7 && ccount > 0)
            {
                status = 0;
                break;
            }
        }
        //cout << "dead "<<deadc <<endl;
        cout << "Round " << testc <<endl;
        if(status == 2){
            cout << "You win.\n";
        }
        else if(status == 0){
            cout << "You lose.\n";
        }
        else{
            cout <<"You chickened out.\n";
        }
    }
    return 0;
}

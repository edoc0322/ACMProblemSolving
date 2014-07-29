#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

map<string , int> friends;
int sumset[200001];
int setn[200001];
int getParent(int i) {
    if (i == setn[i])
        return i;
    else
        return (setn[i] = getParent(setn[i]));
}

void uni_c(string i , string j){

    int glarge = friends[i], gsmall = friends[j];
    if (sumset[friends[i]] < sumset[friends[j]]) swap(glarge, gsmall);
    /*
    std::map<string,int>::iterator it;
    it = friends.find(i);
    int n1 = it->second;
    it = friends.find(j);
    int n2 = it->second;
    */
    /*
    int gmin = min(n1,n2);
    int gmax = max(n1,n2);
    */
    for(std::map<string,int>::iterator it2 = friends.begin(); it2 != friends.end();++it2){
        int nk = it2->second;
        if(nk== gsmall){
            it2->second = glarge;
            --sumset[gsmall];
            ++sumset[glarge];
        }
    }

}
int N;
int main()
{
    int testcase;
    cin >> testcase;
    int pairn;
    string p1,p2;
    while(testcase > 0 )
    {

        friends.clear();
        N = 0;
        cin >> pairn;
        for(int i = 1 ; i <= pairn*2;++i){
            sumset[i] = 1;
            setn[i] = i;
        }
        for(int i = 0 ; i < pairn ;++i){
            cin >> p1;
            cin >> p2;

            if(!friends[p1]){
                friends[p1] = ++N;
            }
            if(!friends[p2]){
                friends[p2] = ++N;
            }
            int n1 = friends[p1];
            int n2 = friends[p2];
            int p = getParent(n1);
            int q = getParent(n2);
            if(p!=q){
                sumset[p] = sumset[p] + sumset[q];
                setn[q] = p;
            }
            cout << sumset[p] << endl;
            /*
            if(n1!=n2){
                uni_c(p1,p2);
            }
            */
            /*
            std::map<string,int>::iterator it;
            it = friends.find(p1);

            if(it == friends.end()){
                friends[p1] = ++N;
            }
            it = friends.find(p2);
            if(it == friends.end()){
                friends[p2] = ++N;
            }
            int n1 = find_c(p1);
            int n2 = find_c(p2);
            if(n1!=n2){
                uni_c(p1,p2);
            }
            */


        }

        --testcase;
    }
    return 0;
}

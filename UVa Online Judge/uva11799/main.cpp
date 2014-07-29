#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

vector<string> split(string& s, const char* c)
{
    char *cstr,*p;
    vector<string> res;
    cstr = new char[s.size()+1];
    strcpy(cstr,s.c_str());
    p = strtok(cstr,c);
    while(p!=NULL)
    {
        res.push_back(p);
        p = strtok(NULL,c);
    }
    return res;

}

int main()
{
    int n ;
    int count = 1;
    cin >> n;
    char temp;
    while(n > 0){
        cin >> temp;
        string s;
        getline(std::cin,s);
        //cout << s << endl;
        vector<string> res = split(s," ");
        int a[res.size()];
        int i =0;
        while(!res.empty()){
            a[i] = atoi(res.back().c_str());
            res.pop_back();
            i++;
        }
        int j = 0;
        int max = 0;
        for(j = 0 ;j < i ;j++){
            if(max < a[j])
                max = a[j];
        }
        cout << "Case "<<count++<<": "<< max <<endl;
        n--;
    }
    return 0;
}

#include <iostream>
#include <set>

using namespace std;

set<int> relation;
int people[50002];
int find(int i){
    int j  = i;
    while(people[j] != j)
        j = people[j];
    return j;
}
void unifunction(int i , int j){
   if(i < j){
        people[j] = i;
   }
   else{
        people[i] = j;
   }
}
int main()
{
    int count = 1;
    int n,m;
    int p1,p2;
    while((cin >> n) && (cin >> m)){
        if(!n && !m) break;
        relation.clear();
        for(int i = 1 ; i <= n ;++i){
            people[i] = i;
        }
        for(int i = 0 ; i < m;++i){
            cin >> p1;
            cin >> p2;
            if(find(p1)!= find(p2)){
                unifunction(find(p1),find(p2));
            }
        }
        for(int i = 1 ; i <= n;i++){
            int k = find(i);
            if(k != people[i]){
                unifunction(k,i);
            }
        }
        for(int i = 1 ; i <= n;i++){
            relation.insert(people[i]);
        }
        cout << "Case "<<count<<": " << relation.size()<<endl;
        count++;
    }


    return 0;
}

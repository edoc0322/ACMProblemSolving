#include <iostream>
#include <set>
#include <vector>
using namespace std;
int N,BN;
int M;
int arr[50];
int tempArr[50];
int ans = 0;
int visit[50];
int ansArr[50];
int coverArr[50];
set<int> sets[50];
void backtrack(int depth,int choose)
{
    if(choose > BN)return;
    if(choose == BN)
    {
        int current=0;
        vector<int> index;
        for(int i = 0 ; i < N;++i)
        {
            //cout << "choose : ";
            if(visit[i] == 1)
            {
                index.push_back(i);
                //cout << i << " ";
                current += arr[i];
            }
            //cout << endl;
        }
        //cout << current <<endl;
        for(int i = 0 ; i < M;++i)
        {
            int pairs = 0;
            for(int j = 0 ; j < index.size();++j)
            {
                if(sets[i].find(index[j]) != sets[i].end())
                {
                    pairs++;
                }
            }
            if(pairs >= 2)
            {
                current -= (coverArr[i]*(pairs-1));
            }
        }
        if(current > ans)
        {
            ans = current;
            int counts = 0;
            for(int i = 0 ; i < N;++i)
            {
                if(visit[i]) ansArr[counts++] = i+1;
            }
        }
        else if(current == ans)
        {
            int tempAns[50];
            int counts = 0;
            for(int i = 0 ; i < N;++i)
            {
                if(visit[i]) tempAns[counts++] = i+1;
            }
            int status = 0;
            for(int i = 0 ; i < BN;++i)
            {
                if(ansArr[i] == tempAns[i])
                {
                    continue;
                }
                else if(ansArr[i] > tempAns[i])
                {
                    status = 1;
                    break;
                }
                else
                {
                    continue;
                }
            }
            if(status)
            {
                for(int i = 0 ; i < BN;++i)
                {
                    ansArr[i] = tempAns[i];
                }
            }
        }
        return;
    }
    if(depth >= N)
    {
        return ;
    }
    visit[depth] = 1;
    backtrack(depth+1,choose+1);
    visit[depth] = 0;
    backtrack(depth+1,choose);








}

int main()
{
    int counts = 1;
    while(cin >> N && cin >> BN)
    {
        if(N == 0 && BN == 0) break;
        for(int i = 0  ; i < N;++i)
        {
            cin >> arr[i];
            visit[i] = 0;

        }

        cin >> M;
        //cout << "= = ?" <<endl;

        for(int i = 0 ; i < M;++i)
        {
            int t;
            cin >> t;
            sets[i].clear();
            int temps;
            for(int j = 0 ; j < t;++j)
            {
                cin >> temps;
                sets[i].insert(temps-1);

            }
            int cover;
            cin >> cover;
            coverArr[i] = cover;
        }

        ans = 0;
        backtrack(0,0);
        cout << "Case Number  " << counts++ <<endl;

        cout << "Number of Customers: " << ans <<endl;
        cout << "Locations recommended:";
        for(int i = 0 ; i < BN;++i)
        {
            cout << " " << ansArr[i];
        }
        cout << endl <<endl;
    }
    return 0;
}

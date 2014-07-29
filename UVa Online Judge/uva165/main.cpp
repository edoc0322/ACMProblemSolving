#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int h,k;
int visit[10000];
int choice[10];
int hasChoice[10];
int maxLen;
int ansChoice[10];
void backtrack1(int depth,int choose);
void backtrack2(int depth,int sums,int rest);
int main()
{
    while(cin >> h && cin >> k)
    {
        if(h == 0 && k == 0) break;
        maxLen = 0;
        memset(visit,0,sizeof(visit));
        memset(hasChoice,0,sizeof(hasChoice));
        memset(choice,0,sizeof(choice));
        backtrack1(0,0);
        for(int i = 0 ; i < k;++i)
        {
            cout << setw(3) << ansChoice[i];
        }
        cout << " ->";
        cout << setw(3) <<maxLen <<endl;
    }
    return 0;
}


void backtrack1(int depth,int choose)
{
    if(choice[0] >= 2) return;
    if(choose == k)
    {
        /*
        for(int i = 0 ; i < k;++i)
        {
            cout << " " << choice[i];
        }
        cout <<endl;
        */
        memset(visit,0,sizeof(visit));
        backtrack2(0,0,h);

        int len;
        for(len = 1 ; len < 10000;++len)
        {
            if(visit[len] != 1)
            {
                break;
                 //if(choice[0] == 1 && choice[1] == 2)
                 //{
                 //    cout << visit[len] << " ";
                // }
            }
        }
        //cout << "choice = " << choice[0]  << "  " << choice[1] <<endl;
        //cout << "len " << len <<endl;
        if(len-1 > maxLen)
        {
            //cout << "choice = " << choice[0]  << "  " << choice[1] <<endl;
            maxLen = len-1;
            for(int j = 0 ; j < k;++j)
            {
                ansChoice[j] = choice[j];
               // if(maxLen == 9999)
                    //cout <<"bose " << choice[j] << " " <<endl;
            }
        }

        return;
    }
    if(depth >= k) return;
    for(int i = 1 ; i <= 100;++i)
    {
        if(depth == 0)
        {
            choice[choose] = i;
            backtrack1(depth+1,choose+1);
            backtrack1(depth+1,choose);
        }
        else if(choose >= 1 && i > choice[choose-1])
        {
            //cout << "...\n";
            choice[choose] = i;
            backtrack1(depth+1,choose+1);
            backtrack1(depth+1,choose);
        }

    }
}

void backtrack2(int depth,int sums,int rest)
{
    if(depth == k)
    {
        visit[sums] = 1;
        return;
    }
    for(int i = 0 ; i <= h;++i)
    {
        if( rest >= i)
        {
            backtrack2(depth+1,sums + choice[depth]*i,rest-i);
        }

    }
}


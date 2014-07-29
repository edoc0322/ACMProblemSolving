#include <iostream>
#include <algorithm>
using namespace std;

struct CDs
{
    int w,c,seq;
} CD1[21];
//int w[21];
//int c[21];
int maxW;
int dif_W;
int maxC;
int N;
bool ans[21];
bool sol[21];
bool cmp(CDs a,CDs b)
{
    return a.w < b.w;
}

bool cmp2(CDs a,CDs b)
{
    return a.seq < b.seq;
}

void CD(int index , int W,int C)
{
    if(W > maxW)
    {
        return;
    }
    if(index == N)
    {
        //cout  << W <<endl;
        if(C >= maxC && maxW - W <= dif_W){

            dif_W = maxW-W;
            maxC = C;
            for(int i = 0 ; i < N;++i){
                sol[i] = ans[i];
            }
        }
        return;
    }
    ans[index] = true;
    CD(index+1,W+CD1[index].w,C+CD1[index].c);
    ans[index] = false;
    CD(index+1,W,C);
    return;
}


int main()
{
    int k;
    while(cin >> maxW)
    {
        cin >> N;
        for(int i = 0;i < N;++i)
        {
            cin >> CD1[i].w;
            CD1[i].c = 1;
            CD1[i].seq = i;
        }
        for(int i = 0 ; i <N;++i)
        {
            sol[i] = false;
            ans[i] = false;
        }
        sort(CD1,CD1+N,cmp);
        maxC = 0;
        dif_W = 2000000000;
        CD(0,0,0);
        int sum1 = 0;
        CDs CD2[21];
        int N2 = 0;
        for(int i = 0 ; i < N;++i)
        {
            if(sol[i])
            {
                sum1+= CD1[i].w;
                CD2[N2++] = CD1[i];
                //cout << CD1[i].w<<" ";
            }
        }
        sort(CD2,CD2+N2,cmp2);
        for(int i = 0 ; i < N2;++i)
        {
            cout << CD2[i].w << " ";
        }

        cout << "sum:"<<sum1<<endl;

    }
    return 0;
}

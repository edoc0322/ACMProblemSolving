#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int arr[31];
int carr[31];
void swapArr(int s1,int p1)
{
    int h = s1+p1/2;
    int temp;
    for(int i = s1 ; i <=h ;++i)
    {
        temp = arr[i];
        arr[i] = arr[p1-i];
        arr[p1-i] = temp;
    }
}

int main()
{
    char s[100];

    while(cin.getline(s,100))
    {
        int i = 0;
        char *temp;
        temp = strtok(s," ");
        carr[i] = arr[i] = atoi(temp);
        i++;
        while(1){
            temp = strtok(NULL," ");
            if(temp == NULL){break;}
            carr[i] = arr[i] = atoi(temp);
            i++;
        }
        int n = i;
        int maxV,maxI;
        int count = 0;
        int re[31];
        for(i = 0 ; i < n ; ++i)
        {
            maxI = -1;
            maxV = -1;
            for(int j = 0 ; j <=n-i-1;++j){
                if(arr[j] >= maxV){
                    maxI = j;
                    maxV = arr[j];
                }
            }
            //cout << maxI <<endl;
            if( maxI == n-i-1){
                continue;
            }
            else if(maxI == 0)
            {
                swapArr(0,n-i-1);
                re[count++] = i+1;
            }
            else
            {
                swapArr(0,maxI);
                re[count++] = n-maxI;
                swapArr(0,n-i-1);
                re[count++] = i+1;
            }
        }
        for(i = 0 ; i < n-1;++i)
        {
            cout << carr[i] << " ";
        }
        cout << carr[n-1] <<endl;
        for(i = 0 ; i < count;++i)
            cout << re[i] << " ";
        cout << "0\n";

    }
    return 0;
}

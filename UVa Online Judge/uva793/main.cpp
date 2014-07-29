#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;


int computer[1001];

int N;
int find_c(int i)
{
    int j = i;
    while(computer[j] != j)
        j = computer[j];
    return j;
}
void uni_c(int i , int j)
{
    int gmin = min(computer[i], computer[j]);
    int gmax = max(computer[i], computer[j]);

    for (int k=1; k<=N; k++)
        if (computer[k] == gmax)
            computer[k] = gmin;
}
int main()
{
    int testcase;
    char words[100];
    char* command;
    char* num1;
    char* num2;
    int n1,n2;
    int gans,wans;
    scanf("%d",&testcase);
    getchar();
    getchar();
    while(testcase>0)
    {

        gans = 0 ;
        wans = 0;
        while(gets(words) && (*words))
        {
            int space = 0;
            for(int i = 0 ; i < strlen(words); ++i)
            {
                if(words[i] == ' ')
                {
                    space = 1;
                    break;
                }
            }
            if(!space)
            {
                N = atoi(words);
                for(int i = 1 ; i <= N; ++i)
                {
                    computer[i] = i;
                }
            }
            else
            {
                command = strtok(words, " ");
                num1 = strtok(NULL," ");
                num2 = strtok(NULL," ");
                n1 = atoi(num1);
                n2 = atoi(num2);
                if(strcmp(command,"c")==0)
                {
                    int p = find_c(n1);
                    int q = find_c(n2);
                    if(p!=q)
                    {
                        uni_c(n1,n2);
                    }
                    /*
                    for(int i = 1 ; i <= N; i++)
                    {
                        int k = find_c(i);
                        if(k != computer[i])
                        {
                            uni_c(k,i);
                        }
                    }
                    */
                }

                else
                {
                    /*
                    for(int i = 1 ; i <= N; i++)
                    {
                        int k = find_c(i);
                        cout << "k and i  is " << k << "   " << i << endl;
                        if(k != computer[i])
                        {
                            uni_c(k,i);
                        }
                        k = find_c(i);
                        cout << "Then k and i  is " << k << "   " << i << endl;
                    }
                    */
                    int p = find_c(n1);
                    int q = find_c(n2);
                    if(p!=q)
                    {
                        ++wans;
                    }
                    else
                    {
                        ++gans;
                    }
                }

            }
        }
        cout << gans << "," << wans<<endl;
        if(testcase > 1)
        {
            cout << endl;
        }
        --testcase;
    }
    return 0;
}

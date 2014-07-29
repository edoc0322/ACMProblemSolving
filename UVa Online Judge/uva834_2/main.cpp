#include <stdio.h>
    #include <stdbool.h>

    int main(){
        int p,j;
        while(scanf("%d %d",&p,&j)==2){
            printf("[%d;",p/j);
            int div=p/j;
            int rem=p%j;
            p=j;
            j=rem;
            bool flag=false;
            while (p!=1){
               div=p/j;
               rem=p%j;
               if(flag)
                    printf(",");
               printf("%d",div);
               flag=true;
               p=j;
               j=rem;
            }
            printf("]\n");
        }
        return 0;
    }

#include <iostream>
#include <cmath>
using namespace std;

double area(double x1,double y1,double x2, double y2,double x3 , double y3)
{
    return fabs((y3 - y1)*(x2 - x1) - (y2 - y1)*(x3 - x1));
}

int main()
{
    int i,j,k,m;

    int n;
    double xy[15][2];
    char temp;
    while(cin >> n){
        if(!n) break;
        for(i = 0 ; i < n ;++i){
            cin >> temp;
            cin >> xy[i][0];
            cin >> xy[i][1];
        }
        int ans[3];
        double maxA = 0;
        int status;
        for(i = 0 ; i <n-2;++i){
            for(j = i+1;j<n-1;++j){
                for(k = j+1;k<n;++k){
                    status = 1;
                    for(m = 0 ; m < n ;++m){
                        if(m!=i && m!=j && m!=k){
                            if(area(xy[i][0],xy[i][1],xy[j][0],xy[j][1],xy[k][0],xy[k][1]) ==
                               area(xy[i][0],xy[i][1],xy[j][0],xy[j][1],xy[m][0],xy[m][1])+
                               area(xy[i][0],xy[i][1],xy[m][0],xy[m][1],xy[k][0],xy[k][1])+
                               area(xy[m][0],xy[m][1],xy[j][0],xy[j][1],xy[k][0],xy[k][1]))
                            {
                                status = 0;
                                break;
                            }
                        }
                    }
                    if(status){
                        if(area(xy[i][0],xy[i][1],xy[j][0],xy[j][1],xy[k][0],xy[k][1]) > maxA)
                        {
                            maxA = area(xy[i][0],xy[i][1],xy[j][0],xy[j][1],xy[k][0],xy[k][1]);
                            ans[0] = i;
                            ans[1] = j;
                            ans[2] = k;

                        }
                    }
                }
            }
        }
        cout << (char)(ans[0]+(int)'A');
        cout <<(char)(ans[1]+(int)'A');
        cout <<(char)(ans[2]+(int)'A')<<endl;

    }
    return 0;
}

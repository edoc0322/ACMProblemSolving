#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, cases = 0;
    int i;
    double x, y, d;
    pair<double, double> pt[1005];
    while(scanf("%d %lf", &n, &d) == 2) {
        if(n == 0)  break;
        int flag = 0;
        for(i = 0; i < n; i++) {
            scanf("%lf %lf", &x, &y);
            pt[i] = make_pair(x, y);
            if(y > d)
                flag = 1;

        }
        /*

12 21
27 1
16 19
12 6
-12 17
-2 16
-49 4
-13 12
46 12
48 4
-46 6
26 14
-22 10
        */
        if(flag) {
            printf("Case %d: %d\n", ++cases, -1);
            continue;
        }
        sort(pt, pt+n);
        for(i = 0; i < n; i++) {
            x = pt[i].first, y = pt[i].second;
            double td = sqrt(d*d - y*y) + 1e-8;
            pt[i] = make_pair(x-td, x+td);
            cout << "fir and sec = " << pt[i].first << " " << pt[i].second <<endl;
        }
        int ret = 0;
        double r = -(1e+60);
        i = 0;
        while(i < n) {
            while(i < n && pt[i].first <= r) {
                r = min(r, pt[i].second);
                i++;
            }
            r = pt[i].second;
            ret++;
            cout  << "What's right" << r <<endl;
        }
        printf("Case %d: %d\n", ++cases, ret-1);
    }
    return 0;
}

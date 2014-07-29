#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int MM;

int main()
{
    srand (time(NULL));
    cout << "How many test???" << endl;
    cout << "enter => ";
    int test;
    cin >> test;
    cout << "Max monkeys???" << endl;
    cout << "enter => ";
    int mmonk;
    cin >> mmonk;
    freopen("input.txt","w",stdout);
    for(int t = 0; t < test; t++){
        int monkeys = rand() % mmonk;
        int p = 2;
        cout << monkeys << " " << p << endl;
        MM = monkeys * 10;
        for(int j = 1; j <= monkeys; j++){
            int r1 = j * (MM / monkeys);
            int x = r1 - rand() % (2 * MM / monkeys);
            int y = r1 + rand() % (2 * MM / monkeys);
            if(x <= 0) x = 1;
            if(y >= MM) y = MM - 1;
            if(x > y) swap(x, y);
            if(x == y) x--;
            int z = rand() % (y - x) + 1;
            cout << z << " " << x << " " << y << endl;
        }
    }
    cout << "0" << endl;
    return 0;
}

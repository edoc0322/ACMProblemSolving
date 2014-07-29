#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
    int test;
    cin >> test;
    char temp;
    char str[100];
    cin.getline(str,100);
    double area;
    while(test--)
    {
        cin.getline(str,100);
        int count = 0;
        char *delim = " ";
        char * pch;
        pch = strtok(str,delim);
        double r[2];
        while (pch != NULL)
        {
            r[count] = atof(pch);
            pch = strtok (NULL, delim);
            count++;
        }
        if(count == 1){
            area = M_PI * r[0] * r[0] / 8;
            if(area <= 0){
                cout << "Impossible.\n";
            }
            else{
                cout.setf(ios::fixed);
                cout.precision(4);
                cout << area << endl;
            }
        }
        else{
            area = 2 * M_PI * r[0] * r[1];
            if(area <= 0){
                cout << "Impossible.\n";
            }
            else{
                cout.setf(ios::fixed);
                cout.precision(4);
                cout << area << endl;
            }
        }
    }

    return 0;
}

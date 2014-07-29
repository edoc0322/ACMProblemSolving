#include <iostream>
#include <string>
using namespace std;

string lcd[10][11][20];

int main()
{
    lcd[0][1][0] = "    ";
    lcd[0][1][1] = "   |";
    lcd[0][1][2] = "   |";
    lcd[0][1][3] = "    ";
    lcd[0][1][4] = "   |";
    lcd[0][1][5] = "   |";
    lcd[0][1][6] = "    ";

    lcd[0][1][0] = " -- ";
    lcd[0][1][1] = "   |";
    lcd[0][1][2] = "   |";
    lcd[0][1][3] = " -- ";
    lcd[0][1][4] = "|   ";
    lcd[0][1][5] = "|   ";
    lcd[0][1][6] = " -- ";



    return 0;
}

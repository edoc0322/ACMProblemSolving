#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define MAXN 201
#define MAXL 100001
#define EMPTY (-1)
using namespace std;
bool memo[MAXN + 1][MAXL + 1];
int choice[MAXN + 1][MAXL + 1];
int sumLength[MAXN + 1];
int cars[MAXN + 1], nCars, maxCars;

void solve_by_dynamic_programming(void)
{
    int cases, ferryLength, carLength;
    bool printBoredBlankLine = false;

    cin >> cases;
    while (cases--)
    {
        if (printBoredBlankLine)
            cout << endl;
        else
            printBoredBlankLine = true;

        cin >> ferryLength;
        ferryLength *= 100;

        nCars = 1;
        sumLength[0] = 0;
        while (cin >> carLength, carLength)
        {
            if (nCars < MAXN)
            {
                cars[nCars] = carLength;
                sumLength[nCars] = sumLength[nCars - 1] + carLength;
                nCars++;
            }
        }
        nCars--;

        pair < int, int > longest;

        memset(memo, false, sizeof(memo));
        memset(choice, EMPTY, sizeof(choice));

        memo[0][0] = true;
        for (int i = 0; i < nCars; i++)
            for (int j = 0; j <= ferryLength; j++)
                if (memo[i][j])
                {
                    if ((j + cars[i + 1]) <= ferryLength)
                    {
                        memo[i + 1][j + cars[i + 1]] = true;
                        choice[i + 1][j + cars[i + 1]] = 1;
                        longest = make_pair(i + 1, j + cars[i + 1]);
                    }

                    if ((sumLength[i] - j + cars[i + 1]) <= ferryLength)
                    {
                        memo[i + 1][j] = true;
                        choice[i + 1][j] = 0;
                        longest = make_pair(i + 1, j);
                    }
                }

        cout << longest.first << endl;
        string solution;
        for (int i = longest.first, j = longest.second; i > 0 &&
                        choice[i][j] != EMPTY; i--)
        {
            solution = (choice[i][j] ? "port\n" : "starboard\n" ) + solution;
            if (choice[i][j])
                j -= cars[i];
        }
        cout << solution;
    }
}

int main(int ac, char *av[])
{
    // 回溯法，差强人意，UVa RT：2.404s。
    // solve_by_backtrack();

    // 动态规划，UVa RT：0.536s。
    solve_by_dynamic_programming();

    return 0;
}

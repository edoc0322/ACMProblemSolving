#include <iostream>
#include <algorithm>
using namespace std;

struct player
{
    int ranks;

};
struct playerSum
{
    int index;
    int score = 0;
};
int Games;
int N;
int Scores;

bool cmp(playerSum p1,playerSum p2)
{
    if(p1.score != p2.score)
    {
        return p1.score > p2.score;
    }
    else
    {
        return p1.index < p2.index;
    }
}

int main()
{
    while(cin >> Games && cin >> N && Games && N)
    {
        player players[Games][N];
        playerSum playerSums[N];
        for(int i = 0 ; i < Games ;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                cin >> players[i][j].ranks;
                playerSums[j].score = 0;
                playerSums[j].index = j;
            }
        }
        cin >> Scores;
        for(int i = 0 ; i < Scores;++i)
        {
            int scoreN;
            cin >> scoreN;
            int scoresArr[scoreN];
            for(int j = 0 ; j < scoreN;++j)
            {
                cin >> scoresArr[j];
            }
            for(int j = 0 ; j < N ;++j)
            {
                for(int k = 0 ; k < Games ; ++k)
                {
                    if(players[k][j].ranks <= scoreN)
                    {
                        playerSums[j].score += scoresArr[players[k][j].ranks-1];
                    }
                }
            }
            /*
            cout << "scores";
            for(int j = 0 ; j < N;++j)
            {
                cout << " " << playerSums[j].score << " and index  " << playerSums[j].index;
            }
            cout <<endl;
            */
            sort(playerSums,playerSums+N,cmp);
            int maxScore = playerSums[0].score;
            for(int j = 0 ; j < N;++j)
            {
                if(playerSums[j].score == maxScore)
                {
                    if(j == 0)
                    {
                        cout << playerSums[j].index + 1;
                    }
                    else
                    {
                        cout << " " << playerSums[j].index + 1;
                    }
                }
            }
            cout <<endl;
            for(int j = 0 ; j < N ;++j)
            {
                playerSums[j].score = 0;
                playerSums[j].index = j;
            }


        }

    }
    return 0;
}

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int cardNum[200];
int flowerNum[200];
int main()
{
    string s;
    cardNum['1'] = 0;
    cardNum['2'] = 1;
    cardNum['3'] = 2;
    cardNum['4'] = 3;
    cardNum['5'] = 4;
    cardNum['6'] = 5;
    cardNum['7'] = 6;
    cardNum['8'] = 7;
    cardNum['9'] = 8;
    cardNum['T'] = 9;
    cardNum['J'] = 10;
    cardNum['Q'] = 11;
    cardNum['K'] = 12;
    flowerNum['C'] = 0;
    flowerNum['D'] = 13;
    flowerNum['H'] = 26;
    flowerNum['S'] = 39;
    while(cin >> s)
    {
        deque<string> que[13];
        int status[13];
        for(int i = 0 ; i < 13;++i)
        {
            status[i] = 0;
        }
        if (s== "#")
        {
            break;
        }
        que[0].push_front(s);
        for(int i = 1 ; i  < 13;++i)
        {
            cin >> s;
            que[i].push_front(s);
        }
        for(int j = 0 ; j < 3;++j)
        {
            for(int i = 0 ; i  < 13;++i)
            {
                cin >> s;
                que[i].push_front(s);
            }
        }
        string first = que[12].front();
        que[12].pop_front();
        int card = cardNum[first[0]];
        int card2 = flowerNum[first[1]] + card;
        int expoC = 1;
        string ansS = "";
        for(int i = 0 ; i < 51;++i)
        {
            cout << card << endl;
            status[card]++;
            que[card].push_back(first);
            first = que[card].front();
            que[card].pop_front();
            card = cardNum[first[0]];
            card2 = flowerNum[first[1]] + card;
            //cout <<  first <<"  " << status[card2] << " " << expoC <<endl;
            if(status[card] == 5)
            {
                ansS = first;
                break;
            }
            expoC++;

        }
        cout << expoC << "," << ansS <<endl;
    }


    return 0;
}

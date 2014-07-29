#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int test;
    cin >> test;
    for(int t = 0 ; t < test; ++t)
    {
        if(t > 0)
        {
            cout <<endl;
        }
        int field,sg,sb;
        cin >> field >> sg >> sb;
        multiset<int> gset;
        multiset<int> bset;
        int temp;
        for(int i = 0 ; i < sg; ++i)
        {
            cin >> temp;
            gset.insert(temp);
        }
        for(int i = 0 ; i < sb; ++i)
        {
            cin >> temp;
            bset.insert(temp);
        }
        while(1)
        {
            multiset<int>::reverse_iterator revG = gset.rbegin()
                                                   ,revB = bset.rbegin();
            int gn,bn;
            vector<int> battleP;
            for(int i = 0 ; i < field; ++i)
            {
                if(revG != gset.rend() && revB != bset.rend())
                {
                    gn = *revG;
                    bn = *revB;

                    gset.erase(--revG.base());
                    //gset.insert(gn - bn);
                    battleP.push_back(gn - bn);
                    bset.erase(--revB.base());
                }
            }
            for(int i = 0 ; i < battleP.size(); ++i)
            {
                //cout << battleP[i] <<endl;
                if(battleP[i] > 0)
                {
                    gset.insert(battleP[i]);
                }
                else if(battleP[i] < 0)
                {
                    bset.insert(-battleP[i]);
                }

            }
            if(gset.size()==0 || bset.size() == 0)
            {
                break;
            }


        }
        if(gset.size()== 0 && bset.size() == 0)
        {
            cout << "green and blue died" <<endl;
        }
        else if(gset.size() > 0)
        {
            cout << "green wins" <<endl;
            multiset<int>::reverse_iterator revG = gset.rbegin();
            while(revG != gset.rend())
            {
                cout << *revG <<endl;
                revG++;
            }
        }
        else
        {
            cout << "blue wins" <<endl;
            multiset<int>::reverse_iterator revB = bset.rbegin();
            while(revB != bset.rend())
            {
                cout << *revB <<endl;
                revB++;
            }
        }
    }
    return 0;
}

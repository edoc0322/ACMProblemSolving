#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;


set<int> nums;
int N;
int main()
{
    for(int i = 0 ; i <= 20;++i)
    {
        nums.insert(i*1);
        nums.insert(i*2);
        nums.insert(i*3);
    }
    nums.insert(50);
    int nums2[nums.size()];
    int counts = 0;
    for(set<int>::iterator i = nums.begin() ; i != nums.end();++i)
    {
        nums2[counts++] = *i;
    }
    int perC = 0;
    int cobC = 0;
    while(cin >> N && N > 0)
    {
        perC = 0;
        cobC = 0;

        if(N > 180)
        {
             cout << "THE SCORE OF " << N << " CANNOT BE MADE WITH THREE DARTS." <<endl;
             cout << "**********************************************************************" <<endl;
             continue;
        }
        for(int i = 0 ; i < nums.size();++i)
        {
            for(int j = i ; j < nums.size();++j)
            {
                for(int k = j ; k < nums.size();++k)
                {
                    if(nums2[i] + nums2[j] + nums2[k] == N)
                    {
                        cobC++;
                        if(i == j && i == k && i == j)
                        {
                            perC++;
                        }
                        else if(i == j || i == k || j == k)
                        {
                            perC+=3;
                        }
                        else
                        {
                            perC+=6;
                        }
                    }
                }
            }
        }
        if(perC)
        {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << N<<" IS " << cobC << "." <<endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << N << " IS " << perC << "." << endl;
        }
        else
        {
            cout << "THE SCORE OF " << N << " CANNOT BE MADE WITH THREE DARTS." <<endl;
        }
        cout << "**********************************************************************" <<endl;

    }
    cout << "END OF OUTPUT" <<endl;

    return 0;
}

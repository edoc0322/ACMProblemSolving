#include <iostream>

using namespace std;

int main()
{
    int M,N;
    while(cin >> M >> N)
    {
        if(M == 1 && N == 1) break;
        double fr = (double) M /(double) N;
        int midM = 1 , midN = 1;
        int leftM = 0,leftN = 1;
        int rightM = 1 , rightN = 0;
        while(1)
        {
            double mid = (double) (leftM + rightM) / (double) (leftN + rightN);
            int midM = (leftM + rightM);
            int midN = (leftN + rightN);
            if(mid < fr)
            {
                cout << "R";
                leftM = midM;
                leftN = midN;
            }
            else if(mid > fr)
            {
                cout << "L";
                rightM = midM;
                rightN = midN;
            }
            else
            {
                cout << endl;
                break;
            }
        }
    }
    return 0;
}

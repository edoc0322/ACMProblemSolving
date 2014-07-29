#include <iostream>
#include <iomanip>
using namespace std;

double des;
double tank,milePerGal,oriPrice;
int N;
double minPrice;

struct stop
{
    double dis,centPerGal;
};

stop stops[55];
void backtrack(int depth,double curTank,double curPrice)
{
    if(depth == N+1)
    {
        double totalPrice = oriPrice + curPrice;
        if(totalPrice < minPrice)
        {
            minPrice = totalPrice;
        }
        return ;
    }
    for(int i = depth+1 ; i <= N+1;++i)
    {
        double costGal = (stops[i].dis-stops[depth].dis) / milePerGal;
        double restGal = curTank - costGal;
        //cout << costGal << " "  << restGal << "  "<< i <<endl;
        if(restGal >= 0 && restGal <= tank/2)
        {
            double price = costGal * stops[i].centPerGal/100;
            if(i == N+1)
                backtrack(i,tank,curPrice+price);
            else
                backtrack(i,tank,curPrice+price+2.0);
        }

        else if( i == N+1 && restGal > 0)
        {
            backtrack(i,restGal,curPrice);
        }

    }
}
int main()
{
    int test = 1;
    while(cin >>des)
    {
        if(des == -1.0) break;
        cin >> tank >> milePerGal >> oriPrice >> N;
        stops[0].dis = 0;
        stops[0].centPerGal = 0;
        for(int i = 1 ; i <= N;++i)
        {
            cin >> stops[i].dis >> stops[i].centPerGal;
        }
        stops[N+1].dis = des;
        stops[N+1].centPerGal = 0;
        minPrice = 1e9;
        backtrack(0,tank,0);
        cout << "Data Set #" << test++ <<endl;
        cout << "minimum cost = $";
        cout << fixed << setprecision(2) << minPrice <<endl;
    }
    return 0;
}

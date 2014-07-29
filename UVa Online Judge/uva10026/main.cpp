#include <iostream>
#include <algorithm>

using namespace std;

#define MAXSIZE 1000

struct order
{
    int days;
    int fine;
    int index;
};

bool cmp(order x, order y)
{
    return x.days * y.fine < y.days * x.fine;
}

int main(int ac, char *av[])
{
    order orders[MAXSIZE];
    int capacity;
    int cases;

    cin >> cases;
    while (cases--)
    {
        cin >> capacity;
        int counter = 0;
        while (counter < capacity)
        {
            cin >> orders[counter].days >> orders[counter].fine;
            orders[counter].index = (counter + 1);
            counter++;
        }

        sort(orders, orders + capacity, cmp);

        for (int i = 0; i < capacity; i++)
        {
            cout << orders[i].index;
            if (i < (capacity - 1))
                cout << " ";
        }

        cout << endl;

        if (cases)
            cout << endl;
    }

    return 0;
}

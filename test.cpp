#include <iostream>
using namespace std;

int main()
{
    int coin_1 = 0;
    int coin_5 = 0;
    int coin_10 = 0;
    int coin_25 = 0;
    int counter = 0;
    int amount = 73;
    bool used = false;
    while (amount != 0)
    {
        if (amount - 25 >= 25)
        {
            amount = amount - 25;
            counter++;
            continue;
        }
        else if (amount - 10 >= 10)
        {
            amount = amount - 10;
            counter++;
            continue;
        }
        else if (amount - 5 >= 5)
        {
            amount = amount - 5;
            counter++;
            continue;
        }
        else if (amount - 1 >= 1)
        {
            amount = amount - 1;
            counter++;
        }
    }
    cout << counter;
}
/*
fibonacci, index we want is the input
calc fibonacci, then return index of that fibonacci
*/
#include <iostream>
using namespace std;

int fibonacci(int target)
{

    int prevY = 1, prevX = 0;
    int current;

    for (int i = 2; i <= target; i++)
    {
        current = prevY + prevX;
        prevX = prevY;
        prevY = current;
    }
    return current;
}

int main()
{
    int target;
    cin >> target;

    int a[] = {};

    cout << fibonacci(target) << endl;

    return 0;
}
#include <iostream>

using namespace std;

int fibonacci(int n)
{
    // Complete the function.
    int curr;
    int a[n] = {0, 1};
    int x = a[0];
    int y = a[1];

    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    for (int i = 2; i <= n; i++)
    {

        a[i] = x + y;

        // swapping
        int temp_change = x + y;
        x = y;
        y = temp_change;

        if (i == n)
        {
            curr = a[i];
        }
    }

    return curr;
}

int main()
{
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
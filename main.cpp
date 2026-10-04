#include <iostream>
using namespace std;

void printsort(int a[], int n)
{
    for (int z = 0; z < n; z++)
    {
        cout << a[z] << " ";
    }

    cout << endl;
}
void sort(int a[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                printsort(a, n);
            }
        }
    }
}

int main()
{

    // read length
    int n;
    cin >> n;

    int a[n]; // not strictly speaking legal but probably will do
    // int* a = new int[n]; // if not use this one which we will explain next week

    // read the n numbers of the array a
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, n);
}
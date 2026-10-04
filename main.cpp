#include <iostream>
using namespace std;

void sort(int a[], int n)
{
    // COMPLETE THIS
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
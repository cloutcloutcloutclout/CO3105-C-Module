#include <iostream>
using namespace std;

int main()
{

	// lab_3 learning how to make use of memory pointers?

	// question 1 using VALGRIND. -> install rq, do CW on laptop>>

	int *p;
	p = new int[10];
	p[0] = 999;
	cout << p[0] << endl;
	delete[] p;

	// test
}

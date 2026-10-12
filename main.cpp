#include <iostream>
using namespace std;

int main() {

	int* p;
	p = new int[10];
	p[0] = 999;
	cout << p[0] << endl;
	delete [] p;

}



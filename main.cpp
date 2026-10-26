#include <iostream>
using namespace std;

int main() {

	int i = 5;
	int *p; // decl pointer
	p = &i; // pointer to int i by &


	int *j;
	j = nullptr; // null pointer


	/*
	pointer of different types will be 

	double* dp;
	int* ip;



	if statement
	-------------
	if (p1 == p2)

	if (p1 == nullptr)


	*/


	// USING 'new' to obtain memory to use
	// USING 'delete' to remove return memory after usage

	int *pa{nullptr}, *pb{nullptr};

	pa = new int;  // allocates a int
	*pa = 2001; // value of pa -> pa is address 

	pb = new int[10]; // arr of 10
	pb[0] = -17;


	cout << *pa << endl;

	// removing
	delete pa; // delete one object from new int 
	pa = nullptr;

	

	// delete [] x; for array of obj




}



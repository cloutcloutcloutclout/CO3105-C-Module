#include <iostream>
using namespace std;



struct Employee {
	string fname;
	string lname;
	int age;
	double hwage;
};


int main() {

	Employee anEmployee;
	anEmployee.age = 33;
	cout << anEmployee.age << endl;
	
	return 0;
}


#include <iostream>
#include <stdlib.h> // for rand()
using std::cout;
using std::endl;

const int INITIALCAP = 10;

class DynArray
{
public:
	DynArray();
	~DynArray();
	DynArray(int size, int *initialData);
	DynArray(const DynArray &); // copy constructor, for operator / deep copy

	// void DynArray::copy(const DynArray& other); -> copy constructor

	bool set(int i, int v);
	int get(int i) const;
	int size() const;
	void print() const;

	void append(int x);
	DynArray &copy(const DynArray &); // copy operator / deep copy

private:
	int size_;
	int capacity_;
	int *array_;
};

// Constructor. Set array to initial size 0 and initial capacity INITIALCAP
DynArray::DynArray() : size_(0), capacity_(INITIALCAP), array_(new int[INITIALCAP])
{
	cout << "Default constructor" << endl;
}

// Destructor
DynArray::~DynArray()
{
	cout << "Destructor" << endl;
	delete[] array_;
}

// Set the array to the given size with the data copied from the pointer
// initialData. This pointer is supposed to point to an int array of the
// correct size.
// This is supposed to be called once only after zero-parameter constructor.
// If called at other times, old data is lost and there will be memory leak.
// Really should rewrite this as a parameterized constructor
DynArray::DynArray(int size, int *initialData)
{
	cout << "param ctor" << endl;
	capacity_ = size_ = size;
	array_ = new int[size];
	for (int i = 0; i < size; ++i)
		array_[i] = initialData[i];
}

// Print the contents of the array.
void DynArray::print() const
{
	cout << "[ ";
	for (int i = 0; i < size_; ++i)
		cout << array_[i] << " ";
	cout << "]" << endl;
}

// Set the i-th entry of the array to v.
bool DynArray::set(int i, int v)
{
	if (i < 0 || i > size_)
	{
		return false;
	}
	array_[i] = v;
	return true;
}

// Return the i-th entry of the array.
// Doesn't check bounds...
int DynArray::get(int i) const
{
	return array_[i];
}

// Return the number of elements stored.
int DynArray::size() const
{
	return size_;
}

// Add x to the end of the array, expanding if necessary.
void DynArray::append(int x)
{
	if (size_ == capacity_)
	{
		capacity_ *= 2;
		int *temp = new int[capacity_];
		for (int i = 0; i < size_; i++)
			temp[i] = array_[i];
		delete[] array_;
		array_ = temp;
	}
	array_[size_++] = x;
}

DynArray &DynArray::copy(const DynArray &other)
{
	if (&other != this)
	{
		delete[] array_;

		size_ = other.size_;
		capacity_ = other.capacity_;
		array_ = new int[capacity_];

		for (int i = 0; i < size_; i++)
		{
			// copying
			array_[i] = other.array_[i];
		}
	}
	return *this;
}

int main()
{

	// two primitive arrays
	int array1[10];
	for (int i = 0; i < 10; ++i)
	{
		array1[i] = rand() % 100;
	}
	int array2[20];
	for (int i = 0; i < 20; ++i)
	{
		array2[i] = rand() % 100;
	}

	// two DynArrays
	DynArray a1(10, array1);
	cout << "a1, a random array: ";
	a1.print();

	DynArray a2(20, array2);
	cout << "a2, another random array: ";
	a2.print();

	a2.copy(a1); // copy
	cout << "copied a1 to a2." << endl;
	cout << "a2 new size: " << a2.size() << endl;
	cout << "a2 new content: ";
	a2.print();

	a1.set(0, 888);
	cout << "a1 after modification: ";
	a1.print();
	cout << "a2 after a1's modification: ";
	a2.print();

	// try this and see what happens to a2?
	a1.append(999);
	a1.print();
	a2.print();

	return 0;
}

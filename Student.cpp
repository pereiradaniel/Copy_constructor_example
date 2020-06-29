// Student.cpp

#include <iostream>
using namespace std;
#include "Student.h"

// Default constructor:
Student::Student()
{
	no = 0;
	ng = 0;
	grade = nullptr;
}

Student::Student(int n)
{
	float g[] = { 0.0f };
	grade = nullptr;
	*this = Student(n, g, 0);
}


// Private member function:
// The following solution localizes the common coode in a private member fucntion named init() and calls this function from the copy constructor and the copy assignment operator:
void Student::init(const Student& source)
{
	no = source.no;
	ng = source.ng;
	if (source.grade != nullptr)
	{
		grade = new float[ng];
		for (int i = 0; i < ng; i++)
		{
			grade[i] = source.grade[i];
		}
	}
	else
	{
		grade = nullptr;
	}
}


// Copy constructor:
// Uses private member function solution init(source).
Student::Student(const Student& source)
{
	init(source);
}


// 3 arg constructor:
Student::Student(int sn, const float* g, int ng_)
{
	bool valid = sn > 0 && g != nullptr && ng_ >= 0;
	
	if (valid)
	{
		for (int i = 0; i < ng_ && valid; i++)
		{
			valid = g[i] >= 0.0f && g[i] <= 100.0f;
		}
	}

	if (valid)
	{
		// Acccept client's data:
		no = sn;
		ng = ng_;

		// Allocate dynamic memory:
		if (ng > 0)
		{
			grade = new float[ng];
			for (int i = 0; i < ng; i++)
			{
				grade[i] = g[i];
			}
		}
		else
		{
			grade = nullptr;
			*this = Student();
		}
	}
}


// Copy assignment operator:
// Uses private member function solution init(source).
Student& Student::operator=(const Student& source)
{
	// Check for self-assignment:
	// To trap a self-assignment from the client code (a = a):
	//		- Compare the address of the current object to the address of the source object.
	//		- If the addresses match, skip the assignment logic.
	//		- If this is not checked, the deallocation statement would release the memory holding the resource data and we would lose access to the source resource resulting in logic failing at grade[i] = source.grade[i];
	if (this != &source)
	{
		// Deallocate previously allocated dynamic memory:
		delete[] grade;
		init(source);
	}
	return *this;
}

Student::~Student ()
{
	delete[] grade;
	grade = nullptr;
}

void Student::display() const {
	if (no > 0) {
		cout << no << ":\n";
		cout.setf(ios::fixed);
		cout.precision(2);
		for (int i = 0; i < ng; i++) {
			cout.width(6);
			cout << grade[i] << endl;
		}
		cout.unsetf(ios::fixed);
		cout.precision(6);
	}
	else {
		cout << "no data available" << endl;
	}
}


int main() {
	float gh[] = { 89.4f, 67.8f, 45.5f };
	Student harry(1234, gh, 3);
	harry.display();
}

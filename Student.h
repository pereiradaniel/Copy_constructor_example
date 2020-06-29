// Student.h

class Student {
	int no;			// Student number.
	float* grade;	// Pointer for grades.
	int ng;			// Number of grades.
public:
	Student();									// Default constructor.
	Student(int n);								// 1 arg constructor
	Student(int sn, const float* g, int ng_);	// 3 arg constructor.
	
	// COPIES PROHIBITED:
	// To prohibit copying and/or copy assigning, the copy constructor and/or the copy assignment operator are declared as deleted members of the class:
	
	// Student& operator=(const Student&) = delete;
	
	Student(const Student&);	// COPY CONSTRUCTOR!
								// Takes the form:  Type(const Type&);

	Student& operator=(const Student&);		// COPY ASSIGNMENT OPERATOR!
								// Takes the form:  Type& operator=(const Type&);
	~Student();					// Destructor.
	void init(const Student& source);
	void display() const;		// Display function.
};
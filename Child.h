//Jasper Yeung
//CSS342
//Lab4
//Header file for Child class.
//Includes definition for constructors, a destructor, getters, and operator overloads.

#ifndef CHILD_H
#define CHILD_H
#include <iostream>
#include <string>
using namespace std;
class Child
{
public: 
	//Constructor
	Child();
	Child(const string& newFirst, const string& newLast, const int& newAge);
	//Destructor
	~Child();

	//Getter Methods
	string getFirstName() const;
	string getLastName() const;
	int getAge() const;

	//Operator Overloads
	bool operator==(const Child& child1) const;
	bool operator!=(const Child& child1) const;
	bool operator>(const Child& child1) const;
	bool operator<(const Child& child1) const;
	Child& operator=(const Child& child1);

	//Friend Method
	friend ostream& operator<<(ostream& outputStream, const Child& myChild);
	friend istream& operator>>(istream& inputStream, Child& myChild);
private:
	string firstname = "";
	string lastname = "";
	int age = 0;
};

#endif
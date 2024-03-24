//Jasper Yeung
//CSS342
//Lab4
//Implementation file for Child class

#ifndef CHILD_CPP
#define CHILD_CPP
#include "Child.h"

//Constructor
Child::Child(){}

Child::Child(const string& newFirst, const string& newLast, const int& newAge) 
{
	firstname = newFirst;
	lastname = newLast;
	age = newAge;
}

//Destructor
Child::~Child(){}

//Getter Methods
string Child::getFirstName() const
{
	return firstname;
}
string Child::getLastName() const
{
	return lastname;
}
int Child::getAge() const
{
	return age;
}

//Operator Overloads
bool Child::operator==(const Child& child1) const
{
	if (this->firstname == child1.firstname)
	{
		if (this->lastname == child1.lastname)
		{
			if (this->age == child1.age)
			{
				return true;
			}
		}
	}
	return false;
}

bool Child::operator!=(const Child& child1) const
{
	return !(*this == child1);
}

bool Child::operator>(const Child& child1) const
{
	if (this->lastname > child1.lastname)
	{
		return true;
	}
	else if(this->lastname == child1.lastname)
	{
		if (this->firstname > child1.firstname)
		{
			return true;
		}
		else if (this->firstname == child1.firstname)
		{
			if (this->age > child1.age)
			{
				return true;
			}
		}
	}
	return false;
}

bool Child::operator<(const Child& child1) const
{
	if (this->lastname < child1.lastname)
	{
		return true;
	}
	else if (this->lastname == child1.lastname)
	{
		if (this->firstname < child1.firstname)
		{
			return true;
		}
		else if (this->firstname == child1.firstname)
		{
			if (this->age < child1.age)
			{
				return true;
			}
		}
	}
	return false;
}

Child& Child::operator=(const Child& child1)
{
	this->firstname = child1.firstname;
	this->lastname = child1.lastname;
	this->age = child1.age;
	return *this;
}

//Friend Method
ostream& operator<<(ostream& outputStream, const Child& myChild)
{
	outputStream << myChild.getFirstName() << myChild.getLastName() << myChild.getAge();
	return outputStream;
}

istream& operator>>(istream& inputStream, Child& myChild)
{
	inputStream >> myChild.firstname >> myChild.lastname >> myChild.age;
	return inputStream;
}

#endif
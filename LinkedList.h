//Jasper Yeung
//CSS342
//Lab4
//LinkedList header file shows definition of LinkedList class.
//Also includes struct Node. The class is templatized.

#ifndef Linked_List_H
#define Linked_List_H
#include <string>
#include <iostream>
using namespace std;

template<class itemType>
class LinkedList
{
public: 
	//Constructors
	LinkedList();
	LinkedList(const LinkedList<itemType>& list1);

	//Destructors
	~LinkedList();

	//Methods
	bool BuildList(string fileName);
	bool Insert(itemType* obj);
	bool Remove(itemType target, itemType& result);
	bool Peek(itemType target, itemType& result) const;
	bool isEmpty() const;
	void DeleteList();
	bool Merge(LinkedList<itemType>& list1);

	//Operation Overloads
	LinkedList<itemType> operator+(const LinkedList<itemType>& list1) const;
	LinkedList<itemType>& operator+=(const LinkedList<itemType>& list1);
	bool operator==(const LinkedList<itemType>& list1) const;
	bool operator!=(const LinkedList<itemType>& list1) const;
	LinkedList<itemType>& operator=(const LinkedList<itemType>& list1);
	
	//Ostream Friend Method
	template<class t>
	friend ostream& operator<< (ostream& outputStream, const LinkedList<t>& myList);
private:
	struct Node
	{
		itemType* data = nullptr;
		Node* next = nullptr;
	};

	Node* Node1 = nullptr;
};
#endif
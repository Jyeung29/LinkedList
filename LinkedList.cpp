//Jasper Yeung
//BIS 342
//Lab4
//LinkedList implementations.
//Definitions include constructors, a destructor,
//BuildList(), Insert(), Remove(), Merge(), Peak(), and operator overloads.

#ifndef Linked_List_CPP
#define Linked_List_CPP
#include <fstream>
#include "LinkedList.h"

template<class itemType>
LinkedList<itemType>::LinkedList(){}

template<class itemType>
LinkedList<itemType>::LinkedList(const LinkedList<itemType>& list1)
{
	*this = list1;
}

//Destructors
template<class itemType>
LinkedList<itemType>::~LinkedList()
{
	this->DeleteList();
}

//Methods
template<class itemType>
bool LinkedList<itemType>::BuildList(string fileName)
{
	string myText;
	itemType myData;
	ifstream MyReadFile(fileName);
	if (!MyReadFile.good()) //checks if filename is found
	{
		MyReadFile.close();
		return false;
	}
	Node* currentNode = Node1;
		//Create subsequent nodes
	while (getline(MyReadFile, myText))
	{
		MyReadFile >> myData;
		Insert(&myData); //has to parse through entire list since inputs can be out of order and have duplicates
	}
	MyReadFile.close();
	return true;
}

template<class itemType>
bool LinkedList<itemType>::Insert(itemType* obj)
{
	if (Node1 == nullptr) //If linked list is empty
	{
		Node1 = new Node();
		Node1->data = new itemType(*obj);
	}
	else //There are at least 1 or more nodes
	{
		bool done = false;
		Node* currentNode = Node1;
		while (!done)
		{
			if (*(currentNode->data) < *obj) //new value is greater than current one
			{
				if (currentNode->next == nullptr) //at the end of the linked list
				{
					currentNode->next = new Node();
					currentNode->next->data = new itemType(*obj);
					currentNode->next->next = nullptr;
					done = true;
				}
				else if (*(currentNode->next->data) > *obj) //insert between two nodes
				{
					Node* temp = currentNode->next;
					currentNode->next = new Node();
					currentNode->next->data = new itemType(*obj);
					currentNode->next->next = temp;
					done = true;
				}
				else //if value is greater than previous node but is either equal or greater than next node
				{
					currentNode = currentNode->next;
				}
			}
			else if (*(currentNode->data) > *obj) //case for if new node is less than Node1
			{
				Node* temp = Node1;
				Node1 = new Node();
				Node1->data = new itemType(*obj);
				Node1->next = temp;
				done = true;
			}
			else if(*(currentNode->data) == *obj) //value is same as currentNode
			{
				return false;
			}
		}
	}
	return true;
}

template<class itemType>
bool LinkedList<itemType>::Remove(itemType target, itemType& result)
{
	Node* currentNode = Node1;
	Node* previousNode = nullptr; //kept track for possible reassignment of node's next
	bool done = false;
	if (currentNode == nullptr) //calling on an empty linked list
	{
		return false;
	}
	while (!done)
	{
		if (*(currentNode->data) == target) //target is in list on current node
		{
			if(previousNode != nullptr && currentNode->next != nullptr) //middle of two nodes
			{
				previousNode->next = currentNode->next; //shifts next pointer of previous node to next node
				result = *(currentNode->data);
				delete currentNode->data;
				delete currentNode;
				done = true;
			}
			else if (currentNode->next == nullptr) //at end of linked list
			{
				if (previousNode == nullptr) //a 1 node linked list
				{
					result = *(currentNode->data);
					delete currentNode->data;
					delete currentNode->next;
					delete currentNode;
					Node1 = nullptr; //Make sure if Node1 is accessed that nothing is retrieved
					done = true;
				}
				else //end of a multi node linked list
				{
					previousNode->next = nullptr;
					result = *(currentNode->data);
					delete currentNode->data;
					delete currentNode->next;
					delete currentNode;
					done = true;
				}
			}
			else //at beginning of linked list with one or more nodes
			{
				result = *(currentNode->data);
				delete currentNode->data;
				Node1 = currentNode->next;
				delete currentNode;
				done = true;
			}
		}
		else if(currentNode->next != nullptr) //not at the end of list so move to next node and keep track of previous node
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
		}
		else //at the end of the list
		{
			return false;
		}
	}
	return true;
}

template<class itemType>
bool LinkedList<itemType>::Peek(itemType target, itemType& result) const
{
	Node* currentNode = Node1;
	bool done = false;
	if (currentNode == nullptr) //calling on an empty linked list
	{
		return false;
	}
	while (!done)
	{
		if (*(currentNode->data) == target) //target is in list on current node
		{
			result = *(currentNode->data);
			done = true;
		}
		else if (currentNode->next != nullptr) //not at the end of list so move to next node
		{
			currentNode = currentNode->next;
		}
		else //at the end of the list
		{
			return false;
		}
	}
	return true;
}

template<class itemType>
bool LinkedList<itemType>::isEmpty() const
{
	if (Node1 == nullptr)
	{
		return true;
	}
	else
	{
	return false;
	}
}

template<class itemType>
void LinkedList<itemType>::DeleteList()
{
	bool done = false;
	if (!this->isEmpty()) {
		while (!done)
		{
			delete Node1->data; //Delete the node's data
			Node1->data = nullptr;
			if (Node1->next != nullptr) //If there are still more than 1 node
			{
				Node* temp = Node1; //keep track of to be deleted node
				Node1 = Node1->next; //Node1 moves onto next node
				delete temp; //delete previous node
			}
			else //if the current node is last to be deleted
			{
				delete Node1->next;
				delete Node1; //flag Node1 memory for use
				Node1 = nullptr; //makes sure Node1 is actually empty
				done = true;
			}
		}
	}
}

template<class itemType>
bool LinkedList<itemType>::Merge(LinkedList& list1)
{
	if (list1.isEmpty())
	{
		return true;
	}
	if (this == &list1) //makes sure the list does not merge itself
	{
		return false;
	}
	if (this->isEmpty()) //if the current list is empty then a simple assignment is enough to merge
	{
		this->Node1 = list1.Node1;
		list1.Node1 = nullptr;
		return true;
	}
	Node* newNode = list1.Node1; //keep track of list1 node to be added 
	Node* currentNode = this->Node1; //node to be parsed through
	Node* previousNode = nullptr; //node before currentNode
	while (newNode != nullptr) //parses through list1 that has 1 or more nodes
	{
		bool done = false;
		while (!done)  //parses through this list
		{
			if (*(currentNode->data) < *(newNode->data)) //new value is greater than current one
			{
				if (currentNode->next == nullptr) //at the end of the linked list
				{
					if (newNode == list1.Node1) //the new node is also the beginning of list1
					{
						list1.Node1 = list1.Node1->next; //shifts list1 node
					}
					currentNode->next = newNode; //insert newNode at end of linked list
					newNode = newNode->next; //moves on to next node to be added
					currentNode->next->next = nullptr; //makes sure the newNode's next ptr is nullptr
					done = true;
					previousNode = currentNode; //stores currentNode in previousNode
					currentNode = currentNode->next; //stores the just merged node into currentNode
					}
					else if (*(currentNode->next->data) > *(newNode->data)) //insert between two nodes
					{
						if (newNode == list1.Node1) //the new node is also the beginning of list1
						{
							list1.Node1 = list1.Node1->next; //shifts list1 node
						}
						Node* temp = currentNode->next; //stores the greater node's address
						previousNode = currentNode; //lesser node's next ptr points to the new node
						currentNode->next = newNode;
						currentNode = currentNode->next;
						newNode = newNode->next; //goes to next node to be added
						currentNode->next = temp; //connects inserted node to greater node
						done = true;
					}
				else //if value is greater than previous node but is either equal or greater than next node
				{
					previousNode = currentNode;
					currentNode = currentNode->next;
				}
			}
			else if (*(currentNode->data) > *(newNode->data)) //case for if new node is less than Node1
			{
				if (newNode == list1.Node1) //the new node is also the beginning of list1
				{
					list1.Node1 = list1.Node1->next; //shifts list1 node
				}
				Node* temp = this->Node1;
				this->Node1 = newNode;
				newNode = newNode->next;
				this->Node1->next = temp;
				done = true;
				currentNode = this->Node1;
			}
			else if (*(currentNode->data) == *(newNode->data)) //value is same as currentNode
			{
				if (newNode->next != nullptr) //there are more nodes to be parsed
				{
					Node* temp = newNode->next;
					list1.Node1 = newNode->next;
					delete newNode->data;
					delete newNode;
					newNode = temp;
				}
				else //no more nodes to parse
				{
					delete newNode->data;
					delete newNode;
					list1.Node1 = nullptr;
					newNode = nullptr;					}
					done = true; //escape parsing of current linked list for the new node
				}
			}
	}
	if (!list1.isEmpty())
	{
		return false;
	}
	else
	{
		return true;
	}
}

//Operation Overloads
template<class itemType>
LinkedList<itemType> LinkedList<itemType>::operator+(const LinkedList& list1) const
{
	LinkedList newList;
	newList += list1;
	newList += *this;
	return newList;
}

template<class itemType>
LinkedList<itemType>& LinkedList<itemType>::operator+=(const LinkedList& list1)
{
	Node* newNode = list1.Node1; //keeps track of the node to be added
	Node* currentNode = this->Node1;
	while (newNode != nullptr)
	{
		if (this->Node1 == nullptr) //If linked list is empty
		{
			this->Node1 = new Node();
			this->Node1->data = new itemType(*(newNode->data));
			newNode = newNode->next;
			currentNode = this->Node1;
		}
		else //There are at least 1 or more nodes
		{
			if (*(currentNode->data) < *(newNode->data)) //new value is greater than current one
			{
				if (currentNode->next == nullptr) //at the end of the linked list
				{
					currentNode->next = new Node();
					currentNode->next->data = new itemType(*(newNode->data));
					currentNode->next->next = nullptr;
					currentNode = currentNode->next;
					newNode = newNode->next;
				}
				else if (*(currentNode->next->data) > *(newNode->data)) //insert between two nodes
				{
					Node* temp = currentNode->next;
					currentNode->next = new Node();
					currentNode->next->data = new itemType(*(newNode->data));
					currentNode->next->next = temp;
					currentNode = currentNode->next;
					newNode = newNode->next;
				}
				else //if value is greater than previous node but is either equal or greater than next node
				{
					currentNode = currentNode->next;
				}
			}
			else if (*(currentNode->data) > *(newNode->data)) //case for if new node is less than Node1
			{
				Node* temp = Node1;
				Node1 = new Node();
				Node1->data = new itemType(*(newNode->data));
				Node1->next = temp;
				currentNode = this->Node1;
				newNode = newNode->next;
			}
			else if (*(currentNode->data) == *(newNode->data)) //value is same as currentNode
			{
				newNode = newNode->next;
			}
		}
	}
	return *this;
}

template<class itemType>
bool LinkedList<itemType>::operator==(const LinkedList<itemType>& list1) const
{
	Node* currentNode1 = list1.Node1;
	Node* currentNode2 = this->Node1;
	while (currentNode1 != nullptr && currentNode2 != nullptr) //runs until ends of either lists
	{
		if (*(currentNode1->data) != *(currentNode2->data)) //node is not the same
		{
			return false;
		}
		else if((currentNode1->next == nullptr && currentNode2->next != nullptr) //If one list ends earlier then the other
			|| (currentNode1->next != nullptr && currentNode2->next == nullptr))
		{
			return false;
		}
		else //is still equal
		{
			currentNode1 = currentNode1->next;
			currentNode2 = currentNode2->next;
		}
	}
	return true;
}

template<class itemType>
bool LinkedList<itemType>::operator!=(const LinkedList<itemType>& list1) const
{
	return !(*this == list1);
}

template<class itemType>
LinkedList<itemType>& LinkedList<itemType>::operator=(const LinkedList<itemType>& list1)
{
	if (!this->isEmpty()) 
	{
		this->DeleteList();
	}
	*this += list1;
	return *this;
}

//Ostream Friend Method
template<class itemType>
ostream& operator<<(ostream& outputStream, const LinkedList<itemType>& myList)
{
	typename LinkedList<itemType>::Node* currentNode = myList.Node1;
	if (currentNode != nullptr) { //make sure there is at least 1 node
		outputStream << *(currentNode->data);
		while (currentNode->next != nullptr) //if there is another node
		{
			currentNode = currentNode->next;
			outputStream << *(currentNode->data);
		}
	}
	return outputStream;
}


#endif
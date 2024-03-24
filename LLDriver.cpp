//Jasper Yeung
//CS342
//Lab4
//Driver file for implementation of LinkedLists and Child class.
//Contains specified example output and additional tests including
//reading file inputs in BuildList() for multiple class types.

#ifndef L_L_DRIVER_CPP
#define L_L_DRIVER_CPP
#include "Child.cpp"
#include "LinkedList.cpp"

int main()
{
	Child c1("Angie", "Ham", 7), c2("Pradnya", "Dhala", 8),
		c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6);
	Child c5("Piqi", "Tangi", 7), c6("Pete", "Rose", 13),
		c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
	Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;
	LinkedList<Child> class1, class2, soccer, chess;
	int a = 1, b = -1, c = 13;
	class1.Insert(&c1);
	class1.Insert(&c2);
	class1.Insert(&c3);
	class1.Insert(&c4);
	class1.Insert(&c5);
	class1.Insert(&c6);
	class1.Insert(&c5);
	cout << "class1: " << class1 << endl;
	if (class1.Insert(&c1))
	{
		cout << "ERROR::: Duplicate" << endl;
	}
	class2.Insert(&c4);
	class2.Insert(&c5);
	class2.Insert(&c6);
	class2.Insert(&c7);
	class2.Insert(&c10);
	cout << "Class2: " << class2 << endl;
	class1.Merge(class2);
	class2.Merge(class1);
	class1.Merge(class2);
	class1.Merge(class1);
	cout << "class1 and 2 Merged: " << class1 << endl;
	if (!class2.isEmpty())
	{
		cout << "ERROR:: Class2 should be empty empty" << endl;
	}
	class1.Remove(c4, c11);
	class1.Remove(c5, c11);
	class1.Remove(c11, c11);
	if (class1.Remove(c1, c11))
	{
		cout << "Removed from class1, student " << c11 << endl;
	}
	cout << "class1: " << class1 << endl;
	soccer.Insert(&c6);
	soccer.Insert(&c4);
	soccer.Insert(&c9);
	cout << "soccer: " << soccer << endl;
	soccer += class1;
	cout << "soccer += class1 : " << soccer << endl;
	LinkedList<Child> football = soccer;
	if (football == soccer)
	{
		cout << "football: " << football << endl;
	} if (
		football.Peek(c6, c11))
	{
		cout << c11 << " is on the football team" << endl;
	}
	soccer.DeleteList();
	if (!soccer.isEmpty())
	{
		cout << "ERROR: soccer should be empty" << endl;
	}
	LinkedList<int> numbers;
	numbers.Insert(&a);
	numbers.Insert(&b);
	numbers.Insert(&c);
	cout << "These are the numbers: " << numbers << endl << endl;
	numbers.DeleteList();

	cout << endl << "Further Testing of LinkedList: " << endl;

	LinkedList<int> list1;
	LinkedList<int> list2;
	LinkedList<Child> childList;
	LinkedList<Child> childList2 = childList;
	LinkedList<string> stringList;
	LinkedList<char> charList;

	//Test BuildList
	cout << "Building list1 with noInputs.txt: " << list1.BuildList("noInputs.txt") << endl; //blank txt document
	cout << list1 << endl;
	cout << "Building list1 with invalid filename: " << list1.BuildList("fjkdalfj") << endl;
	cout << list1 << endl;
	cout << "Building list1 with evenInputs.txt: " << list1.BuildList("evenInputs.txt") << endl; //has duplicate 4 and out of order and even
	cout << list1 << endl;
	cout << "Building list1 with oddInputs.txt: " << list1.BuildList("oddInputs.txt") << endl; //has duplicate 5 and out of order and odd
	cout << list1 << endl;
	cout << "Building list2 with mixedInputs.txt: " << list2.BuildList("mixedInputs.txt") << endl; //has mixed int values including a -4
	cout << list2 << endl;
	cout << "Building childList with childInputs.txt: " << childList.BuildList("childInputs.txt") << endl; //has elements with same childs, childs with 1 different parameter from another
	cout << childList << endl;
	cout << "Building childList with childInputs2.txt: " << childList2.BuildList("childInputs2.txt") << endl;
	cout << childList2 << endl;
	cout << "Building stringList with stringInputs.txt: " << stringList.BuildList("stringInputs.txt") << endl;
	cout << stringList << endl;
	cout << "Building charList with characterInputs.txt: " << charList.BuildList("characterInputs.txt") << endl;
	cout << charList << endl;

	//Test insert
	int var = 4;
	cout << "Inserting duplicate 4: " << list1.Insert(&var) << endl; //test insert duplicate
	cout << list1 << endl;
	var = -1;
	cout << "Inserting new -1: " << list1.Insert(&var) << endl; //test insert beginning
	cout << list1 << endl;
	var = 25003;
	cout << "Inserting 25003: " << list1.Insert(&var) << endl; //test insert end
	cout << "list1: " << list1 << endl;
	var = 28;
	cout << "Inserting 28: " << list1.Insert(&var) << endl; //test insert between
	cout << "list1: " << list1 << endl;
	string stringVar = "right";
	cout << "Inserting 'right' into stringList: " << stringList.Insert(&stringVar) << endl;
	cout << stringVar << endl;
	char charVar = 'q';
	cout << "Inserting 'q' into charList: " << charList.Insert(&charVar) << endl;
	cout << charList << endl << endl;

	//Test peek
	int result = 0;
	cout << "Peeking list1 4: " << list1.Peek(4, result) << " result: " << result << endl;
	result = 0;
	cout << "Peeking 200 not in list1: " << list1.Peek(200, result) << " result: " << result << endl;
	char charResult = ' ';
	cout << "Peeking 'T' in charList: " << charList.Peek('T', charResult) << " result: " << charResult << endl;
	charResult = ' ';
	cout << "Peeking 'z' not in charList: " << charList.Peek('z', charResult) << " result: " << charResult << endl;
	string stringResult = "";
	cout << "Peeking 'Hello' in stringList: " << stringList.Peek("Hello", stringResult) << stringResult << endl;
	stringResult = "";
	cout << "Peeking 'wrong' not in stringList : " << stringList.Peek("wrong", stringResult) << " result : " << stringResult << endl << endl;
	
	//Test remove
	result = 0;
	cout << "Removing list1 4: " << list1.Remove(4, result) << " result: " << result << endl; //test remove present
	result = 0;
	cout << "Removing list1 1000 not in list: " << list1.Remove(1000, result) << " result: " << result << endl; //test remove on non-existent element
	charResult = ' ';
	cout << "Removing charList 'T': " << charList.Remove('T', charResult) << " result: " << result << endl; //test remove present
	charResult = ' ';
	cout << "Removing charList 'x' not in list: " << charList.Remove('x', charResult) << " result: " << result << endl; //test remove on non-existent element
	stringResult = "";
	cout << "Removing stringList 'Hello': " << stringList.Remove("Hello", stringResult) << " result: " << result << endl; //test remove present
	stringResult = "";
	cout << "Removing stringList 'wrong' not in list: " << stringList.Remove("wrong", stringResult) << " result: " << result << endl; //test remove on non-existent element

	//Test merge
	cout << "list1: " << list1 << endl;
	cout << "list2: " << list2 << endl;
	cout << "Merging list1 and list2: " << list1.Merge(list2) << endl; //test merge two different lists
	cout << "list1: " << list1 << endl;
	cout << "Merging list1 and list1: " << list1.Merge(list1) << endl; //test merge into self
	cout << "list1: " << list1 << endl;
	cout << "list2: " << list2 << endl;
	cout << "Merging list1 and list2: " << list1.Merge(list2) << endl; //test empty merge
	list2 = list1;
	cout << "list1: " << list1 << endl;
	cout << "list2: " << list2 << endl; 
	cout << "Merging same list: " << list1.Merge(list2) << endl; //merging same element list
	cout << "list1: " << list1 << endl;
	cout << "list2: " << list2 << endl;

	LinkedList<string> stringList2;
	LinkedList<char> charList2;
	stringList2.BuildList("stringInputs2.txt");
	charList2.BuildList("charInpputs2.txt");
	cout << "stringList: " << stringList << endl;
	cout << "stringList2: " << stringList2 << endl;
	cout << "Merging stringList and stringList2: " << stringList.Merge(stringList2) << endl;
	cout << "stringList: " << stringList << endl;
	cout << "stringList2: " << stringList2 << endl;
	cout << "charList: " << charList << endl;
	cout << "charList2: " << charList2 << endl;
	cout << "Merging charList and charList2: " << charList.Merge(charList2) << endl;
	cout << "charList: " << charList << endl;
	cout << "charList2: " << charList2 << endl << endl;

	//test == and !=
	LinkedList<int> list3, list4, list5;
	list3.BuildList("evenInputs.txt");
	list4.BuildList("evenInputs.txt");
	list5.BuildList("oddInputs.txt");
	cout << "list3: " << list3 << endl;
	cout << "list4: " << list4 << endl;
	cout << "list5: " << list5 << endl;
	cout << "list3 == list4: " << (list3 == list4) << endl;
	cout << "list3 == list5: " << (list3 == list5) << endl;
	cout << "list3 != list4: " << (list3 != list4) << endl;
	cout << "list3 != list5: " << (list3 != list5) << endl;
	LinkedList<char> charList3 = charList;
	LinkedList<string> stringList3 = stringList;
	charList2.BuildList("characterInputs2.txt");
	stringList2.BuildList("stringInputs2.txt");
	cout << "charList: " << charList << endl;
	cout << "charList2: " << charList2 << endl;
	cout << "charList3: " << charList3 << endl;
	cout << "charList == charList2: " << (charList == charList2) << endl;
	cout << "charList == charList3: " << (charList == charList3) << endl;
	cout << "charList != charList2: " << (charList != charList2) << endl;
	cout << "charList != charList3: " << (charList != charList3) << endl;
	cout << "stringList: " << stringList << endl;
	cout << "stringList2: " << stringList2 << endl;
	cout << "stringList3: " << stringList3 << endl;
	cout << "stringList == stringList2: " << (stringList == stringList2) << endl;
	cout << "stringList == stringList3: " << (stringList == stringList3) << endl;
	cout << "stringList != stringList2: " << (stringList != stringList2) << endl;
	cout << "stringList != stringList3: " << (stringList != stringList3) << endl << endl;

	//test += + =
	cout << "list3: " << list3 << endl;
	cout << "list5: " << list5 << endl;
	list3 += list5; //test different lists +=
	cout << "list3: " << list3 << endl;
	cout << "list5: " << list5 << endl;
	cout << "list4: " << list4 << endl;
	list4 = list3; //test =
	cout << "list4: " << list4 << endl;
	cout << "list3: " << list3 << endl;
	list3 += list4; //test same lists +=
	cout << "list4: " << list4 << endl;
	cout << "list3: " << list3 << endl;

	string temp = "iteration";
	stringList2.Insert(&temp);
	cout << "stringList: " << stringList << endl;
	cout << "stringList2: " << stringList2 << endl;
	stringList += stringList2; //test different lists +=
	cout << "stringList: " << stringList << endl;
	cout << "stringList2: " << stringList2 << endl;
	cout << "stringList3: " << stringList3 << endl;
	stringList3 = stringList; //test =
	cout << "stringList: " << stringList << endl;
	cout << "stringList3: " << stringList3 << endl;
	stringList3 += stringList; //test same lists +=
	cout << "stringList: " << stringList << endl;
	cout << "stringList3: " << stringList3 << endl;

	cout << "charList: " << charList << endl;
	cout << "charList2: " << charList2 << endl;
	charList += charList2; //test different lists +=
	cout << "charList: " << charList << endl;
	cout << "charList2: " << charList2 << endl;
	cout << "charList3: " << charList3 << endl;
	stringList3 = stringList; //test =
	cout << "charList: " << charList << endl;
	cout << "charList3: " << charList3 << endl;
	charList3 += charList; //test same lists +=
	cout << "charList: " << charList << endl;
	cout << "charList3: " << charList3 << endl;
	return 0;
}
#endif
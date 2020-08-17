#include <iostream>
#include "Vector.h"
#include "List.h"
using namespace std;

int main()
{
	
	cout << "This is the test program to test our added functions to the Vector.h and List.h" << endl;
	cout << "The code begins by testing the Vector.h by calling several functions including replaceAll and removeAll" << endl;
	cout << "Our test uses 2 different data types; characters and integers: " << endl;
	cout << endl;
	cout << "Vector.h test with characters: " << endl;
	//------------------------------ Vector --------------------------------
	Vector<char> v1;
	
	cout << "Adding elements to an empty vector: " << endl;
	v1.push_back('a');
	v1.print();
	v1.push_back('b');
	v1.print();
	v1.push_back('a');
	v1.print();
	v1.push_back('c');
	v1.print();
	v1.push_back('a');
	v1.print();
	v1.push_back('d');
	v1.print();


	cout << endl;
	cout << "Testing replaceAll function; Replacing all 'a' with 'e'" << endl;
	int temp1 = v1.replaceAll('a', 'e');
	v1.print();
	cout << "Number of the modified elements: " << endl;
	cout << temp1 << endl;
	
	cout << endl;

	cout << "Testing removeAll function; Removing all 'e'" << endl;
	int temp2 = v1.removeAll('e');
	v1.print();
	cout << "Number of the modified elements: " << endl;
	cout << temp2 << endl;
	cout << endl;


	cout << "Vector.h test with integers: " << endl;
	Vector<int> v2;
	
	cout << "Adding elements to an empty vector: " << endl;
	v2.push_back(1);
	v2.print();
	v2.push_back(2);
	v2.print();
	v2.push_back(3);
	v2.print();
	v2.push_back(4);
	v2.print();
	v2.push_back(2);
	v2.print();
	v2.push_back(4);
	v2.print();
	v2.push_back(5);
	v2.print();
	v2.push_back(7);
	v2.print();

	cout << endl;
	cout << "Testing replaceAll function; Replacing all 2 with 4" << endl;
	int temp3 = v2.replaceAll(2, 4);
	v2.print();
	cout << "Number of the modified elements: " << endl;
	cout << temp3 << endl;
	
	cout << endl;

	cout << "Testing removeAll function; Removing all 4" << endl;
	int temp4 = v2.removeAll(4);
	v2.print();
	cout << "Number of the modified elements: " << endl;
	cout << temp4 << endl;
	cout << endl;
	cout << endl;

	
	//------------------------------ List --------------------------------
	cout << "---------------------------------------------------------------------------- " << endl;
	cout << endl;
	cout << endl;
	cout << "Now, the codes tests the List.h just like above. Therefore the results are the same: " << endl;
	List<char> L1;
	
	cout << "Adding elements to an empty List: " << endl;
	L1.push_back('a');
	L1.print();
	L1.push_back('b');
	L1.print();
	
	L1.push_back('a');
	L1.print();
	L1.push_back('c');
	L1.print();
	L1.push_back('a');
	L1.print();
	L1.push_back('d');
	L1.print();


	cout << endl;
	cout << "Testing replaceAll function; Replacing all 'a' with 'e'" << endl;
	int ttemp1 = L1.replaceAll('a', 'e');
	L1.print();
	cout << "Number of the modified elements: " << endl;
	cout << ttemp1 << endl;
	
	cout << endl;

	cout << "Testing removeAll function; Removing all 'e'" << endl;
	int ttemp2 = L1.removeAll('e');
	L1.print();
	cout << "Number of the modified elements: " << endl;
	cout << ttemp2 << endl;
	cout << endl;


	cout << "List.h test with integers: " << endl;
	List<int> L2;
	
	cout << "Adding elements to an empty List: " << endl;
	L2.push_back(1);
	L2.print();
	L2.push_back(2);
	L2.print();
	L2.push_back(3);
	L2.print();
	L2.push_back(4);
	L2.print();
	L2.push_back(2);
	L2.print();
	L2.push_back(4);
	L2.print();
	L2.push_back(5);
	L2.print();
	L2.push_back(7);
	L2.print();

	cout << endl;
	cout << "Testing replaceAll function; Replacing all 2 with 4" << endl;
	int ttemp3 = L2.replaceAll(2, 4);
	L2.print();
	cout << "Number of the modified elements: " << endl;
	cout << ttemp3 << endl;
	
	cout << endl;

	cout << "Testing removeAll function; Removing all 4" << endl;
	int ttemp4 = L2.removeAll(4);
	L2.print();
	cout << "Number of the modified elements: " << endl;
	cout << ttemp4 << endl;
	cout << endl;
	cout << endl;

	cout << "As can be seen, the results from the vector and list are the same and also their functionality is correct" << endl;
	cout << "End of testing the program" << endl;
	cout << "Terminating... " << endl;
	cout << endl;
	


system ("pause");
return 0;
}


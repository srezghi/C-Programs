#include <iostream>
#include "Vector.h"
#include "List.h"
#include <time.h> 
#include <iomanip> 
using namespace std;


double elapsed_time( clock_t start, clock_t finish)
{
   // returns elapsed time in milliseconds
   return (double)(finish - start) / (CLOCKS_PER_SEC/1000);
}


int main()
{
	//-----Insert a large number of items into a Vector-----//
	Vector<int> V1;

	clock_t start, finish ; //used for getting the time.
	start = clock();
	for (int i(0); i < 1000000; i++)
	{
		V1.push_back(1);
		V1.push_back(2);
		V1.push_back(3);
	}
	finish = clock();
	float time_taken_vector_insrt = elapsed_time(start,finish);

	

	//-----Insert a large number of items into a List-----//
	List<int> L1;
	start = clock();
	for (int i(0); i < 1000000; i++)
	{
		L1.push_back(1);
		L1.push_back(2);
		L1.push_back(3);
	}
	finish = clock();
	double time_taken_list_insrt = elapsed_time(start,finish);



	//-----Change all occurrences of a particular element in the Vector-----//
	start = clock();
	V1.replaceAll(3, 2);
	finish = clock();
	double time_taken_vector_chng = elapsed_time(start,finish);
	


	//-----Change all occurrences of a particular element in theLlist-----//
	start = clock();
	L1.replaceAll(3, 2);
	finish = clock();
	double time_taken_list_chng = elapsed_time(start,finish);



	//-----Delete all occurrences of a particular element from the Vector-----//
	start = clock();
	V1.removeAll(1);
	finish = clock();
	double time_taken_vector_delete = elapsed_time(start,finish);


	//-----Delete all occurrences of a particular element from the List-----//
	start = clock();
	L1.removeAll(1);
	finish = clock();
	double time_taken_list_delete = elapsed_time(start,finish);

	
	cout << "Siavash Rezghiighomi" << endl;
	cout << "301311417" << endl;
	cout << "Type of Elements: Integer" << endl;
	cout << "Number of Elements Added: 3,000,000" << endl;
	cout << "Number of Elements Changed/Removed: 1,000,000 changed and 1,000,000 removed; 2,000,000" << endl;
	cout << "Time units: milliseconds " << endl;
	cout << "Time for Vector Insertion: " << time_taken_vector_insrt << endl;
	cout << "Time for List Insertion: " << time_taken_list_insrt << endl;
	cout << "Time for Vector Change: " << time_taken_vector_chng << endl;
	cout << "Time for List Change: " << time_taken_list_chng << endl;
	cout << "Time for Vector Deletion: " << time_taken_vector_delete << endl;
	cout << "Time for List Deletion: " << time_taken_list_delete << endl;
	cout << endl;
	

system ("pause");
return 0;
}
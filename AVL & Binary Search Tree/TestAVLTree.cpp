#include<iostream>
#include"AvlTreeB.h"
#include"dsexceptions.h"
#include<time.h>
using namespace std;

int main()
{
	// This test function begins by creating a BST called bst and inserts some elements to the bst 
	// from 10 through 20. Then it prints all the keys of this bst. After, we call the remove function to test it.
	// The program removes 15 and 16 then prints the updated tree.
	AvlTree <int> avl;
	int arr[11];
	int count = 0;
	for (int i (0); i < 11; i++)
	{
		arr[i] = i + 10;
		count = count + arr[i];
		avl.insert(arr[i]);
	}
	cout << "Printing the AVL tree:" << endl;
	avl.printTree();
	cout << endl;
	
	cout << "Removing 15 and 16 from the AVL tree" << endl;
	avl.remove(15);
	avl.remove(16);

	cout << "Printing the AVL Tree after removing:" << endl;
	avl.printTree();
	cout << endl;	
	cout << "End of the test function." << endl;
	cout << endl;

system("pause");
return 0;
}

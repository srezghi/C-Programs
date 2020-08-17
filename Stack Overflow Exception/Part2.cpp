//* @section This program helps the user to construct a variable type called  
//*			 "Stack" what accepts words of specific size defined by the user. 
//*			 The program asks user to input the desired size and the actual word.
//*		     Then the code creates the Stack object by using the constructors. 
//*			 There are 2 error cases that are being handeled by the code: 1) when
//*			 there is a "stack overflow", 2) when the user tries to output from
//*			 an empty stack. Please refer to the comments below for more
//*			 information/understanding of the code.

#include <iostream>
using namespace std;

//Declaration of "StackFrame" struct 
struct StackFrame
{
	char data;
	StackFrame *link;
};
typedef StackFrame* StackFramePtr;

//Declaration of "Stack" class 
//This class definition is derived from page 766 of the textbook,
//"Problem Solving With C++ 9th Edition" by Walter Savitch.
class Stack
{
public:
	//Constructors
	Stack();
	Stack(int size);
	Stack(const Stack& s);

	//Destructor
	~Stack();

	//Getter
	int getSize();

	//Other functions
	void push(char c);
	char pop();	
	bool empty() const;
	

private:
	StackFramePtr top;
	int maxSize;
};

//Declaration of "StackOverflowException" class
class StackOverflowException
{
public:
	void OverflowError();
};
//**
//* @brief The following block gives error once there is an Overflow.
//**
void StackOverflowException::OverflowError()
{
    cout << "The stack is FULL.\n";
    cout << "There is no space for a new data.\n";
}
//Declaration of "StackEmptyException" class
class StackEmptyException
{
public:
	void EmptyError();
};
//**
//* @brief The following block gives error once the user tries to output
//*		   from an empty stack.
//**
void StackEmptyException::EmptyError()
{
    cout << "The stack is EMPTY.\n";
    cout << "There is no data to show.\n";
}

//Main function (Test Driver program)---------------------------------------------------
//**
//* @brief This main function is testing all the functions of the Stack class.
//*        Part of this Test Driver program is derived from page 768 of the
//*        "Problem Solving With C++ 9th Edition" by Walter Savitch.
//*        The expected output from the is something like the following based
//*        the randomly assigned information by myself:
//*        Creating a Stack of size 10 manually and pushing 'helloworld'
//*        This will call Pop() function and the output is 'dlrowolleh'
//*        The backwards output is: dlrowolleh
//*        Testing the empty stack condition
//*        The program should give error as the following shows:
//*        ERROR:
//*        The stack is EMPTY.
//*        There is no data to show.
//*
//*
//*        Enter a word of length ten: hellohello
//*        Written backwards is: olleholleh
//*        Enter y to try again or n to exit: y
//*        Enter a word of length ten: hello hello
//*        The stack is FULL.
//*        There is no space for a new data.
//*        Enter y to try again or n to exit: y
//*        Enter a word of length ten: hellodavid
//*        Written backwards is: divadolleholleh olleh
//*        Enter y to try again or n to exit: n
//**
int main()
{
    char test, test_choice;
    cout << endl;
    cout << "Creating a Stack of size 10 manually and pushing 'helloworld'" << endl;
    Stack test2(10);
    test2.push('h');
    test2.push('e');
    test2.push('l');
    test2.push('l');
    test2.push('o');
    test2.push('w');
    test2.push('o');
    test2.push('r');
    test2.push('l');
    test2.push('d');
    
    cout << "This will call Pop() function and the output is 'dlrowolleh' " << endl;
    cout << "The backwards output is: ";
    while (!test2.empty())
    {
        cout << test2.pop();
    }
    cout << endl;
    cout << "Testing the empty stack condition" << endl;
    cout << "The program should give error as the following shows:";
    cout << endl  << "ERROR: " << endl;
    test2.pop();
    
    cout << endl << endl;
    
	Stack test1(10);
	int mSize = 0;
	char c, ans;

	do
	{
		try
		{
			cout << "Enter a word of length ten: ";
			cin.get(c);
			while (c != '\n')
			{
				test1.push(c);
				cin.get(c);
				mSize++;
				if (mSize > test1.getSize())
				{
					throw StackOverflowException();
				}
			}
			cout << "Written backwards is: ";
			while (!test1.empty())
			{
				cout << test1.pop();
			}
			cout << endl;
		}
		catch (StackOverflowException e1)
		{
			e1.OverflowError();
		}
		cout << "Enter y to try again or n to exit: ";
		cin >> ans;
		cin.ignore(10000, '\n');
		if (ans == 'y')
		{
			mSize = 0;
		}
	} while (ans == 'y');


system("pause");
return 0;
}

//**
//* @brief Default constructor: Creates a stack that points to NULL.
//**
Stack::Stack()
{
	this->top = NULL;
}
//**
//* @brief Non-Default constructor: Creates a stack with the given size.
//*
//* @param "size" is the given stack size by user.
//**
Stack::Stack(int size)
{
	this->maxSize = size;
}
//**
//* @brief Copy constructor: Copies the Stack type variable into another Stack variable.
//*
//* @param "s" is the given/created Stack type variable by user.
//*
//* This copy constructor definition is derived from page 778 of the
//* textbook, "Problem Solving With C++ 9th Edition" by Walter Savitch.
//**
Stack::Stack(const Stack& s)
{
	if (s.top == NULL)
	{
		top = NULL;
	}

	else
	{
		StackFramePtr temp = s.top;
		StackFramePtr end;
		end = new StackFrame;
		end->data = temp->data;
		top = end;

		temp = temp->link;
		while (temp != NULL)
		{
			end->link = new StackFrame;
			end = end->link;
			end->data = temp->data;
			temp = temp->link;
		}
		end->link = NULL;
	}
}

//**
//* @brief Destructor: Deletes stack type variable once it is called.
//**
Stack::~Stack()
{
	char next;
	while (!empty())
	{
		next = pop();
	}
}
//**
//* @brief This function checks whether the stack is empty or not.
//**
bool Stack::empty() const
{
	return (top == NULL);
}
//**
//* @brief This function allows the character to be pushed in the desired stack.
//*
//* @param "c" is the given character variable by user.
//*
//* The push function definition is derived from page 777-778 of the
//* textbook, "Problem Solving With C++ 9th Edition" by Walter Savitch.
//**
void Stack::push(char c)
{
	StackFramePtr newNode = new StackFrame;
	newNode->data = c;
	newNode->link = top;
	top = newNode;
}
//**
//* @brief This function checks whether the stack is empty or not.
//*
//* The pop function definition is derived from page 769-770 of the
//* textbook, "Problem Solving With C++ 9th Edition" by Walter Savitch.
//**
char Stack::pop()
{
	try
	{   
		if (empty())
		{
			throw StackEmptyException();
		}
		char result = top->data;
		StackFramePtr temp;
		temp = top;
		top = top->link;
		delete temp;
		return result;
	}
	catch (StackEmptyException e)
	{
		e.EmptyError();
	}
}

//**
//* @brief This function returns the size of the stack.
//**
int Stack::getSize()
{
	return this->maxSize;
}

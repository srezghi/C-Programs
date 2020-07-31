//**
// * @file Part2.cpp
// * @author Siavash Rezghighomi
// * @Date   26/05/2018
// * @version 1
// * @section DESCRIPTION
// * Implemented a "Class" called Movie which has different member variables
// * and functions which as be found below. There is also a test driver that
// * tests each function and return a specific output.
// 
//
//
//
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Movie
{
private: 
	//Member of Movie class
	int raters1;
	int raters2;
	int raters3;
	int raters4;
	int raters5;
	int averageRating;
	string movieName;
	string mpaaRate;

public:
	//Constructor member function
	Movie(string a, string b);

	//Getters functions
	double getAverage();
	string getMovieName();
	string getMpaaRate();
	
	//Setters functions
	void setMovieName(string &a);
	void setAverage(int &a);
	void setMpaaRating(string &a);
	
	//Additional member functions
	void addRating();
	void print();
};

//Main function------------------------------------------------------------
//**
//* @brief This main function is the "Test Function". In the following main(),
//*		   2 variables type string is being initialized; name1 = "John Wick"
//*		   and MPAA1 = "PG". Then the test uses the movie constructor of the 
//*		   Movie Class. The test continues by calling addRating() and print(). 
//*		   The description of the mentioned function can be found below.
//*		   The same procedure will be repeated for the second movie;  
//*		   name2 = "Deadpool2" and MPAA2 = "R". Since the ratings are assigned 
//*		   randomly, the test function output for averageRating will vary 
//*		   each time. Lastly, there will be a message from the function ends
//*		   the code with "Thanks for using our system! Bye.". Overall, the 
//*		   expected output from the code is something like:
//*		   The movie name is John Wick
//*		   The MPAA rating is PG
//*		   The average rating for this movie is 3.5
//*
//*		   The movie name is Deadpool2
//*		   The MPAA rating is R
//*		   The average rating for this movie is 2.3
//*
////*		   "Thanks for using our system! Bye."
//*
//*/
int main ()
{
	string name1 = "John Wick";
	string MPAA1 = "PG";
	Movie input1(name1, MPAA1);
	input1.addRating();
	input1.print();

	cout << endl;

	string name2 = "Deadpool2";
	string MPAA2 = "R";
	Movie input2(name2, MPAA2);
	input2.addRating();
	input2.print();

	cout << endl;
	cout << "Thanks for using our system! Bye." << endl;
	cout << endl;

system ("pause");
return 0;
}

//Constructors--------------------------------------------------------------
//**
//* @brief This function constructs a new varianle type Movie Class that takes
//*		   a name and MPAA rating whereas its average rating and number of 
//*		   raters has assigned to zero.
//*		   
//* @param "a" is movieName and "b" is mpaaRate of the class function.
//*/
Movie::Movie(string a, string b)
{
	int temp(0);
	raters1 = 0;
	raters2 = 0;
	raters3 = 0;
	raters4 = 0;
	raters5 = 0;
	setMovieName(a);
	setAverage(temp);
	setMpaaRating(b);
}

//Getters-------------------------------------------------------------------
//**
//* @brief This function returns the average ratings of a movie usng the
//*		   following formula.
//*/
double Movie::getAverage()
{
	return static_cast<double>(this->raters1 * 1 + this->raters2 * 2 + 
		this->raters3 * 3 +	this->raters4 * 4 + this->raters5 * 5) / 
		(this->raters1 + this->raters2 + this->raters3 + this->raters4 + 
		this->raters5);
}
//**
//* @brief This function returns the movieName of the Movie Class.
//*/
string Movie::getMovieName()
{
	return movieName;
}
//**
//* @brief This function returns the mpaaRate of the Movie Class.
//*/
string Movie::getMpaaRate()
{
	return mpaaRate;
}

//Setters-------------------------------------------------------------------
//**
//* @brief This function sets the given movie name to the "movieName".
//*
//* @param "a" is movieName given by user.
//*/
void Movie::setMovieName(string &a)
{
	this->movieName = a;
}
//**
//* @brief This function sets the averageRating of the Movie Class.
//*
//* @param "a" is average rating.
//*/
void Movie::setAverage(int &a)
{
	this->averageRating = a;
}
//**
//* @brief This function sets the mpaaRate of the Movie Class.
//*
//* @param "a" is MPAA rating.
//*/
void Movie::setMpaaRating(string &a)
{
	this->mpaaRate = a;
}

//Additional member functions-----------------------------------------------
//**
//* @brief This function assigns 5 random rating for movies.
//*/
void Movie::addRating()
{
	srand (time(NULL));
	for (int i(0); i < 5; i++)
	{
		int randomRate = rand() % 5 + 1;
		if (randomRate == 1)
		{
			this->raters1++;
		}
		else if (randomRate == 2)
		{
			this->raters2++;
		}
		else if (randomRate == 3)
		{
			this->raters3++;
		}
		else if (randomRate == 4)
		{
			this->raters4++;
		}
		else if (randomRate == 5)
		{
			this->raters5++;
		}
	}	
}
//**
//* @brief This function prints the movieName, mpaaRate and averageRating of a movie.
//*/
void Movie::print()
{
	cout << "The movie name is " << getMovieName() << endl;
	cout << "The MPAA rating is " << getMpaaRate() << endl;
	cout << "The average rating for this movie is " << getAverage() << endl;
}
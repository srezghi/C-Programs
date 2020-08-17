//* @section This program helps the user to construct a variable type called  
//*			 "Vehicle" and "Truck" whereas truck is the subclass. The program
//*			 asks user to input the information for Vehicle and/or Truck class,
//*		     such as owner's name, manufacturer's name, # of cylinders, load and
//*			 tow capacity. Several test cases has been included in the driver program
//*			 which tests all the member functions of the mentioned classes. Please see 
//*			 the comments below for more information/understanding.
//*

#include <iostream>
#include <string>
using namespace std;

//Declaration of "Person" class 
class Person
{
public:
	//Constructors
	Person();
	Person(string theName);
	Person(const Person& theObject);

	//Getters
	string getName() const;

	//Assignment Operator
	Person& operator = (const Person& rtSide);

	//Friend functions
	friend istream& operator >>(istream& inStream, Person& personObject);
	friend ostream& operator <<(ostream& outStream, const Person& personObject);

private:
	string name;
};
//**
//* @brief Default constructor: Sets the name to "NOT AVAILABLE".
//**
Person::Person()
{
	this->name = "NOT AVAILABLE";
}
//**
//* @brief Non-Default constructor: Sets the name to the given name.
//*
//* @param "theName" is the given name by user.
//**
Person::Person(string theName)
{
	this->name = theName;
}
//**
//* @brief Copy constructor: Copies the Person type variable into another Person variable.
//*
//* @param "theObject" is the given/created Person type variable by user.
//**
Person::Person(const Person& theObject)
{
	this->name = theObject.getName();
}
//**
//* @brief Getter: Retunrs the name of the variabe Person once it has called.
//**
string Person::getName() const
{
	return this->name;
}
//**
//* @brief Assignment Operator(=): Assigns all the member variables of a Person Variable
//*		   to another new/existing Person variable.
//*
//* @param "rtSide" is the given/created Person type variable by user.
//**
Person& Person::operator=(const Person& rtSide)
{
	if (this == &rtSide)
		return *this;
	this->name = rtSide.getName();
	return *this;
}

//**
//* @brief This function overloads the " >> " operator for Person class
//*		   that allows a user to cin name directly.
//**
istream& operator >>(istream& inStream, Person& personObject)
{
	string a;
	cout << "Please enter your name: ";
	inStream >> a;
	personObject.name = a;
	return inStream;
}
//**
//* @brief This function overloads the " << " operator for Person class.
//**	
ostream& operator <<(ostream& outStream, const Person& personObject)
{
	outStream << "The owner's name: " << personObject.name;
	return outStream;
}


//Declaration of the "Vehicle" class
class Vehicle
{
private:
	string manufacturer;
	int cylinders;
	Person owner;

public:
	//Constructors
	Vehicle();
	Vehicle(const string &m, const int &c, const Person &o);
	Vehicle(const Vehicle &v);

	//Assignment Operator
	Vehicle& operator=(const Vehicle &v);

	//Getters
	string getManufacturer() const;
	int getCylinder() const;
	Person getOwner() const;

	//Setters
	void setManufacturer(const string &);
	void setCylinder(const int &);
	void setOwner(const Person &);

	//Friend functions
	friend istream& operator>>(istream& inStream, Vehicle &v);
	friend ostream& operator<<(ostream& outStream, const Vehicle &v);
};
//**
//* @brief Default constructor: Sets the name to "NOT AVAILABLE" by calling 
//*		   the Default constructor of Person class, sets the manufacturer's
//*		   name to "NOT AVAILABLE" and number of cylinders to "0".
//**
Vehicle::Vehicle()
{
	this->owner = Person();
	this->setManufacturer("NOT AVAILABLE");
	this->setCylinder(0);
}
//**
//* @brief Non-Default constructor: Sets the name to "NOT AVAILABLE" by calling 
//*		   the Default constructor of Person class, sets the manufacturer's
//*		   name to "NOT AVAILABLE" and number of cylinders to "0".
//*
//* @param "m", "c" and "o" are manufacturer's name, # of cylinders and owner accordingly.
//**
Vehicle::Vehicle(const string &m, const int &c, const Person &o)
{
	this->setManufacturer(m);
	this->setCylinder(c);
	this->setOwner(o);
}
//**
//* @brief Copy constructor: Copies the Vehicle type variable into another Vehicle variable.
//*
//* @param "v" is the given/created Vehicle type variable by user.
//**
Vehicle::Vehicle(const Vehicle &v)
{
	this->setManufacturer(v.getManufacturer());
	this->setCylinder(v.getCylinder());
	this->setOwner(v.getOwner());
}
//**
//* @brief Getter: Retunrs the name of the manufacturer's name once it has called.
//**
string Vehicle::getManufacturer() const
{
	return this->manufacturer;
}
//**
//* @brief Getter: Retunrs the name of the # of cylinders once it has called.
//**
int Vehicle::getCylinder() const
{
	return this->cylinders;
}
//**
//* @brief Getter: Retunrs vehicle's owner's name. 
//**
Person Vehicle::getOwner() const
{
	return this->owner;
}

//**
//* @brief Setter: Sets manufacturer's name. 
//**
void Vehicle::setManufacturer(const string &m)
{
	this->manufacturer = m;
}
//**
//* @brief Setter: Sets # of cylinders. 
//**
void Vehicle::setCylinder(const int &c)
{
	this->cylinders = c;
}
//**
//* @brief Setter: Sets vehicle's owner's name. 
//**
void Vehicle::setOwner(const Person &o)
{
	this->owner = o;
}
//**
//* @brief Assignment Operator(=): Assigns all the member variables of a Vehicle Variable
//*		   Variable to another new/existing Person variable including owner's name.
//*
//* @param "v" is the given/created Vehicle type variable by user.
//**
Vehicle& Vehicle::operator=(const Vehicle &v)
{
	if (this == &v)
		return *this;
	this->setManufacturer(v.getManufacturer());
	this->setCylinder(v.getCylinder());
	this->owner = (v.owner.getName());
	return *this;
}
//**
//* @brief This function overloads the " >> " operator for Vehicle class
//*		   that allows a user to cin a vehicle directly.
//**
istream& operator >>(istream& inStream, Vehicle &v) 
{
	string manufacturer;
	int cylinder;
	Person o;
	inStream >> o;
	cout << "Please enter the manufacturer's name: ";
	inStream >> manufacturer;
	cout << "Please enter the number of cylinders: ";
	inStream >> cylinder;
	v.setOwner(o);
	v.setManufacturer(manufacturer);
	v.setCylinder(cylinder);
	return inStream;
}
//**
//* @brief This function overloads the " << " operator for Vehicle class.
//**
ostream& operator <<(ostream& outStream, const Vehicle &v)
{
	outStream << v.getOwner() << endl;
	outStream << "The manufacturer's name: " << v.getManufacturer() << endl;
	outStream << "Number of Cylinders: " << v.getCylinder() << endl;
	return outStream;
}


//Declaration of the "Truck" class which has "Vehcile" class as the base.
class Truck : public Vehicle
{
private:
	double loadCapacity;
	int towCapacity;

public:
	//Constructors
	Truck();
	Truck(const string &m, const int &c, const Person &o, const double &l, const int &t);
	Truck(const Truck &t);

	//Assignment Operator
	Truck& operator=(const Truck &t);

	//Getters
	double getLoadCapacity() const;
	int getTowCapacity() const;

	//Setters
	void setLoadCapacity(const double &);
	void setTowCapacity(const int &);

	//Friend functions
	friend istream& operator>>(istream& inStream, Truck &t);
	friend ostream& operator<<(ostream& outStream, const Truck &t);
};
//**
//* @brief Default constructor: Sets load capacity to "0.0" and tow capacity to "0"
//*		   and also calls the Default constructor of Vehicle class. Accordingly the
//*		   manufacturer's name and owner's name will be "NOT AVAIABLE" and cylinders
//*		   to "0".
//**
Truck::Truck() : Vehicle()
{
	this->setLoadCapacity(0.0);
	this->setTowCapacity(0);
}
//**
//* @brief Default constructor: Sets load capacity to "l" and tow capacity to "t"
//*		   and also calls the Non-Default constructor of Vehicle class. Accordingly the
//*		   manufacturer's name wil set to "m", owner's name to "o" and cylinders to "c".
//*
//* @param "m", "c", "o", "l" and "t" are manufacturer's name, # of cylinders, owner,
//*		   load and tow capacity accordingly.
//**
Truck::Truck(const string &m, const int &c, const Person &o, const double &l, const int &t) : Vehicle(m,c,o)
{
	this->setLoadCapacity(l);
	this->setTowCapacity(t);
}
//**
//* @brief Copy constructor: Copies the Truck type variable into another Truck variable.
//*		   Also, it calls the copy constructor of the Vehicle class which copies the
//*		   manufacturer's name, owner's name and # of cylinders.
//*
//* @param "t" is the given/created Truck type variable by user.
//**
Truck::Truck(const Truck &t) : Vehicle(t)
{
	this->setLoadCapacity(t.getLoadCapacity());
	this->setTowCapacity(t.getTowCapacity());
}
//**
//* @brief Getter: Retunrs the load capacity once it has called.
//**
double Truck::getLoadCapacity() const
{
	return this->loadCapacity;
}
//**
//* @brief Getter: Retunrs the tow capacity once it has called.
//**
int Truck::getTowCapacity() const
{
	return this->towCapacity;
}
//**
//* @brief Setter: Sets the load capacity once it has called.
//**
void Truck::setLoadCapacity(const double &l)
{
	this->loadCapacity = l;
}
//**
//* @brief Setter: Sets the tow capacity once it has called.
//**
void Truck::setTowCapacity(const int &t)
{
	this->towCapacity = t;
}
//**
//* @brief Assignment Operator(=): Assigns all the member variables of a Truck Variable
//*		   Variable to another new/existing Truck variable.
//*
//* @param "t" is the given/created Truck type variable by user.
//**
Truck& Truck::operator=(const Truck &t)
{
	if (this == &t)
		return *this;
	this->setLoadCapacity(t.getLoadCapacity());
	this->setTowCapacity(t.getTowCapacity());
	(*this).Vehicle::operator=(t);
	return *this;
}
//**
//* @brief This function overloads the " >> " operator for Truck class
//*		   that allows a user to cin a Truck directly.
//**
istream& operator>>(istream& inStream, Truck &t)
{
	double load;
	int tow;
	string manufacturer;
	int cylinder;
	Person o;
	inStream >> o;
	cout << "Please enter the manufacturer's name: ";
	inStream >> manufacturer;
	cout << "Please enter the number of cylinders: ";
	inStream >> cylinder;
	cout << "Please enter the load capacity in tons: ";
	cin >> load;
	cout << "Please enter the tow capacity in pounds: ";
	cin >> tow;
	t = Truck(manufacturer, cylinder, o, load, tow);
	return inStream;
}
//**
//* @brief This function overloads the " << " operator for Truck class.
//**
ostream& operator <<(ostream& outStream, const Truck &t)
{
	outStream << t.getOwner() << "." << endl;
	outStream << "The manufacturer's name: " << t.getManufacturer() << "." << endl;
	outStream << "Number of Cylinders: " << t.getCylinder() << "." << endl;
	outStream << "Load capacity (in tons): " << t.getLoadCapacity() << "." << endl;
	outStream << "Tow capacity (in pounds): " << t.getTowCapacity() << "." << endl;
	return outStream;
}

//Main function (Driver program)---------------------------------------------------
//**
//* @brief This main function is testing all the functions of the Person class,
//*		   Vehicle class and Truck class. First, some Vehicle variable will be  
//*		   initialized and filled by using constructors. Related functions of the 
//*		   Vehicle class will be all tested accordignly. Second, some Truck 
//*		   variable will be initialized and filled by using its constructors.
//*		   Related functions of the Truck class will be all tested accordignly. 
//*		   Please see the comments provided in the body of the main function 
//*		   for better understanding of the code.Overall, the expected output from 
//*		   the code is something like the following based on the randomly assigned
//*		   information by myself:
//*		   
//*		   Please enter your name: Tristan
//*		   Please enter the manufacturer's name: Ford
//*		   Please enter the number of cylinders: 4
//*		   
//*		   The owner's name: Tristan
//*		   The manufacturer's name: Ford
//*		   Number of Cylinders: 4
//*		   
//*		   The owner's name: NOT AVAILABLE
//*		   The manufacturer's name: NOT AVAILABLE
//*		   Number of Cylinders: 0
//*		   
//*		   The owner's name: Tristan
//*		   The manufacturer's name: Ford
//*		   Number of Cylinders: 4
//*		   
//*		   The owner's name: Tom
//*		   The manufacturer's name: Toyota
//*		   Number of Cylinders: 6
//*		   
//*		   The owner's name: Tom
//*		   The manufacturer's name: Toyota
//*		   Number of Cylinders: 6
//*		   
//*		   Please enter your name: Alvin
//*		   Please enter the manufacturer's name: Honda
//*		   Please enter the number of cylinders: 6
//*		   Please enter the load capacity in tons: 3
//*		   Please enter the tow capacity in pounds: 1500
//*		   
//*		   The owner's name: Alvin.
//*		   The manufacturer's name: Honda.
//*		   Number of Cylinders: 6.
//*		   Load capacity (in tons): 3.
//*		   Tow capacity (in pounds): 1500.
//*		   
//*		   The owner's name: NOT AVAILABLE.
//*		   The manufacturer's name: NOT AVAILABLE.
//*		   Number of Cylinders: 0.
//*		   Load capacity (in tons): 0.
//*		   Tow capacity (in pounds): 0.
//*		   
//*		   The owner's name: Alvin.
//*		   The manufacturer's name: Honda.
//*		   Number of Cylinders: 6.
//*		   Load capacity (in tons): 3.
//*		   Tow capacity (in pounds): 1500.
//*		   
//*		   The owner's name: Adam.
//*		   The manufacturer's name: Nissan.
//*		   Number of Cylinders: 6.
//*		   Load capacity (in tons): 1.5.
//*		   Tow capacity (in pounds): 1350.
//*		   
//*		   The owner's name: Adam.
//*		   The manufacturer's name: Nissan.
//*		   Number of Cylinders: 6.
//*		   Load capacity (in tons): 1.5.
//*		   Tow capacity (in pounds): 1350.
//*		   
//*		   The owner's name: David.
//*		   The manufacturer's name: Nissan.
//*		   Number of Cylinders: 6.
//*		   Load capacity (in tons): 1.5.
//*		   Tow capacity (in pounds): 1350.

int main()
{
	//Testing Vehicle/Person default constructor, << , >>
	Vehicle v1,v2,v3;
	cin >> v1;
	cout << endl;
	cout << v1 << endl;
	cout << v2 << endl;
	//Testing assignment operator (=)
	v3 = v1;
	cout << v3 << endl;
	string m1 = "Toyota";
	int c1 = 6;
	//Testing Person non default constructor
	Person o1("Tom");
	//Testing Vehicle non default constructor
	Vehicle v4(m1, c1, o1);
	cout << v4 << endl;
	//Testing Vehicle copy constructor
	Vehicle v5(v4);
	cout << v5 << endl;

	//Testing Vehicle/Person/Truck default constructor, << , >>
	Truck t1,t2,t3;
	cin >> t1;
	cout << endl;
	cout << t1 << endl;
	cout << t2 << endl;
	//Testing assignment operator (=)
	t3 = t1;
	//Testing default constructor
	cout << t3 << endl;
	string m2 = "Nissan";
	int c2 = 6;
	double l = 1.5;
	int t = 1350;
	//Testing Person non default constructor
	Person o2("Adam");
	//Testing Truck non default constructor
	Truck t4(m2, c2, o2, l, t);
	cout << t4 << endl;
	//Testing Truck copy constructor
	Truck t5(t4);
	cout << t5 << endl;
	Person o3("David");
	//Testing Person copy constructor
	Person o4(o3);
	Truck t6(m2, c2, o4, l, t);
	cout << t6 << endl;

system ("pause");
return 0;
}

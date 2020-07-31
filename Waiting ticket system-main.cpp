//**
//* @author SIAVASH REZGHIGHOMI
//* @Date 06/21/2018
//* @version 1.0
//*


#include <iostream>
#include <string>
#include <ctime>
#include "Waiting ticket system.h"
using namespace std;
using namespace QueueSiavash;

//Main function------------------------------------------------------------
//**
//* @brief This main function will test the header file (Part2h.h) and Queue 
//*		   class (Part2.cpp). A similar output as showed on the HW2 is an 
//*		   excepted output from this code.
//*
//**
int main()
{
	Queue newCustomer;
    long waitTime;
    long averageWaitTime;
    int input;
    int temp1 (1);
    int temp2 (1);
    long seconds = static_cast<long>(time(NULL));
   
    cout << "The line is empty " << endl;
    cout << "Enter '1' to simulate a customer's arrival,";
	cout << "'2' to help the next customer, or '3' to quit." << endl;
    cin >> input;

    while ((input == 1) || (input == 2) || (input == 3))
    {
        seconds = static_cast<long>(time(NULL));
        if (input == 1)
        {
            cout << "Customer " << temp1 << " entered the queue at ";
			cout << seconds << " seconds. " << endl;
            temp1++;
            newCustomer.add(seconds);
        }
        else if (input == 2)
        {
            if(newCustomer.empty())
            {
                cout << "The line is empty" << endl;
            }
            else
            {
                waitTime = newCustomer.remove(seconds);
                cout << "Customer " << temp2 << " is being helped at time ";
				cout << seconds << " seconds. " << "Wait Time = " << waitTime << endl;
                temp2++;
                averageWaitTime = newCustomer.updateWaitTime(waitTime);
                if(newCustomer.empty())
                {
                    cout << "The line is empty" << endl;
                }
                else
                {
                    cout << "The estimated wait time for customer " << temp2;
					cout << " is " << averageWaitTime << endl;     
                }
            }
        }
        else if (input == 3)
        {
			cout << "Exiting..." << endl;
			cout << "Bye!" << endl;
            break;
        }
        else
        {
            cout << "Please enter a valid input." << endl;
        }
		cout << "The line is empty " << endl;
		cout << "Enter '1' to simulate a customer's arrival,";
		cout << "'2' to help the next customer, or '3' to quit." << endl;        
		cin >> input;
        cout << endl;
    }

system ("pause");
return 0;
}
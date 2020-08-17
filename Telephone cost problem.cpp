#include <iostream>  
using namespace std; 

void calculateCost(int a, double b);
	
int main()
{
	int call_in_time;
	int duration;
	char day_1;
	char day_2;

	// // Here I have divided the time to 5 seperate charactors to be able to
	// include the colon within my time input. The is a note to make: If
	// the user wants to input 8:00 am, he/she SHOULD input it as 08:00. 
	char time_a;
	char time_b;
	char colon;
	char time_c;
	char time_d;

	double rate_of_call;
	double cost_of_call;

	// temp is just a simple variable used for the while-do loop which it could be 0 or 1
	char temp;


	do
	{
		cout << "Which day of the week the call as been made ?" << endl;
		cin >> day_1 >> day_2;

		cout << "\n";

		cout << "At what time did the call start ?" << endl;
		cin >> time_a >> time_b >> colon >> time_c >> time_d;

		cout << "\n";

		cout << "Please provide the duration of the call in minutes ?" << endl;
		cin >> duration;

		cout << "\n";

		// The following two lines are transforming the input time as a charactor to an integar 
		int time_a_transformed = time_a;
		int time_b_transformed = time_b;

		if ((day_1 == 'S' || day_1 == 's') && (day_2 == 'A' || day_2 == 'a' || day_2 == 'U' || day_2 == 'u'))
			rate_of_call = 0.15;
	
		else
		{
			if ((time_a_transformed == 48 && time_b_transformed >= 56) || (time_a_transformed == 49 && time_b_transformed < 56))
				rate_of_call = 0.40;
			else
				rate_of_call = 0.25;
		}

		calculateCost(duration, rate_of_call);
		cout << "For a new call calculation choose 1 or press 0 to exit" << endl;
		cin >> temp;
	}
	while(temp!='0');
}

/**
 * @brief DESCRIPTION
 *
 * @param a is 
 * @param b is 
 * @return void
 *
 */
void calculateCost(int a, double b)
{
	double cost = 0;
 	cost = a * b;
	cout << "The total cost of your call is $" << cost << "\n" << endl;
}

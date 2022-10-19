#include <iostream>
#include "FUNCTIONS.h"
using namespace std;

/* This function is used to control the switch/case menu */
void menuOption(int option, int array[], const int ARRSIZE)
{
	int target, modify, toMod, addInt, indexPoint = 0;
	switch (option)
	{
	case 1:
		cout << "What number would you like to find the in array: ";
		cin >> target;
		
		isIntegerThere(target, array, ARRSIZE);
		break;
	case 2:

		cout << "What integer do you want to modify: ";
		cin >> modify;
		cout << endl;
		cout << "What do you want to modify " << modify << " to: ";
		cin >> toMod;

		modifyInteger(modify, array, toMod, ARRSIZE);
		break;
	case 3:
		cout << "What integer would you like to add: ";
		cin >> addInt;
		addInteger(addInt, array, ARRSIZE);
		break;
	case 4:
		cout << "At which index of the list would you like to zero: ";
		cin >> indexPoint;
		zeroInteger(indexPoint, array, ARRSIZE);
		cout << "4. Zero An Integer From The List" << endl;
		break;
	case 5:
		cout << "5. Exit" << endl;
		break;
	default:
		cout << "No Matching Option." << endl;
	}
}
/* a function that will traverse the array passed into it with the value the user is looking for
and if found, will output the found array at the index found */
void isIntegerThere(int target, int array[], const int ARRSIZE)
{
	bool isFound = false;
	//flag utilized to help display error message if never turned true
	for (int i = 0; i < 100; i++)
	{
		//try to find integer passed in to the array
		try
		{
			//if search is found at position i, it will output the value and at what index
			if (target == array[i])
			{
				cout << "Value " << target << " found at index " << i << endl;
				isFound = true;
			}
			//if the target was not found in the array, throw target
			else if(isFound == false)
				throw(target);
		}
		//catches target and outputs error message.
		catch (int num)
		{
			cout << "Unable to find " << num << " in the index." << endl;
			break;
		}
	}
	return;
}
/* modifyInteger is very similar to isIntegerThere with a few differences, it still runs through the array
looking for a specific integer but it will now instead of reporting back that it is indeed there, modify
the integer to what the user wants it to be, then show it to the user
*/

int modifyInteger(const int TARGET, int array[], const int TOMOD, const int ARRSIZE)
{
	//boolean variable to indicate whether an integer has been modified
	bool isModded = false;
	//using search to find the value needed in the array
	for (int i = 0; i < ARRSIZE; i++)
	{
		//exception handling
		try 
		{
			//if search is found at this position, it will output the value and at what index
			if (TARGET == array[i])
			{
				array[i] = TOMOD;
				cout << "Value " << TARGET << " found at index " << i << " is now " << TOMOD << endl;
				isModded = true;
			}
			else if (isModded == false)
				throw(TARGET);
		}
		catch (const int num)
		{
			cout << "Unable to find " << num << " in the index to change it to your input: " << TOMOD << endl;
			break;
		}
	}
	return array[ARRSIZE];
}

/* addInteger will take the number wanting to be added into a new array at the end of the
index, temp, to return to the user
*/
int addInteger(const int ADDNUM, int array[], int arrSize)
{
	//utilizing the counter "i" to determine the size of our index in array "temp"
	int i = 0;
	//temp will be returned so that the array will keep the added integer
	int temp[200] = { 0 };
	try
	{
		for (i = 0; i < arrSize; i++)
		{
			//filling in temp with the passed through array's index values
			temp[i] = array[i];
			//if i reaches the end of the index, add the paramater ADDNUM to the end of temp
			if (i = arrSize - 1)
			{
				temp[i + 1] = ADDNUM;
			}
			if (ADDNUM < 0)
				throw(ADDNUM);
		}
	}
	catch (const int ADDNUM)
	{
		cout << "Unable to add the integer provided as it is below zero." << endl;
	}

	cout << endl;
	return temp[200];
}

/* This function takes the index number that the user wants zeroed in the array, finds it,
then changes the value in that index to zero.
array is being returned since the values in the index have changed.
*/
int zeroInteger(int index, int array[], const int ARRSIZE)
{
	bool found = false;
	for (int i = 0; i < ARRSIZE; i++)
	{
		//if i is equal to INDEX in array do this
		if (i == index)
		{
			array[i] = 0;
			cout << "Index at position " << index << " has been changed to zero." << endl;
			//helps control error message
			found = true;
		}
	}
	if (found == false)
		cout << "Unable to find that index position." << endl;

	return array[ARRSIZE];
}

//Recursion method to get a valid response from the user
int recursionOption(int userInput)
{
	//if statement conrols whether or not 
	if (userInput <= 0 || userInput >= 6)
	{
		cout << "Input does not match an option, try again: ";
		//allows user to try again
		cin >> userInput;
		return recursionOption(userInput);
	}
	else
		return userInput;
}

//default constructor
Employee::Employee() 
{
	healthcarePay = 0;
	paymentRate = 0;
	vacationDays = 0;
	hoursWorked = 0;
}
//construcor
Employee::Employee(double hcP, double pR, double vD, double hours) :healthcarePay(hcP), paymentRate(pR), vacationDays(vD), hoursWorked(hours)
{}

Professional::Professional(double pmr, double hcp, double vcd, double hours) : monthlyRate(pmr), healthTax(hcp), salaryHours(hours), vacDays(vcd) {}

//getter function for weekly salary
double Professional::weeklySalary()
{
	//returning a value of the monthlyRate divided by 4 to return a weekly rate.
	return (monthlyRate / 4);
}
	//returns how much of a Professionals income is put into healthcare
double Professional::healthContributions()
{
	return (monthlyRate * healthTax);
}
//returns amount of vacations days earned
double Professional::vacationEarned()
{
	//Professionals earn vacations days faster, thus we divide hours worked by 50 instead of 100
	return (vacDays + (salaryHours/50));
}

//returns a nonProfessionals weekly salary
nonProfessional::nonProfessional(double wT, double hT, double vD, double hW) : weeklyRate(wT), healthTax(hT), vacDays(vD), hoursWorked(hW) {}
double nonProfessional::weeklySalary()
{
	return (weeklyRate * hoursWorked);
}

//nonProfessionals have less health benefit than Professionals, thus we use half the hours of a month instead of the full month
double nonProfessional::healthContributions()
{
	return((weeklyRate*80) * healthTax);
}
//returns a nonProfessionals vacation time earned
double nonProfessional::vacationEarned()
{
	//nonProfessionals earn vacation days slower than Professionals
	return (vacDays + (hoursWorked / 100));
}
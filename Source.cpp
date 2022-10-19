/*
Jesse Gonzalez
Due date: 9/23/2022
Computer Science 303
Programming Assignment 1
*/

#include <iostream>
#include "FUNCTIONS.h"
#include <string>
#include <fstream>
using namespace std;


const int INDEX = 100;

int main() {
	//variables to open a text file
	string file = "readin.txt";
	ifstream inFile;
	inFile.open(file);
	//User input is applied to the recursionOption function
	int userInput = 0;
	//option is used to control the switch case menu
	int option = 0;
	//runner is the main array
	int runner[INDEX] = { 0 };
	//temp will be used for new arrays to be passed back into
	int temp[INDEX + 1] = { 0 };
	//if file has successfully opened
	if (inFile.is_open())
	{
		//read in inputs from readin.txt and insert them into index's of runner
		for (int i = 0; i < INDEX; i++)
		{
			inFile >> runner[i];
			cout << runner[i] << " ";
		}
	}
	else
	{
		cout << "File can't open" << endl;
	}

	//traverse and display the array
	for (int i = 0; i < INDEX; i++)
	{
		cout << runner[i] << " ";
	}
	cout << endl;
	//do-while loops executes the options for the user until they want to terminate the process
	do 
	{
		//list of options for the user
		cout << "Enter an option from the list: " << endl;
		cout << "1. Find An Integer In The List" << endl;
		cout << "2. Modify An Integer In The List" << endl;
		cout << "3. Add An Integer To The End Of The List" << endl;
		cout << "4. Zero An Integer From The List" << endl;
		cout << "5. Exit" << endl;
		cin >> userInput;
		//making sure option is within bounds of the menu
		option = recursionOption(userInput);
		menuOption(option, runner, INDEX);
	} while (option != 5);

	inFile.close();
	
	//using these variables to test out Professional
	double testingThis = 0;
	double rate = .05;
	double salary = 5000;
	double vacationDays = 20;
	double salariedHours = 50;
	//initializing Professional, Jimmy
	Professional Jimmy(salary, rate, vacationDays, salariedHours);
	cout << "Professional Testing: " << endl;
	//testing vacationEared
	testingThis = Jimmy.vacationEarned();
	cout << "Testing vacation hours earned resulted in " << testingThis << " Hours." << endl;
	//testing healthContributions
	testingThis = Jimmy.healthContributions();
	cout << "Testing healthContributions resulted in: $" << testingThis << " in health expenses taken from weekly check." << endl;
	//testing weeklySalary
	testingThis = Jimmy.weeklySalary();
	cout << "Testing weeklySalary resulted in: $" << testingThis << " weekly salary." << endl;

	//using these variables to test out nonProfessional
	double nTesting = 0;
	double nRate = .05;
	double nHourlySalary = 25;
	double nVacationDays = 10;
	double nHoursThisWeek = 34;
	//initializing nonProfessional, Stewie
	nonProfessional Stewie(nHourlySalary, nRate, nVacationDays, nHoursThisWeek);
	cout << "NonProfessional testing: " << endl;
	nTesting = Stewie.vacationEarned();
	cout << "Testing vacations hours earned resulted in " << nTesting << " Hours." << endl;
	nTesting = Stewie.healthContributions();
	cout << "Testing health Contributions resulted in: $" << nTesting << " in health expenses taken from weekly check." << endl;
	nTesting = Stewie.weeklySalary();
	cout << "Testing weeklySalary resulted in: $" << nTesting << " weekly salary." << endl;

	return 0;
}


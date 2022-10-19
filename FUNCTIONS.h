#pragma once

#include <iostream>
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void menuOption(int option, int array[], const int ARRSIZE);
void isIntegerThere(int target, int array[], const int ARRSIZE);
int modifyInteger(const int TARGET, int array[], const int TOMOD, const int ARRSIZE);
int addInteger(const int ADDNUM, int array[], int arrSize);
int zeroInteger(int index, int array[], const int ARRSIZE);
int recursionOption(int userInput);
class Employee
{
private:
	double healthcarePay;
	double paymentRate;
	double vacationDays;
	double hoursWorked;
public:
	Employee();
	Employee(double hcP, double pR, double vD, double hours);
	virtual double weeklySalary() = 0;
	virtual double healthContributions() = 0;
	virtual double vacationEarned() = 0;
};

class Professional: public Employee
{
private:
	double monthlyRate;
	double healthTax;
	double vacDays;
	double salaryHours;
public:
	Professional(double hcp, double pmr, double vcd, double hours);
	double weeklySalary();
	double healthContributions();
	double vacationEarned();
};

class nonProfessional : public Employee
{
private:
	double weeklyRate;
	double healthTax;
	double vacDays;
	double hoursWorked;
public:
	nonProfessional(double wR, double hT, double vD, double hR);
	double weeklySalary();
	double healthContributions();
	double vacationEarned();
};
#endif
#include "date.h"
#include <iostream>
#include <iomanip>
using namespace std;


//*********************************************************************************************
//*********************************************************************************************
// D A T E . C P P
//This stub (for now) should be implemented in date.cpp
//*************************************************************************************
//Name: Date
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to 01/01/0001 date
//Description: This is the default constructor which will be called automatically when
//an object is declared. It will initialize the state of the class
//
//*************************************************************************************
Date::Date()
{
	myMonth = 01;
	myDay = 01;
	myYear = 0001;
}
//*************************************************************************************
//Name: Date
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: myDate, myMonth, and myYear are initialized to values passed into the method, daysInMonths will change if it is a leap year.
//Description: This is the explict constructor which require 3 arguments to be passed into it. These
//three arguments initialize myDay, myMonth, and myYear
//
//
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
	
	check_month(m);
	check_year(y);
	check_day(d,m);
	check_leap(y);
	

}
//*************************************************************************************
//Name: Display
//Precondition: myDay, myMonth, and myYear are intiliazed
//Postcondition: This function does not change anything in memory
//Description: This function is used to display the date
//
//
//*************************************************************************************
void Date::display()
{

	cout << setfill('0') << setw(2) << myMonth;
	cout << "/";
	cout << setfill('0') << setw(2) << myDay;
	cout << "/";
	cout << setfill('0') << setw(4) << myYear << endl;

}
//*************************************************************************************
//Name: getMonth
//Precondition: myDay, myMonth, and myYear are intiliazed
//Postcondition: This function does not change anything in memory
//Description: This is accessor method for myMonth
//
//
//*************************************************************************************
int Date::getMonth()
{
	return myMonth;
}
//*************************************************************************************
//Name: getDay
//Precondition: myDay, myMonth, and myYear are intiliazed
//Postcondition: This function does not change anything in memory
//Description: This is accessor method for myDay
//
//
//*************************************************************************************
int Date::getDay()
{
	return (int)myDay;
}
//*************************************************************************************
//Name: getYear
//Precondition: myDay, myMonth, and myYear are intiliazed
//Postcondition: This function does not change anything in memory
//Description: This is accessor method for myYear
//
//
//*************************************************************************************
int Date::getYear()
{
	return myYear;
}
//*************************************************************************************
//Name: setMonth
//Precondition: myDay, myMonth, and myYear are intiliazed
//Postcondition: This Changes the value of myMonth
//Description: This function is used to access the private myMonth to a new value.
//
//
//*************************************************************************************
void Date::setMonth(unsigned m)
{
	myMonth = m;
}
//*************************************************************************************
//Name: setDay
//Precondition: myDay, myMonth, and myYear are intiliazed
//Postcondition: This function is used to access the private myDay to a new value.
//Description: This function is used to access the private myDay to a new value.
//
//
//*************************************************************************************
void Date::setDay(unsigned d)
{
	myDay = d;
}
//*************************************************************************************
//Name: getYear
//Precondition: myDay, myMonth, and myYear are intiliazed
//Postcondition: This function is used to access the private myYear to a new value.
//Description: This function is used to access the private myYear to a new value.
//
//
//*************************************************************************************
void Date::setYear(unsigned y)
{
	myYear = y;
}
//*************************************************************************************
//Name: Check_day
//Precondition: myMonth, and myYear are intiliazed
//Postcondition: If the condition is met myDay is set and if it is not met error flag is changed to true
//Description: This function is called in the explict constructor and makes sure the day that is passed is a valid date.
//
//
//*************************************************************************************
void Date::check_day(unsigned d, unsigned m) {
	if ((d < 1) || (d > daysInMonths[m - 1])) {
		cout << "Ivalid date\n";
		error_flag = true;
	}
	else {
		myDay = d;
		error_flag = false;
	}
}
//*************************************************************************************
//Name: Check_month
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: If the condition is met myMonth is set and if it is not met error flag is changed to true
//Description: This function is called in the explict constructor and makes sure the month that is passed is a valid month.
//
//
//*************************************************************************************
void Date::check_month(unsigned m) {
	if ((m > 0) & (m < 13)) {
		myMonth = m;
		error_flag = false;
	}
	else {
		cout << "Ivalid month \n";
		error_flag = true;
	}
}
//*************************************************************************************
//Name: Check_year
//Precondition:  myMonth are intiliazed
//Postcondition: If the condition is met myMonth is set and if it is not met error flag is changed to true
//Description: This function is called in the explict constructor and makes sure the year that is passed is a valid year.
//
//
//*************************************************************************************
void Date::check_year(unsigned y) {
	if ((y > 0)) {
		myYear = y;
		error_flag = false;
		if (((y % 4 == 0) & (y % 100 == 0) & (y % 400 == 0)) || ((y % 4 == 0) & (y % 100 != 0))) {
			daysInMonths[1] = 29;
		}
		else {
			daysInMonths[1] = 28;
		}
	}
	else {
		cout << "Invalid year\n";
		error_flag = true;
	}
}
//*************************************************************************************
//Name: Check_leap
//Precondition: myDay, myMonth, and myYear are intiliazed
//Postcondition: Nothing in memory changes
//Description: This function is called in the explict constructor and determines if a leap year
//
//
//*************************************************************************************
void Date::check_leap(unsigned y) {
	if (daysInMonths[1] == 29 && error_flag == false)
	{
		cout << y << " is a leap year \n";
	}
}
//*************************************************************************************
//Name: ostream
//Precondition: myDay, myMonth, and myYear are intiliazed
//Postcondition: Nothing in memory changes
//Description: This function prints the mymonth, myDay, and myYear for a object.
//
//
//*************************************************************************************
ostream& operator<<(ostream& out, Date& dateObj)
{
	out << dateObj.myMonth << '/' << dateObj.myDay << '/' << dateObj.myYear;
	return out;
}


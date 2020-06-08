#ifndef DATE_H
#define DATE_H
#include <string>

using namespace std;

class Date
{
public:
	Date(); //default constructor; sets m=01, d=01, y =0001
	Date(unsigned m, unsigned d, unsigned y); //explicit-value constructor to set date equal to today's
	//date. Use 2-digits for month (m) and day (d), and 4-digits for year (y); this function should
	//print a message if a leap year.
	void display();//output Date object to the screen
	int getMonth();//accessor to output the month
	int getDay();//accessor to output the day
	int getYear();//accessor to output the year
	void setMonth(unsigned m);//mutator to change the month
	void setDay(unsigned d);//mutator to change the day
	void setYear(unsigned y);//mutation to change the year
	friend ostream& operator<<(ostream& out, Date& dateObj);
private:
	int myMonth, myDay, myYear; //month, day, and year of a Date obj respectively
	unsigned daysInMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	void check_day(unsigned d, unsigned m);
	void check_month(unsigned m);
	void check_year(unsigned y);
	void check_leap(unsigned y);
	bool error_flag = false;
};
#endif


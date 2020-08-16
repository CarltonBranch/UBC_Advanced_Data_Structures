#pragma once
#include <string>

class Date {
private: 
	int day, month, year;
	static const int base_year = 1800;
	int daysPassed;
	//utility method
	int getMonthInDays(int month, int year);

public:
	//constructor
	Date(int d, int m, int y);
	Date(int given_date);
	
	//accessors
	int getDay();
	int getMonth();
	int getYear();
	int getDaysPassed();
	std::string getDate();

	//calculations
	bool isLeapYear(int year);

	//operator overloads
	int operator-(Date& d2);
	Date operator+(int increment);
	Date operator-(int decrement);
	Date* operator=(Date other_date);
	bool operator==(Date other_date);
};

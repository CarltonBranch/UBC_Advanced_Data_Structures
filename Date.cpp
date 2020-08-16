#include "Date.h"
#include <iostream>


Date::Date(int p) {
	//copy p to daysPassed
	daysPassed = p;
	int num_years = 0;
	int curr_year = base_year;

	//calculate the year
	while (p >= 365)
	{
		isLeapYear(curr_year) ? p -= 366 : p -= 365;
		curr_year++;
	}
	year = curr_year;

	//calculate the correct month;
	int curr_month = 1;
	while (true)
	{
		auto days_in_month = getMonthInDays(curr_month, curr_year);
		if (p >= days_in_month)
			p -= days_in_month;
		else
			break;
		++curr_month;
	}
	month = curr_month;

	//calculate the remaining days
	day = (p == 0) ? 1 : p;
}

Date::Date(int d, int m, int y):day(d), month(m), year(y) {
//days passed since this date: 1, 1, <base year>

	daysPassed = 0;
	//calculate the number of years in days
	for (int i = base_year; i < y; ++i)
	{
		daysPassed += isLeapYear(i) ? 366 : 365;
	}
	//calculate the number of months in days
	for (int i = 1; i < m; ++i)
	{
		daysPassed += getMonthInDays(i, year);
	}
	//add the number of days 
	daysPassed += day;
	daysPassed--;
}

int Date::getMonthInDays(int month, int year) {

	switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 9: case 11:
			return 30;
		case 2:
			return isLeapYear(year) ? 29 : 28;
	}
}

bool Date::isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0) ? true: false;
}

std::string Date::getDate() { 
	std::string result;
	result.append(std::to_string(day));
	result.append("/");
	result.append(std::to_string(month));
	result.append("/");
	result.append(std::to_string(year));
	return result; }

int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }
int Date::getDaysPassed() { return daysPassed; }

//operator overloads
Date Date::operator+(int increment){

	while (increment > 0)
	{
		--increment;
		++day;
		if (day > getMonthInDays(month, year)) {
			if (month == 12)
			{
				month = 1;
				++year;
				}
			else
			{
				++month;
			}
			day = 1;
		}
	}
	return *this;

}
Date Date::operator-(int decrement){

	while (decrement > 0)
	{
		--decrement;
		--day;

		if (day == 0)
		{
			if (month > 1)
			{
				--month;
			}
			else
			{
				month = 12;
				--year;
			}
			day = getMonthInDays(month, year);
		}
	}
	return *this;
}

int Date::operator-(Date& d2) {
	return this->daysPassed - d2.getDaysPassed();
}

Date* Date::operator=(Date other_date) {
	day = other_date.day;
	month = other_date.month;
	year = other_date.year;
	daysPassed = other_date.daysPassed;
}

bool Date::operator==(Date other_date) {
	return (
		day == other_date.day
		&& month == other_date.month
		&& year == other_date.year
		);
}
// Assigment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Date.h"
#include <iostream>

int main() {
	Date d = Date(1, 1, 1801);
	std::cout << d.getDaysPassed() << std::endl;

	Date d2 = Date(365);
	std::cout << d2.getDate()<<std::endl;

	Date d3 = Date(1, 1, 1980);
	d3 - 30;
	std::cout << d3.getDate() << std::endl;

	return 0;
}

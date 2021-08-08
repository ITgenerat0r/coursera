#pragma once 

#include <string>
#include <iostream>

class Date {
public:
	Date();
	Date(int new_year, int new_month, int new_day);

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;


	bool Is_next_sumbol_number(std::istream& c);

	bool ValidDate(const std::string& date);

	bool setDatefromString(const std::string& date);

	// bool operator<(const Date& date);

private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs);


std::ostream& operator<<(std::ostream& stream, const Date& date);


Date ParseDate(std::istream& in);
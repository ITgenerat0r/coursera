#pragma once 



class Date {
public:
	Date();
	Date(int new_year, int new_month, int new_day){
		year = new_year;
		month = new_month;
		day = new_day;
	}

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;


	bool Is_next_sumbol_number(istream& c);

	bool ValidDate(const string& date);

	bool setDatefromString(const string& date);

	// bool operator<(const Date& date);

private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs);


ostream& operator<<(ostream& stream, const Date& date);

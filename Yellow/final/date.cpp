

#include "date.h"
#include <sstream>
#include <iomanip>


using namespace std;



	Date::Date(){};
	Date::Date(int new_year, int new_month, int new_day){
		year = new_year;
		month = new_month;
		day = new_day;
	}

	int Date::GetYear() const{
		return year;
	};
	int Date::GetMonth() const{
		return month;
	};
	int Date::GetDay() const {
		return day;
	};


	bool Date::Is_next_sumbol_number(istream& c){
		// cout << " Is_next_sumbol_number: " << c.peek() << " " << (char)c.peek() << endl;
		if (c.peek() > 47 && c.peek() < 58 || c.peek() == 45 || c.peek() == 43){
			return true;
		}
		return false;
	};

	bool Date::ValidDate(const string& date){
		stringstream ss(date);
		int day, month, year;
		if (ss && Is_next_sumbol_number(ss)){
			ss >> year;
			if (ss && ss.peek() == 45){
				ss.ignore(1);
				if (ss && Is_next_sumbol_number(ss)){
					ss >> month;
					if (ss && ss.peek() == 45){
						ss.ignore(1);
						if (ss && Is_next_sumbol_number(ss)){
							ss >> day;
							if(ss.peek() == -1){
								if (month < 1 || month > 12){
									cout << "Month value is invalid: " << month << endl;
									return false;
								}
								if (day < 1 || day > 31){
									cout << "Day value is invalid: " << day << endl;
									return false;
								}
								return true;
							}
						}
					}
				}
			}
		}
		cout << "Wrong date format: " << date << endl;
		return false;
	};

	bool Date::setDatefromString(const string& date){
		if(ValidDate(date)){
			stringstream ss(date);
			ss >> year;
			ss.ignore(1);
			ss >> month;
			ss.ignore(1);
			ss >> day;
			return true;
		}
		return false;
	};

	// bool operator<(const Date& date){
 //    if(GetYear()<date.GetYear()){
 //        return true;
 //    } else if (GetYear()<date.GetMonth()){
 //        return true;
 //    } else if (GetYear() < date.GetDay()){
 //        return true;
 //    }
 //    return false;
	// };


bool operator<(const Date& lhs, const Date& rhs){
	return lhs.GetYear()*372+lhs.GetMonth()*31+lhs.GetDay() < rhs.GetYear()*372+rhs.GetMonth()*31+rhs.GetDay();
};


// bool operator<(const Date& lhs, const Date& rhs){
// 	if(lhs.GetYear()<rhs.GetYear()){
// 		return true;
// 	} else if (lhs.GetMonth()<rhs.GetMonth()){
// 		return true;
// 	} else if (lhs.GetDay() < rhs.GetDay()){
// 		return true;
// 	}
// 	return false;
// };


ostream& operator<<(ostream& stream, const Date& date){
    stream << setw(4) << setfill('0') << date.GetYear() << '-' << setw(2) << setfill('0') << date.GetMonth() << '-' << setw(2) << setfill('0') << date.GetDay();
    return stream;
}




Date ParseDate(std::istringstream& in){
	Date date;
	string str_date;
	getline(in, str_date, ' ');
	date.setDatefromString(str_date);
	return date;
}
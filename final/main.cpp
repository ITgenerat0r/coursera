#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>


using namespace std;


class Date {
public:
	Date(){};
	Date(int new_year, int new_month, int new_day){
		year = new_year;
		month = new_month;
		day = new_day;
	}

	int GetYear() const{
		return year;
	};
	int GetMonth() const{
		return month;
	};
	int GetDay() const {
		return day;
	};
private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs){
	return lhs.GetYear()*372+lhs.GetMonth()*31+lhs.GetDay() < rhs.GetYear()*372+rhs.GetMonth()*31+rhs.GetDay();
};



class Database {
public:
	void AddEvent(const Date& date, const string& event);
	bool DeleteEvent(const Date& date, const string& event);
	int  DeleteDate(const Date& date);

	set<string> Find(const Date& date) const;
	void Print() const;
private:
	map<Date, set<string>> base;
};


bool Is_next_sumbol_number(istream& c){
	// cout << " Is_next_sumbol_number: " << c.peek() << " " << (char)c.peek() << endl;
	if (c.peek() > 47 && c.peek() < 58 || c.peek() == 45 || c.peek() == 43){
		return true;
	}
	return false;
}

bool ValidDate(const string& date){
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

	return false;
}



int main() {
  Database db;
    
  string command;
  while (getline(cin, command)) {
    // Считайте команды с потока ввода и обработайте каждую
    string cm;
    stringstream input(command);
    input >> cm;
    if (cm == "Add"){
    	string dt, ev;
    	input >> dt >> ev;
    	cout << "Command: " << cm << "   Date: " << dt << "   Event: " << ev << endl;
    } else if (cm == "Del"){
    	string dt, ev = "";
    	input >> dt;
    	if (input){
    		input >> ev;
    	}
    	cout << "Command: " << cm << "   Date: " << dt << "   Event: " << ev << endl;
    } else if (cm == "Find"){
    	string dt;
    	input >> dt;
    	cout << "Command: " << cm << "   Date: " << dt << endl;
    	cout << ValidDate(dt) << endl;
    } else if (cm == "Print"){
    	cout << "Command: " << cm << endl;
    } else {
    	cout << "Unknown command: " << cm << endl;
    }
  }

  return 0;
}


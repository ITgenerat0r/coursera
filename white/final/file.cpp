#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <fstream>


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


	bool Is_next_sumbol_number(istream& c){
		// cout << " Is_next_sumbol_number: " << c.peek() << " " << (char)c.peek() << endl;
		if (c.peek() > 47 && c.peek() < 58 || c.peek() == 45 || c.peek() == 43){
			return true;
		}
		return false;
	};

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

	bool setDatefromString(const string& date){
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

private:
	int year;
	int month;
	int day;
};

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



class Database {
public:
	void AddEvent(const Date& date, const string& event){
		base[date].insert(event);
	};
	
	bool DeleteEvent(const Date& date, const string& event){
		if(base.count(date) > 0){
			if(base[date].count(event)){
				base[date].erase(event);
				return true;
			}
		}
		return false;
	};
	
	int  DeleteDate(const Date& date){
		if(base.count(date) > 0){
			int r = base[date].size();
			base.erase(date);
			return r;
		}
		return 0;
	};

	void Find(const Date& date) const {
		if (base.count(date)){
			for (const string& ev : base.at(date)){
				cout << ev << endl;
			}
		}
	};
	
	void Print() const {
		for(const auto& [date, events] : base){
			for (const string& event : events){
				cout << date << " " << event << endl;
			}
		}
	};

	void Save()const{
		ofstream output("database.mdb");
		for(const auto& [date, events] : base){
			for (const string& event : events){
				output << "Add " << date << " " << event << endl;
			}
		}
	}

	void Load(){
		ifstream file("database.mdb");
		std::string command;
		while (getline(file, command)) {
			string cm;
		    stringstream input(command);
		    input >> cm;
		    if (cm == "Add"){
		    	string dt, ev;
		    	input >> dt >> ev;
		    	Date date;
		    	if (date.setDatefromString(dt)){
			    	base[date].insert(ev);
			    } else {
			    	return;
			    }
		    }
		}
	}

private:
	map<Date, set<string>> base;
};








int main() {
  Database db;
  ifstream file("data.dt");
  string command;
  while (getline(cin, command)) {
    // Считайте команды с потока ввода и обработайте каждую
    string cm;
    stringstream input(command);
    input >> cm;
    if (cm == "Add"){
    	string dt, ev;
    	input >> dt >> ev;
    	Date date;
    	if (date.setDatefromString(dt)){
	    	db.AddEvent(date, ev);
	    } else {
	    	return 0;
	    }
    	// cout << "Command: " << cm << "   Date: " << dt << "   Event: " << ev << endl;
    } else if (cm == "Del"){
    	string dt, ev = "";
    	input >> dt;
    	Date date;
    	if (date.setDatefromString(dt)){
	    	if (input.peek() > -1){
	    		// cout << "'" << input.peek() << "'" << endl;
	    		input >> ev;
	    		if(db.DeleteEvent(date, ev)){
	    			cout << "Deleted successfully\n";
	    		} else {
	    			cout << "Event not found\n";
	    		}
	    	} else {
	    		cout << "Deleted " << db.DeleteDate(date) << " events\n";
	    	}
	    } else {
	    	return 0;
	    }
    	// cout << "Command: " << cm << "   Date: " << dt << "   Event: " << ev << endl;
    } else if (cm == "Find"){
    	string dt;
    	input >> dt;
    	Date date;
    	if(date.setDatefromString(dt)){
	    	db.Find(date);
			} else {
	    	return 0;
	    }
    	// cout << "Command: " << cm << "   Date: " << dt << endl;
    	// cout << ValidDate(dt) << endl;
    } else if (cm == "Print"){
    	db.Print();
    	// cout << "Command: " << cm << endl;
    } else if (cm == "Save"){
    	db.Save();
    	// cout << "Command: " << cm << endl;
    } else if (cm == "Load"){
    	db.Load();
    	// cout << "Command: " << cm << endl;
    } else if (cm != ""){
    	cout << "Unknown command: " << cm << endl;
    	return 0;
    }
  }

  return 0;
}


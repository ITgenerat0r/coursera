
#include "database.h"

#include <iostream>

using namespace std;


	void Database::AddEvent(const Date& date, const string& event){
		base[date].insert(event);
	};
	
	bool Database::DeleteEvent(const Date& date, const string& event){
		if(base.count(date) > 0){
			if(base[date].count(event)){
				base[date].erase(event);
				return true;
			}
		}
		return false;
	};
	
	int  Database::DeleteDate(const Date& date){
		if(base.count(date) > 0){
			int r = base[date].size();
			base.erase(date);
			return r;
		}
		return 0;
	};

	void Database::Find(const Date& date) const {
		if (base.count(date)){
			for (const string& ev : base.at(date)){
				cout << ev << endl;
			}
		}
	};
	
	void Database::Print() const {
		for(const auto& [date, events] : base){
			for (const string& event : events){
				cout << date << " " << event << endl;
			}
		}
	};

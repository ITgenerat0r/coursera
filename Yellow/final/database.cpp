
#include "database.h"

#include <iostream>

using namespace std;


	void Database::Add(const Date& date, const string& event){
		if(base[date].count(event)){
			base_vector[date].push_back(event);
			base[date].insert(event);
		}
	};
	
	bool Database::DeleteEvent(const Date& date, const string& event){
		if(base.count(date) > 0){
			if(base[date].count(event)){
				base[date].erase(event);
				auto it = find(begin(base_vector[date]), end(base_vector[date]), event);
				base_vector[date].erase(it);
				return true;
			}
		}
		return false;
	};
	
	int  Database::DeleteDate(const Date& date){
		if(base.count(date) > 0){
			int r = base[date].size();
			base.erase(date);
			base_vector.erase(date);
			return r;
		}
		return 0;
	};

	void Database::Find(const Date& date) const {
		if (base_vector.count(date)){
			for (const string& ev : base_vector.at(date)){
				cout << ev << endl;
			}
		}
	};
	
	void Database::Print(std::ostream& out) const {
		for(const auto& [date, events] : base_vector){
			for (const string& event : events){
				out << date << " " << event << endl;
			}
		}
	};


	int Database::RemoveIf(bool b){
		return 0;
	};



	vector<string> Database::FindIf(bool b){
		std::vector<string> v;
		return v;
	}

	string Database::Last(Date& date){
		return "";
	}
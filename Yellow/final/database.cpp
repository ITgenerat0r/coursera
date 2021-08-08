
#include "database.h"

#include <iostream>

using namespace std;

template <typename First, typename Second>
ostream& operator << (ostream& out, const pair<First, Second>& p) {
  return out << '(' << p.first << ',' << p.second << ')';
}


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


	int Database::RemoveIf(function<bool(const Date& date, const string& event)> predicate) {
		auto count = 0;
		for (auto storageIt = base_vector.begin(); storageIt != base_vector.end();) {
			auto d = (*storageIt).first;
			auto beforeSize = (*storageIt).second.size();
			auto newEnd =
			stable_partition((*storageIt).second.begin(), (*storageIt).second.end(),
				[predicate, d](string s) { return !predicate(d, s); });

			(*storageIt).second.erase(newEnd, (*storageIt).second.end());
		    auto afterSize = (*storageIt).second.size();
		    count += (beforeSize - afterSize);

		    for (auto setStorageIt = base.begin();
		    	setStorageIt != base.end();) {
		    	for (auto it = (*setStorageIt).second.begin();
		    		it != (*setStorageIt).second.end();) {
		    		if (predicate((*setStorageIt).first, *it)) {
		    			(*setStorageIt).second.erase(it++);
		    		} else {
		    			++it;
		    		}
		    	}

		    	if ((*setStorageIt).second.empty()) {
		    		setStorageIt = base.erase(setStorageIt);
		    	} else {
		    		++setStorageIt;
		    	}
		    }

		    if ((*storageIt).second.empty()) {
		    	storageIt = base_vector.erase(storageIt);
		    } else {
		    	++storageIt;
		    }
		}
		return count;
	};



	vector<pair<Date, string>> Database::FindIf(function<bool(const Date& date, const string& event)> predicate) const {
		vector<pair<Date, string>> found;
		for (const auto& pair : base_vector) {
			auto d = pair.first;
			vector<string> tmp;
			copy_if(pair.second.begin(), pair.second.end(), back_inserter(tmp),
				[predicate, d](string s) { return predicate(d, s); });
			for (const auto& ev : tmp) {
				found.push_back({d, ev});
			}
		}
		return found;
	}

	pair<Date, string> Database::Last(const Date date){
		if (base_vector.empty() || date < base_vector.begin()->first) {
			throw invalid_argument("Database is empty or date is too old");
		} else {
			auto it = prev(base_vector.upper_bound(date));
			return {(*it).first, (*it).second.back()};
		}
	}
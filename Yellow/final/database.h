#pragma once

#include <string>
#include <map>
#include <vector>
#include <set>
#include <functional>
#include <algorithm>

#include "date.h"


class Database {
public:
	void Add(const Date& date, const std::string& event);
	
	bool DeleteEvent(const Date& date, const std::string& event);
	
	int  DeleteDate(const Date& date);

	int RemoveIf(std::function<bool(const Date& date, const std::string& event)> predicate);

	std::vector<std::string> FindIf(std::function<bool(const Date& date, const std::string& event)> predicate);

	std::pair<Date, std::string> Last(const Date date);

	void Find(const Date& date) const;
	
	void Print(std::ostream& out) const;

private:
	std::map<Date, std::set<std::string>> base;
	std::map<Date, std::vector<std::string>> base_vector;
};
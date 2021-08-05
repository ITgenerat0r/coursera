#pragma once

#include <string>
#include <map>
#include <vector>
#include <set>

#include "date.h"


class Database {
public:
	void Add(const Date& date, const std::string& event);
	
	bool DeleteEvent(const Date& date, const std::string& event);
	
	int  DeleteDate(const Date& date);

	int RemoveIf(bool b);

	std::vector<std::string> FindIf(bool b);

	std::string Last(Date& date);

	void Find(const Date& date) const;
	
	void Print(std::ostream& out) const;

private:
	std::map<Date, std::set<std::string>> base;
	std::map<Date, std::vector<std::string>> base_vector;
};
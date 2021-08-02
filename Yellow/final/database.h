#pragma once




class Database {
public:
	void AddEvent(const Date& date, const string& event);
	
	bool DeleteEvent(const Date& date, const string& event);
	
	int  DeleteDate(const Date& date);

	void Find(const Date& date) const;
	
	void Print() const;

private:
	map<Date, set<string>> base;
};
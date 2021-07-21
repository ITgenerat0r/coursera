#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <numeric>


using namespace std;


struct Date
{
	int year;
	int month;
	int day;
};

int ToInt(string s){
	stringstream ss(s);
	int r;
	ss >> r;
	return r;
}

istream& operator>> (istream& in, Date& date){
	string ex;
	in >> ex;
	stringstream ss(ex);
	string tmp;
	getline(ss, tmp, '-');
	date.year = ToInt(tmp);
	getline(ss, tmp, '-');
	date.month = ToInt(tmp);
	getline(ss, tmp, '-');
	date.day = ToInt(tmp);
	return in;
}

bool operator<= (const Date& dl, const Date& dr){
	if(dl.year != dr.year){
		return dl.year <= dr.year;
	} else if (dl.month != dr.month){
		return dl.month <= dr.month;
	} else {
		return dl.day <= dr.day;
	}
}

bool operator< (const Date& dl, const Date& dr){
	if(dl.year != dr.year){
		return dl.year < dr.year;
	} else if (dl.month != dr.month){
		return dl.month < dr.month;
	} else {
		return dl.day < dr.day;
	}
}




void operator+= (Date& d, int a){
	d.day += a;
	if(d.month == 2){
		if(d.year % 4 == 0){
			if(d.day > 29){
				d.day = 1;
				d.month++;
			}
			return;
		} else {
			if(d.day > 28){
				d.day = 1;
				d.month++;
			}
			return;
		}
	}
	if(d.day < 31){
		return;
	} else if (d.day > 31){
		d.day = 1;
		if(++d.month > 12){
			d.month = 1;
			d.year++;
		}
		return;
	} else {
		switch(d.month){
			case 4:
			case 6:
			case 9:
			case 11: {
				d.day = 1;
				d.month++;
			}
		}
		return;
	}

}


int main(){
	map<Date, int> base;
	int q;
	cin >> q;
	while(q-->0){
		string command;
		cin >> command;
		Date date_from, date_to;
		cin >> date_from >> date_to;
		if(command == "ComputeIncome"){
			cout << "ComputeIncome\n";
			cout << accumulate(begin(base), end(base));
		}else if(command == "Earn"){
			cout << "Earn\n";
			int value;
			cin >> value;
			for(Date d = date_from; d <= date_to; d+=1){
				base[d] = value;
			}

		}
	}
	return 0;
}
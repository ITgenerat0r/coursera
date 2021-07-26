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



istream& operator>> (istream& in, Date& date);
bool operator<= (const Date& dl, const Date& dr);
bool operator< (const Date& dl, const Date& dr);
int operator- (const Date& d1, const Date& d2);
void operator+= (Date& d, int a);


	

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

ostream& operator<< (ostream& out, const Date& date){
	out << date.year << "-";
	out << date.month << "-";
	out << date.day << endl;
	return out;
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

int operator- (const Date& d1, const Date& d2){
	Date dl = d1;
	Date dr = d2;
	int k = 0;
	if(dl < dr){
		k = -1;
		while(dl < dr){
			k--;
			dl+=1;
		}
	} else {
		k = 1;
		while(dr < dl){
			k++;
			dr+=1;
		}
	}
	return k;

}

void PrintMap(map<Date, int>& a){
	cout << " map\n";
	for(const auto& [k, x] : a){
		// cout << " " << x;
		cout << k << " = " << x << endl;
	}
	cout << endl;
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
			int s = 0;
			for(Date d = date_from; d <= date_to; d+=1){
				if(base.count(d)){
					s += base.at(d);
				}
			}
			cout << s << endl;
			// PrintMap(base);
			// cout << accumulate(begin(base), end(base), s);
		}else if(command == "Earn"){
			int value;
			cin >> value;
			value /= date_to - date_from;
			// cout << value << endl;
			for(Date d = date_from; d <= date_to; d+=1){
				if(base.count(d)){
					base[d] += value;
				}else{
					base[d] = value;
				}
			}
			// PrintMap(base);

		}
	}
	return 0;
}
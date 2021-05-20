#include <iostream>
// #include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
    // cout << " 	ChangeFirstName on " << first_name << " from " << year << endl;
    if(m.count(year) == 0){
    	m[year].surname = "with unknown last name";
    }
    m[year].name = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    // cout << " 	ChangeLastName on " << last_name << " from " << year <<  endl;
    if(m.count(year) == 0){
    	m[year].name = "with unknown first name";
    }
    m[year].surname = last_name;
  }

  void Print(){
  	cout << "\n 	Print----\n";
  	for (const auto& [it_y, it_name] : m){
  		cout << " 	" << it_y << "	" << it_name.name << " - - - " << it_name.surname << endl;
  	}
  	cout << " 	---------" << endl;
  }

  string GetFullName(int year) {
  // получить имя и фамилию по состоянию на конец года year
  	string n = "with unknown first name";
  	string sn = "with unknown last name";
	for(const auto& [it_y, it_name] : m){
		if(it_y>year){
			break;
		} else {
			if(m[it_y].name != "with unknown first name"){
				n = m[it_y].name;
			}
			if(m[it_y].surname != "with unknown last name"){
				sn = m[it_y].surname;
			}
		}
	}

	if (n == "with unknown first name"){
		if(sn == "with unknown last name"){
			return "Incognito";
		}
		return sn + " " + n;
	}
	return n + " " + sn;
  	
  }

  string GetFullNameWithHistory(int year) {
  // получить имя и фамилию по состоянию на конец года year
  	string n = "with unknown first name";
  	string sn = "with unknown last name";
  	string add_n = "", add_sn = "";
  	std::vector<string> n_adds, sn_adds;
	for(const auto& [it_y, it_name] : m){
		if(it_y>year){
			break;
		} else {
			if(m[it_y].name != "with unknown first name"){
				if(n != "with unknown first name"){
					if(count(n_adds.begin(), n_adds.end(), n)==0){
						n_adds.push_back(n);
					}
				}
				n = m[it_y].name;
			}
			if(m[it_y].surname != "with unknown last name"){
				if(sn != "with unknown last name"){
					if(count(sn_adds.begin(), sn_adds.end(), sn)==0){
						sn_adds.push_back(sn);
					}
				}
				sn = m[it_y].surname;
			}
		}
	}

	string help = "";
	for(const auto& i : n_adds){
		if(i==n){
			help = ", " + i;
			continue;
		}
		if (add_n == ""){
			add_n = i + help + ")";
			help = "";
		} else {
			add_n = i + help + ", " + add_n;
			help = "";
		}
	}
	for(const auto& i : sn_adds){
		if(i == sn){
			help = ", " + i;
			continue;
		}
		if(add_sn == ""){
			add_sn = i + help + ")";
			help = "";
		} else {
			add_sn = i + help + ", " + add_sn;
			help = "";
		}
	}


	if(add_n != ""){
		n += " (" + add_n;
	}
	if(add_sn != ""){
		sn += " (" + add_sn;
	}


	if (n == "with unknown first name"){
		if(sn == "with unknown last name"){
			return "Incognito";
		}
		return sn + " " + n;
	}
	return n + " " + sn;
  	
  }

private:
  // приватные поля
	struct Name
	{
		string name;
		string surname;
	};
	map<int, Name> m;
};



int main() {
  Person person;
  

  
  return 0;
}

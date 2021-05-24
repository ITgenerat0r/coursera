#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
// #include <locale>

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
  string name;  // изначально имя неизвестно
  
  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
  for (const auto& item : names) {
    // если очередной год не больше данного, обновляем имя
    if (item.first <= year) {
      name = item.second;
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
      break;
    }
  }
  
  return name;
}

string FindNameByYearWithHistory(const map<int, string>& names, int year) {
  string name = "";  // изначально имя неизвестно
  string history = "";
  string last;

  
  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
  for (const auto& item : names) {
    // если очередной год не больше данного, обновляем имя
    if (item.first <= year) {
    	if (name != item.second){
    		if(history != ""){
    			history = ", " + history;
    		}
    		history = name + history;
    	}
      name = item.second;
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
      break;
    }
  }
  
  if (history != ""){
  	history = " (" + history + ")";
  }

  return name + history;
}

class Person {
public:
	Person(const string& name, const string& surname, const int& b){
		first_names[b] = name;
		last_names[b] = surname;
		birth = b;
	}
  void ChangeFirstName(const int& year, const string& first_name) {
  	if (year>birth){
	    first_names[year] = first_name;
  	}
  }
  void ChangeLastName(const int& year, const string& last_name) {
  	if(year>birth){
	    last_names[year] = last_name;
  	}
  }
  string GetFullName(const int& year) const {
  	if(year<birth){
  		return "No person";
  	}
    // получаем имя и фамилию по состоянию на год year
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);
    
    // если и имя, и фамилия неизвестны
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    
    // если неизвестно только имяs
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";
      
    // если неизвестна только фамилия
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";
      
    // если известны и имя, и фамилия
    } else {
      return first_name + " " + last_name;
    }
  }

  string GetFullNameWithHistory(const int& year)const {
  	if(year<birth){
  		return "No person";
  	}
    // получаем имя и фамилию по состоянию на год year
    const string first_name = FindNameByYearWithHistory(first_names, year);
    const string last_name = FindNameByYearWithHistory(last_names, year);
    
    // если и имя, и фамилия неизвестны
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    
    // если неизвестно только имяs
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";
      
    // если неизвестна только фамилия
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";
      
    // если известны и имя, и фамилия
    } else {
      return first_name + " " + last_name;
    }
  }

private:
  map<int, string> first_names;
  map<int, string> last_names;
  int birth;
};



int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
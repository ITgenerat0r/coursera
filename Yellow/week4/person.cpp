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
  
  auto it = names.lower_bound(year);
  if (year == (*it).first){
    name = (*it).second;
  } else if (it != names.begin()){
    it--;
    name = (*it).second;
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
  Person(){};
  Person(const string& name, const string& surname, const int& b){
    first_names[b] = name;
    last_names[b] = surname;
    birth = b;
  }

  void ChangeFirstName(int year, const string& first_name) {
    if (year>=birth){
      first_names[year] = first_name;
    }
  }
  void ChangeLastName(int year, const string& last_name) {
    if (year>=birth){
      last_names[year] = last_name;
    }
  }
  string GetFullName(int year) const {
    if(year<birth){
      return "No person";
    }
    // получаем имя и фамилию по состоянию на год year
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);
    
    // если и имя, и фамилия неизвестны
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    
    // если неизвестно только имя
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

  string GetFullNameWithHistory(int year) const {
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
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}

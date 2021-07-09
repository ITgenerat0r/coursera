#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

// class Person {
// public:
//   // Р’С‹ РјРѕР¶РµС‚Рµ РІСЃС‚Р°РІР»СЏС‚СЊ СЃСЋРґР° СЂР°Р·Р»РёС‡РЅС‹Рµ СЂРµР°Р»РёР·Р°С†РёРё РєР»Р°СЃСЃР°,
//   // С‡С‚РѕР±С‹ РїСЂРѕРІРµСЂРёС‚СЊ, С‡С‚Рѕ РІР°С€Рё С‚РµСЃС‚С‹ РїСЂРѕРїСѓСЃРєР°СЋС‚ РєРѕСЂСЂРµРєС‚РЅС‹Р№ РєРѕРґ
//   // Рё Р»РѕРІСЏС‚ РЅРµРєРѕСЂСЂРµРєС‚РЅС‹Р№
//   void ChangeFirstName(int year, const string& first_name) {
//   }
//   void ChangeLastName(int year, const string& last_name) {
//   }
//   string GetFullName(int year) {
//     return "None";
//   }
// };


// string FindNameByYear(const map<int, string>& names, int year) {
//   string name;  // изначально имя неизвестно
  
//   // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
//   for (const auto& item : names) {
//     // если очередной год не больше данного, обновляем имя
//     if (item.first <= year) {
//       name = item.second;
//     } else {
//       // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
//       break;
//     }
//   }
  
//   return name;
// }
// class Person {
// public:
//   void ChangeFirstName(int year, const string& first_name) {
//     first_names[year] = first_name;
//   }
//   void ChangeLastName(int year, const string& last_name) {
//     last_names[year] = last_name;
//   }
//   string GetFullName(int year) {
//     // получаем имя и фамилию по состоянию на год year
//     const string first_name = FindNameByYear(first_names, year);
//     const string last_name = FindNameByYear(last_names, year);
    
//     // если и имя, и фамилия неизвестны
//     if (first_name.empty() && last_name.empty()) {
//       return "Incognito";
    
//     // если неизвестно только имя
//     } else if (first_name.empty()) {
//       return last_name + " with unknown first name";
      
//     // если неизвестна только фамилия
//     } else if (last_name.empty()) {
//       return first_name + " with unknown last name";
      
//     // если известны и имя, и фамилия
//     } else {
//       return first_name + " " + last_name;
//     }
//   }

// private:
//   map<int, string> first_names;
//   map<int, string> last_names;
// };

void TestGetFullName(){
  cerr << "Start test";
  Person person, person2;
  AssertEqual(person.GetFullName(1900), "Incognito", "Get 1");
  cerr << "\ntest.stage2";
  string name = "TestName";
  string surname = "TestSurname";
  person.ChangeFirstName(1910, name);
  AssertEqual(person.GetFullName(1900), "Incognito", "get 2");
  AssertEqual(person.GetFullName(1920), name+" with unknown last name", "get 3");
  person.ChangeLastName(1950, surname);
  AssertEqual(person.GetFullName(1900), "Incognito", "get 4");
  AssertEqual(person.GetFullName(1920), name+" with unknown last name", "get 5");
  AssertEqual(person.GetFullName(1960), name+" "+surname, "get 6");
  cerr << endl << "Start test 2";

  AssertEqual(person2.GetFullName(1900), "Incognito", "Get 7");
  name = "TestName2";
  surname = "TestSurname2";
  person2.ChangeLastName(1910, surname);
  AssertEqual(person2.GetFullName(1900), "Incognito", "get 8");
  AssertEqual(person2.GetFullName(1920), surname+" with unknown first name", "get 9");
  person2.ChangeFirstName(1950, name);
  AssertEqual(person2.GetFullName(1900), "Incognito", "get 10");
  AssertEqual(person2.GetFullName(1920), surname+" with unknown first name", "get 11");
  AssertEqual(person2.GetFullName(1960), name+" "+surname, "get 12");

  cerr << endl << "End tests\n";

}

int main() {
  TestRunner runner;
  runner.RunTest(TestGetFullName, "GetFullName");
  runner.~TestRunner();
  // РґРѕР±Р°РІСЊС‚Рµ СЃСЋРґР° СЃРІРѕРё С‚РµСЃС‚С‹
  return 0;
}
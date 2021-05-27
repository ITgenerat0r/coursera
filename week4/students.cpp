#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
  string name;
  string last_name;

  int day;
  int month;
  int year;
};

int main() {
  int n;
  cin >> n;

  string name, last_name;
  int day, month, year;
  vector<Student> students;

  for (size_t i = 0; i < n; ++i) {
    cin >> name >> last_name >> day >> month >> year;

    students.push_back(Student{
      name,
      last_name,
      day,
      month,
      year
    });
  }

  int m;
  cin >> m;
  string query;
  int number;

  for (int i = 0; i < m; ++i) {
    cin >> query >> number;
    --number;

    if (query == "name" && number >= 0 && number < n) {
      cout << students[number].name << " "
           << students[number].last_name << endl;
    } else if (query == "date" && number >= 0 && number < n) {
      cout << students[number].day << "."
           << students[number].month << "."
           << students[number].year << endl;
    } else {
      cout << "bad request" << endl;
    }
  }

  return 0;
}

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


#include <string>
#include <sstream>
template <typename Collection>
string Join(const Collection& c, char d) {
  stringstream ss;
  bool first = true;
  for (const auto& i : c) {
    if (!first) {
      ss << d;
    }
    first = false;
    ss << i;
  }
  return ss.str();
}


template <typename T>
ostream& operator << (ostream& out, const vector<T>& vi) {
  return out << '[' << Join(vi, ',') << ']';
}



template <typename T>
void RemoveDuplicates(vector<T>& elements){

    // cout << " " << elements << endl;
    sort(begin(elements), end(elements));
    // cout << " " << elements << endl;
    elements.erase(std::unique(begin(elements), end(elements)),end(elements));
    // elements.erase(er, end(elements));
    // cout << "  "  << elements << endl << endl;
}







int main() {
  vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
  RemoveDuplicates(v1);
  for (int x : v1) {
    cout << x << " ";
  }
  cout << endl;
  
  vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
  RemoveDuplicates(v2);
  for (const string& s : v2) {
    cout << s << " ";
  }
  cout << endl;
  return 0;
}



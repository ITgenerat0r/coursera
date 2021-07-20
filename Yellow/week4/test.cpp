#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


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



int main(){

	vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
	cout << v << endl;
	auto f = find(begin(v), end(v), 6);
	cout << *f << endl;
	cout << v << endl;
	return 0;
}
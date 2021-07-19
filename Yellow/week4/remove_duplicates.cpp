#include <set>
#include <vector>
#include <iostream>

using namespace std;



template <typename T>
void RemoveDuplicates(vector<T>& elements){
	set<T> h;
	for(auto it = begin(elements); it != end(elements); it++){
		if(*(find(begin(elements), it, it)) != *it){
			// h.insert(it);
		} else {
			remove_if(it, end(elements), it);
		}
	}
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



#include <iostream>
#include <set>
#include <cmath>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border){
	set<int>::const_iterator it, it2;
	it = numbers.lower_bound(border);
	if(it != numbers.begin()){
		it2 = prev(it);
	} else {
		return it;
	}
	// it2 = upper_bound(numbers.begin(), numbers.end(), border);
	// cout << "\nInfo   " << border << " " << *it << " " << *it2 << endl;
	if(abs(border - *it2) <= abs(border - *it)){
		return it2;
	} else {
		return it;
	}
}



int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;
      
  set<int> empty_set;
  
  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void PrintVectorPart(const vector<int>& numbers){
	auto r = find_if(numbers.begin(), numbers.end(), [](const int& n){return n < 0;});
	for (auto it = r; it != numbers.begin(); ) {
		cout << *(--it) << " ";
	}
}


int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){

	if(range_begin == range_end || range_begin+1 == range_end){
		return ;
	}
	vector<typename RandomIt::value_type> elements(range_begin, range_end);
	
	MergeSort(begin(elements), begin(elements)+elements.size()/2);
	MergeSort(begin(elements)+elements.size()/2, end(elements));
	merge(begin(elements), begin(elements)+elements.size()/2,
		 begin(elements)+elements.size()/2, end(elements), range_begin);
}


int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
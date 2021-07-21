#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){


	if(range_begin == range_end || range_begin+1 == range_end){
		return ;
	}

	int size = range_end - range_begin;

	vector<typename RandomIt::value_type> elements(range_begin, range_end);

	MergeSort(begin(elements), begin(elements)+size/3);
	MergeSort(begin(elements)+size/3, begin(elements)+size/3*2);
	MergeSort(begin(elements)+size/3*2, end(elements));
	
	vector<typename RandomIt::value_type> extra;

	auto b = back_inserter(extra); 
	
	merge(begin(elements), begin(elements)+size/3,
		 begin(elements)+size/3, begin(elements)+size/3*2, 
		 b);

	merge(begin(extra), end(extra), 
		begin(elements)+size/3*2, end(elements), 
		range_begin);
}








int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}











// vector<typename RandomIt::value_type> elements(range_begin, range_end);

// 	MergeSort(begin(elements), begin(elements)+elements.size()/3);
// 	MergeSort(begin(elements)+elements.size()/3, begin(elements)+elements.size()/3*2);
// 	MergeSort(begin(elements)+elements.size()/3*2, end(elements));
	
// 	vector<typename RandomIt::value_type> back_inserter(begin(elements), begin(elements)+elements.size()/3*2); 
	
// 	merge(begin(elements), begin(elements)+elements.size()/3,
// 		 begin(elements)+elements.size()/3, begin(elements)+elements.size()/3*2, 
// 		 begin(back_inserter));

// 	merge(begin(back_inserter), end(back_inserter), 
// 		begin(elements)+elements.size()/3*2, end(elements), 
// 		range_begin);
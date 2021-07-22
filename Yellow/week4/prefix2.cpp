#include <iostream>
#include <string>
#include <vector>



using namespace std;









// template <typename RandomIt>
// pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix){
// 	RandomIt it_begin, it_end;
// 	string p = prefix;

// 	it_begin = lower_bound(range_begin, range_end, prefix);

// 	// it_end = lower_bound(it_begin, range_end, ++prefix);
// 	p[p.size()-1]++;
// 	it_end = lower_bound(range_begin, range_end, p);

	
// 	if (it_end == range_end){
// 		it_end = it_begin;
// 	}
// 	pair<RandomIt, RandomIt> r = make_pair(it_begin, it_end);
// 	return r;
// }



template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix){
	RandomIt it;

	it = range_end - range_begin;
	if(*it[0] < prefix){
		range_begin = it;
	} else if (*it[0] > prefix){
		range_end = it;
	}


	pair<RandomIt, RandomIt> r = make_pair(range_begin, range_end);
	return r;
}


    

int main() {
  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
  
  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  
  const auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  cout << (mt_result.first - begin(sorted_strings)) << " " <<
      (mt_result.second - begin(sorted_strings)) << endl;
  
  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " " <<
      (na_result.second - begin(sorted_strings)) << endl;
  
  return 0;
}

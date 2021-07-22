#include <iostream>
#include <string>
#include <vector>



using namespace std;


// bool operator< (const std::__cxx11::basic_string<char> s, const char c){
// 	return s[0] < c;
// }


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix){
	RandomIt it_begin, it_end;
	it_begin = find_if(range_begin, range_end, [prefix](const std::__cxx11::basic_string<char> s){ return s[0]<prefix;});

	// it_end = lower_bound(it_begin, range_end, ++prefix);
	it_end = find_if(range_begin, range_end, [prefix](const std::__cxx11::basic_string<char> s){ return s[0]<prefix+1;});

	


	if (it_end == range_end){
		it_end = it_begin;
	}
	pair<RandomIt, RandomIt> r = make_pair(it_begin, it_end);
	// r.first = it_begin;
	// r.second = it_end;
	return r;
}




int main() {
  const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};
  
  const auto m_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
  for (auto it = m_result.first; it != m_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  
  const auto p_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
  cout << (p_result.first - begin(sorted_strings)) << " " <<
      (p_result.second - begin(sorted_strings)) << endl;
  
  const auto z_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
  cout << (z_result.first - begin(sorted_strings)) << " " <<
      (z_result.second - begin(sorted_strings)) << endl;
  
  return 0;
}




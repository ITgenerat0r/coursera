#include <iostream>
#include <string>
#include <vector>



using namespace std;


// bool operator< (const std::__cxx11::basic_string<char> s, const char c){
// 	return s[0] < c;
// }


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix){
	RandomIt it;
    typename std::iterator_traits<RandomIt>::difference_type count, step;
    count = std::distance(range_begin, range_end);
 
    while (count > 0) {
        it = range_begin; 
        step = count / 2; 
        std::advance(it, step);
        string ss = *it;
        if (ss[0] < prefix) {
            range_begin = ++it; 
            count -= step + 1; 
        }
        else
            count = step;
    }
    RandomIt first = range_begin;
    count = std::distance(range_begin, range_end);
    while (count > 0) {
        it = range_begin; 
        step = count / 2; 
        std::advance(it, step);
        string ss = *it;
        if (!(prefix < ss[0])) {
            range_begin = ++it;
            count -= step + 1;
        } 
        else
            count = step;
    }
    

	pair<RandomIt, RandomIt> r = make_pair(first, range_begin);
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




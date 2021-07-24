#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



using namespace std;





// bool comp(const string sl, const string sr);



// bool test(const string s, const string prefix){
// 	// cerr << "\nTEST\n";
// 	// cerr << s << " ? " << prefix << endl;
//   // cerr << "test return " << comp(s, prefix) << endl;
//   return comp(s, prefix);
// 	size_t	 dl = min(s.size(), prefix.size());
// 	for(int i = 0; i < dl; i++){
// 		// cerr << " - " << s[i] << " " << prefix[i] << endl;
// 		if(s[i] > prefix[i]) {
// 			// cerr << "false" << endl << endl;
// 			return false;
// 		} else if(s[i] < prefix[i]){
// 			// cerr << "true" << endl << endl;
// 			return true;
// 		}
// 	}
// 	// cerr << "true" << endl << endl;
// 	return true;
// }

bool comp(const string sl, const string sr){
  int r;
  size_t   dl = min(sl.size(), sr.size());
  r = 0;
  for(int i = 0; i < dl; i++){
    if(sl[i]<sr[i]){
      r = -1;
      break;
    } else if (sl[i] > sr[i]){
      r = 1;
      break;
    }
  }
  if(r == -1){
    return true;
  } else {
    return false;
  }
}




template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix){
	
  RandomIt first, last;
  first = lower_bound(range_begin, range_end, prefix, comp);
  last  = upper_bound(range_begin, range_end, prefix, comp);

	pair<RandomIt, RandomIt> r = make_pair(first, last);	
	return r;
}



    
int main() {

  cerr << "TEST " << comp("aa", "aaaa") << endl;
  cerr << "TEST " << comp("aaaa", "aa") << endl;
  cerr << "TEST " << comp("a", "eeeee") << endl;
  cerr << "TEST " << comp("c", "EEEEE") << endl;
  cerr << "TEST " << comp("h", "H") << endl;
  cerr << "TEST " << comp("h", "H") << endl;

  const vector<string> sorted_strings = {"a", "b", "c", "d", "e", "h"};
  
  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "EEEEEEEEEE");
      // cerr << *mo_result.first << " " << *mo_result.second << endl;
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

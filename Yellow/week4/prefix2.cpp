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

bool comp(const string& sl, const string& sr){
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
  } else if(r == 1){
    return false;
  } else if (sl.size() < sr.size()){
    return false;
  } else {
    return false;
  }
}

bool comp2(const string& sl, const string& sr){
  int r = sl.compare(0, sr.size(), sr);
  // cerr << "INFO        " << sl << " " << sr << " " << r << endl;
  if (r<0){
    return true;
  } else {
    return false;
  }
}




template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix){
	
  RandomIt first, last;
  first = lower_bound(range_begin, range_end, prefix, comp2);
  last  = upper_bound(range_begin, range_end, prefix, comp);

	pair<RandomIt, RandomIt> r = make_pair(first, last);	


  // pair<RandomIt, RandomIt> r = equal_range(range_begin, range_end, prefix, comp2);
  // cerr << "INFO " << *r.first << " " << *r.second << endl;
	return r;
}

void test(const string& sl, const string& sr){
  cerr << "TEST " << sl << " < " << sr << "     " << comp(sl, sr) << "   " << comp2(sl, sr) << endl;
}

void AllTests(){
  test("asdf", "fdsa");
  test("aa", "aaaa");
  test("aaaa", "aa");
  test("a", "eeeee");
  test("tt", "b");
  test("c", "eeeee");
  test("h", "h");
  test("moscow", "mo");
  test("motovilikha", "mo");
  test("murmansk", "mo");
  cout << endl;
}

    
int main() {
  // AllTests();

  // const vector<string> sorted_strings = {"m", "m", "v"};
  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
  
  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  // cerr << (mo_result.first - begin(sorted_strings)) << " " <<
      // (mo_result.second - begin(sorted_strings)) << endl;
  
  
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


#include <iostream>
#include <string>
#include <vector>



using namespace std;









bool testL(const string& s, const string& prefix){
	cout << "testL\n";
	for(int i = 0; i < prefix.size(); i++){
			cout << " - " << prefix[i] << " " << s[i] << endl;
			if(s[i] < prefix[i]) {
				cout << "false" << endl;
				return false;
			}
		}
		cout << "true" << endl;
		return true;
}


bool testU(const string& s, const string& prefix){
	cout << "testU\n";
	bool e = false;
	for(int i = 0; i < prefix.size(); i++){
			cout << " - " << prefix[i] << " " << s[i] << endl;
			if(s[i] < prefix[i]) {
				cout << "false" << endl;
				return false;
			} else if(s[i] > prefix[i]){
				e = true;
			}
		}
		cout << "true" << endl;
		if (e){
			return true;
		}else{
			return false;
		}
}


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix){
	RandomIt it_begin, it_end;

	it_begin = lower_bound(range_begin, range_end, prefix, testL);


	it_end = lower_bound(range_begin, range_end, prefix, testU);

	// it_end = find_if(range_begin, range_end, [prefix](string s){
	// 	for(int i = 0; i <= prefix.size(); i++){
	// 		if(prefix[i] != s[i]) {return false;}
	// 	}
	// 	return true;
	// });


	pair<RandomIt, RandomIt> r = make_pair(it_begin, it_end);

	cout << "   Info " << *r.first << " " << *r.second << endl;
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

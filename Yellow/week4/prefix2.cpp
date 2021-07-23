#include <iostream>
#include <string>
#include <vector>



using namespace std;









bool test(const string s, const string prefix){
	cout << "\nTEST\n";
	cout << s << " ? " << prefix << endl;
	size_t	 dl = min(s.size(), prefix.size());
	for(int i = 0; i < dl; i++){
		cout << " - " << s[i] << " " << prefix[i] << endl;
		if(s[i] > prefix[i]) {
			cout << "false" << endl << endl;
			return false;
		} else if(s[i] < prefix[i]){
			cout << "true" << endl << endl;
			return true;
		}
	}
	cout << "true" << endl << endl;
	return true;
}


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix){
	RandomIt it, tmp;
	tmp = range_begin;
    typename std::iterator_traits<RandomIt>::difference_type count, step;
    count = std::distance(range_begin, range_end);
 	cout << "Count " << count << endl;
    while (count > 0) {
        it = range_begin; 
        step = count / 2; 
        std::advance(it, step);
        if (test(*it, prefix)) {
            range_begin = ++it; 
            count -= step + 1; 
            cout << "<" << count << endl;
        } 
        else 
        {
        	count = step;
        	cout << ">=" << count << endl;
        }
    }
    RandomIt first = range_begin;
    // range_begin = tmp;
    count = std::distance(range_begin, range_end);

    cout << "->2\n";
    cout << count << endl;
    while (count > 0) {
        it = range_begin; 
        step = count / 2; 
        std::advance(it, step);
        if (!(test(prefix, *it))) {
            range_begin = ++it;
            count -= step + 1;
        } 
        else
            count = step;
    }
    RandomIt last = range_begin;



    // RandomIt first, last;

    // first = upper_bound(range_begin, range_end, prefix, test);
    // cout << "2222222222222222222222222222222222222222222222222222222222\n";
    // last = lower_bound(range_begin, range_end, prefix, test);


    cout << "count " << distance(first, range_end) << " " << distance(last, range_end) << endl;
    cout << "	INFO " << *first << " " << *last << endl;
	pair<RandomIt, RandomIt> r = make_pair(first, last);	
	return r;
}



    

int main() {
  const vector<string> sorted_strings = {"aaa", "minsk", "moscow", "motovilikha", "murmansk"};
  

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

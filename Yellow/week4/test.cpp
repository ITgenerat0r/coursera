#include <iostream>
#include <string>
#include <vector>



using namespace std;





// bool comp(const string sl, const string sr);



// bool test(const string s, const string prefix){
//  // cerr << "\nTEST\n";
//  // cerr << s << " ? " << prefix << endl;
//   // cerr << "test return " << comp(s, prefix) << endl;
//   return comp(s, prefix);
//  size_t   dl = min(s.size(), prefix.size());
//  for(int i = 0; i < dl; i++){
//    // cerr << " - " << s[i] << " " << prefix[i] << endl;
//    if(s[i] > prefix[i]) {
//      // cerr << "false" << endl << endl;
//      return false;
//    } else if(s[i] < prefix[i]){
//      // cerr << "true" << endl << endl;
//      return true;
//    }
//  }
//  // cerr << "true" << endl << endl;
//  return true;
// }

// bool comp(const string sl, const string sr){
//   int r;
//   size_t   dl = min(sl.size(), sr.size());
//   r = sl.compare(0, dl, sr);
//   // cerr << "comp r = " << r << endl;
//   if (r == -1){
//     return true;
//   }
//   return false;
// }




template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix){
  RandomIt it, tmp;
  tmp = range_begin;
    typename std::iterator_traits<RandomIt>::difference_type count, step;
    count = std::distance(range_begin, range_end);
  cerr << "\n\n\nCount " << count << endl;
    while (count > 0) {
        it = range_begin; 
        step = count / 2; 
        std::advance(it, step);



        string sl = *it;
        string sr = prefix;
        cerr << "sl & sr = " << sl << " & " << sr << endl;
        bool k = false;
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
        cerr << " r = " << r << endl;
        if (r == -1){
          k = true;
        } else {
          k = false;
        }
        

        if (k) {
            range_begin = ++it; 
            count -= step + 1; 
            cerr << "<" << count << endl;
        } 
        else 
        {
          count = step;
          cerr << ">=" << count << endl;
        }
    }
    RandomIt first = range_begin;
    // range_begin = tmp;
    count = std::distance(range_begin, range_end);

    // cerr << "->222222222222222222222222222222222222222222222222222\n";
    // cerr << count << endl;
    while (count > 0) {
        it = range_begin; 
        step = count / 2; 
        std::advance(it, step);


        string sl = prefix;
        string sr = *it;
        // cerr << "sl & sr = " << sl << " & " << sr << endl;
        bool k = false;
        int r = 0;
        size_t dl = min(sl.size(), sr.size());
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
        // cerr << " r = " << r << endl;
        if (r == -1 ){
          k = true;
        } else {
          k = false;
        }








        if (!(k)) {
            range_begin = ++it;
            count -= step + 1;
        } 
        else
            count = step;
    }
    RandomIt last = range_begin;
    // if(first < last){
    //   last--;
    // }


    // RandomIt first, last;

    // first = upper_bound(range_begin, range_end, prefix, test);
    // cerr << "2222222222222222222222222222222222222222222222222222222222\n";
    // last = lower_bound(range_begin, range_end, prefix, test);


    // cerr << "count " << distance(first, range_end) << " " << distance(last, range_end) << endl;
    // cerr << "!!!!!!!!!!!!!!!!!!  INFO " << *first << " " << *last << " !!!!!!!!!!!!!!!!!!!!" << endl;
  pair<RandomIt, RandomIt> r = make_pair(first, last);  
  return r;
}



    
int main() {
  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
  
  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
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

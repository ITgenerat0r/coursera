

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#include <algorithm>
 
template<typename T> 
ostream& operator<< (ostream& out, std::vector<T> v){
  bool first = true;
  for(auto it = begin(v); it != end(v); it++ ){
    if(!first){
      out << " ";
    }else{
      first = false;
    }
    out << *it;
  }
  return out;
}

int main()
{
    std::string s = "";
    std::vector<int> v;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
      // s += to_string(i);
      v.push_back(i);
    }
    // cout << s << endl;
    std::sort(v.rbegin(), v.rend());
    do {
        std::cout << v << '\n';
    } while(std::prev_permutation(v.begin(), v.end()));
}



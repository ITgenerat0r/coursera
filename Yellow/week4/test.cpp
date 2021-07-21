

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
    vector<int> v = {0, 1, 2, 3, 4, 5};
    auto it = partition(begin(v), end(v), [](const int c){return c % 2 == 0;});
    cout << v << endl;
    cout << *it << endl;
}




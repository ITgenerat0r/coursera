#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



// Решение авторов
// vector<string> SplitIntoWords(const string& str) {
//   // Готовим вектор, в который будем сохранять слова
//   vector<string> result;

//   // Эти два итератора будут ограничивать текущую не разбитую часть строки
//   // str_begin будет двигаться вправо
//   auto str_begin = begin(str);
//   // str_end всегда будет указывать на конец строки (поэтому он константный)
//   const auto str_end = end(str);

//   // У цикла нет условия завершения, так что единственный способ закончить его —
//   // сделать break
//   while (true) {
    
//     // Находим первый пробел в текущем «хвосте» строки
//     auto it = find(str_begin, str_end, ' ');
    
//     // Полуинтервал [str_begin, it) — очередное слово
//     result.push_back(string(str_begin, it));
    
//     if (it == str_end) {
//       // Если пробелов больше нет, цикл пора завершить.
//       // Последнее слово уже добавлено
//       break;
//     } else {
//       // Иначе первый символ после пробела — начало очередного слова.
//       // Туда и подвинем str_begin
//       str_begin = it + 1;
//     }
    
//   }

//   return result;
// }







vector<string> SplitIntoWords(const string& s){
	auto it = begin(s);
	vector<string> r(0);
	while(it != end(s)) {
	    auto it2 = find_if(it, end(s), [](const auto& c){return c == ' ';});
	    // for(auto tmp = it; tmp != end(s); tmp++){
	    // 		cout << *tmp;
	    // 	}
	    if(it2 != end(s)){
	    	// cout << endl << "IN" << endl;
	    	string ss = "";
	    	for(auto tmp = it; tmp != it2; tmp++){
	    		ss += *tmp;
	    		// cout << ss;
	    	}
	    	r.push_back(ss);
	    	// cout << ss << endl << "OUT" << endl;
	    	it2++;
	    }else{
	    	if(it!= it2){
	    		// cout << endl << "IN" << endl;
		    	string ss = "";
		    	for(auto tmp = it; tmp != it2; tmp++){
		    		ss += *tmp;
		    		// cout << ss;
		    	}
		    	r.push_back(ss);
		    	// cout << ss << endl << "OUT" << endl;
	    	}
	    }
	    it = it2;
	}
	return r;
}




int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}

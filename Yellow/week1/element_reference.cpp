#include <iostream>
#include <map>

using namespace std;

//template<typename T, typename K, typename V, typename F> T& GetRefStrict(map<K, V> m, F k);



template<typename K, typename V, typename F> 
V& GetRefStrict(map<K, V>& m, F k){
	if(m.count(k)){
		return m[k];
	} else {
		throw runtime_error("No element");
	}
}




int main(){
	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue


	return 0;
}
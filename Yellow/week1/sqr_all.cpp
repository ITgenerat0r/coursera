#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

template<typename F, typename S> pair<F, S> operator* (pair<F, S> p1, pair<F, S> p2);
template<typename I> vector<I> operator* (std::vector<I> v1, std::vector<I> v2);
template<typename K, typename V> map<K, V> operator* (std::map<K, V> m1, std::map<K, V> m2);
template<typename T> T Sqr(const T& x);


template<typename F, typename S>
pair<F, S> operator* (pair<F, S> p1, pair<F, S> p2){
	return pair<F, S> {p1.first * p2.first, p1.second * p2.second};
};

template<typename I> vector<I>
vector<I> operator* (std::vector<I> v1, std::vector<I> v2){};

template<typename K, typename V>
map<K, V> operator* (std::map<K, V> m1, std::map<K, V> m2);
template <typename T>
T Sqr(const T& x){
	return x * x;
}


int main(){

	// Пример вызова функции
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}
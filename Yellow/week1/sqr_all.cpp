#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

template<typename F, typename S> pair<F, S> operator* (pair<F, S> p1, pair<F, S> p2);
template<typename T> T Sqr(const T& x);
template<typename T> vector<T> Sqr(const vector<T>& v);
template<typename Tfirst, typename Tsecond> map<Tfirst, Tsecond> Sqr(const map<Tfirst, Tsecond>& m);


template<typename F, typename S>
pair<F, S> operator* (pair<F, S> p1, pair<F, S> p2){
	return pair<F, S> {p1.first * p2.first, p1.second * p2.second};
};


template<typename T>
vector<T> Sqr(const vector<T>& v){
	vector<T> r;
	for(const T& i : v){
		r.push_back(Sqr(i));
	}
	return r;
}

template<typename Tfirst, typename Tsecond>
map<Tfirst, Tsecond> Sqr(const map<Tfirst, Tsecond>& m){
	map<Tfirst, Tsecond> r;
	for(const auto& i : m){
		r[i.first] = Sqr(i.second);
	}
	return r;
}

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
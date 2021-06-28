#include <iostream>
#include <vector>


using namespace std;

void PrintVector(vector<string>& a){
	cout << " Vector \n";
	for(auto x : a){
		cout << " " << x;
	}
	cout << endl;
}

void PrintMap(map<string, int>& a){
	cout << " map\n";
	for(const auto& [k, x] : a){
		// cout << " " << x;
		cout << k << " = " << x << endl;
	}
	cout << endl;
}

void PrintSet(set<string>& a){
	cout << " set\n";
	for(const auto& x : a){
		cout << " " << x;
	}
	cout << endl;
}

int main(){

	return 0;
}



	// map<int, string> m = {{1, "one"}, {2, "two"}};
	// for (const auto& [k, v] : m){
	// 	cout << k << " = " << v << endl;
	// }
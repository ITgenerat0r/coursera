#include <sstream>
#include <iostream>
using namespace std;

int main(){
	string t = "";
	stringstream ss("text.test+one");
	getline(ss, t , '.');
	cout << t;
	getline(ss, t , '.');
	cout << endl << t[0];
	return 0;
}
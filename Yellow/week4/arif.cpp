#include <iostream>
#include <string>


using namespace std;


int main(){
	int q;
	string x;
	string s, b;
	cin >> x >> q;
	b = "";
	while(q-->0){
		b+="(";
		cin >> s;
		x += ") " + s;
		cin >> s;
		x += " " + s;
		// cout << s << "   " << x << endl;
	}
	cout << b << x;
	return 0;
}
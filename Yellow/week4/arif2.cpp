#include <iostream>
#include <string>


using namespace std;


int main(){
	int q, k=1;
	string x;
	string s, b;
	cin >> x >> q;
	b = "";
	while(q-->0){
		cin >> s;
		if(s == "*" || s == "/"){
			k++;
		} else {
			k = 0;
		}
		if(k == 1){
			b+="(";
			x += ") " + s;
		}else{
			x += " " + s;
		}
		
		cin >> s;
		x += " " + s;
		// cout << s << "   " << x << endl;
	}
	cout << b << x;
	return 0;
}
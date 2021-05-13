#include <iostream>
#include <cmath>
// #include <string>
// #include <vector>
// #include <algorithm>

using namespace std;

int main(){
	float a, b, c, d, x1, x2;
	cin >> a >> b >> c;
	d = b * b - 4 * a * c;

	if (a != 0){
		x1 = (-b+sqrt(d))/(2 * a);
		x2 = (-b-sqrt(d))/(2 * a);
	} else {
		x1 = -c/b;
	}
	if (a * x1 * x1 + b * x1 + c == 0){
		cout << x1;
	}
	if ((a * x2 * x2 + b * x2 + c == 0) && (x1 != x2)){
		cout << " " << x2;
	}
	// cout << x1 << " " << x2;

	return 0;
}

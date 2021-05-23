#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;




int main(){
	auto start = steady_clock::now();

	auto finish = steady_clock::now();
	cout << "Interval = " << duration_cast<milliseconds>(finish-start).count() << " ms\n";
	return 0;
}
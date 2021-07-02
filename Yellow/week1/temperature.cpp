#include <iostream>
#include <vector>
#include <cstdint>


using namespace std;

int main(){
	int n;
	cin >> n;
	int64_t summ = 0;
	vector<int64_t> m(n);
	vector<int> days;
	for(int64_t& i : m){
		cin >> i;
		summ += i;
	}
	summ /= static_cast<int64_t>(m.size());
	int d = 0;
	for(const int64_t& i : m){
		if(i > summ){
			days.push_back(d);
		}
		d++;
	}
	cout << days.size() << endl;
	for (const int64_t& i : days)
	{
		cout << i << " ";
	}
}
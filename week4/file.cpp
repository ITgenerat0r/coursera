#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>


using namespace std;

int main(int argc, char const *argv[])
{
	ifstream input("input.txt");
	// ofstream output("output.txt");
	int n, m, data;
	std::vector<int> v;

	if(input){
		input >> n;
		input.ignore(1);
		input >> m;
		input.ignore(1);
	}
	int mm = m;
	while (n){
		// cout << "n"<<n<<endl;
		while(mm){
			// cout << "m" << m << endl;
			input >> data;
			input.ignore(1);
			cout << setw(10) << data;
			if (mm > 1){
				cout << ' ';
			}
			--mm;
		}
		if (n > 1){
			cout << endl;
		}
		mm = m;
		--n;
	}
	// cout << fixed;
	// cout << setprecision(3);
	// for(auto& i : v){
	// 	cout << setw(10) << i << endl;
	// }
	return 0;
}


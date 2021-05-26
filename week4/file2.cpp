#include <fstream>
#include <iostream>
#include <string>


using namespace std;

int main(int argc, char const *argv[])
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	string data;
	if(input.is_open()){
		while(getline(input, data)){
			// cout << data << endl;
			output << data << endl;
		}
	}
	return 0;
}


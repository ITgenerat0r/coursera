#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <locale>

using namespace std;


class ReversibleString
{
private:
	string name;
public:
	ReversibleString(){
		name = "";
	};
	ReversibleString(const string& ss){
		name = ss;
	}

	string ToString () const {
		return name;
	}

	void Reverse(){
		string temp = "";
		for(const char& ch : name){
			temp = ch + temp;
		}
		name = temp;
	}

	// ~ReversibleString();
	
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}
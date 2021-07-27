#include <iostream>

using namespace std;

class Animal {
public:
    // ваш код
	Animal(const string& s) : Name(s) {

	}
    const string Name;
};


class Dog : public Animal {
public:
    // ваш код
	Dog(const string& n) : Animal(n){}
    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};



// int main(){
// 	Animal a("Animal");
// 	Dog d("Dog");
// 	d.Bark();
// 	return 0;
// }
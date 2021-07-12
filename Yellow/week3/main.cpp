#include "phone_number.h"
#include <iostream>
#include <exception>



int main(){
	
	try{
		PhoneNumber pn("asdf");
	}catch(const exception& e){
		cerr << e.what() << endl;
	}

	return 0;
}
#include "phone_number.h"
#include <iostream>
#include <exception>



int main(){
	
	try{
		PhoneNumber pn("+asdf-123-888-123");
	}catch(const exception& e){
		cerr << e.what() << endl;
	}

	return 0;
}
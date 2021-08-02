
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>


int main(int argc, char *argv[]){


	// for (int count=0; count < argc; ++count)
 //        std::cout << count << " " << argv[count] << '\n';

    if(argc>2){
    	std::string command = argv[1];
    	std::stringstream ss(argv[2]);
    	std::string filename;
    	std::getline(ss, filename, '.');
	    
	    if(command == "-out"){
	    	std::string cmd = "g++ -std=c++20 -c " + filename + ".cpp";
	    	std::system("clear");
	    	std::cout << cmd << std::endl;
	    	const char *test = cmd.c_str();
	    	std::system(test);
	    } else if (command == "-build"){
	    	std::cout << "It's didn't developed yet!\n";
	    }
    }
	return 0;
}


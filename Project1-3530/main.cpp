#include <iostream>
#include <exception>
#include "SSLL.h"
#include "PSLL.h"
#include "SDAL.h"
#include "CDAL.h"


int main(){
	SDAL<int> al = SDAL<int>(7);
	try{
		for (int i = 0; i < 150; ++i){
			al.push_front(i);
		}
		std::cout << std::endl << std::endl << std::endl;
		for (int i = 0; i < 50; ++i){
			std::cout << al.pop_back() << std::endl;
		}

	}
	catch (std::exception e){
		std::cerr << "\nException: " << e.what() << std::endl;
	}
	al.print(std::cout);

	return 0;

}
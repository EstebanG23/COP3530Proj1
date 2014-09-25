#include <iostream>
#include <exception>
#include "SSLL.h"
#include "PSLL.h"
#include "SDAL.h"
#include "CDAL.h"


int main(){
	

	SSLL<int> bl = SSLL<int>();

	bl.insert(0, 0);
	bl.insert(1, 1);
	bl.insert(2, 2);
	bl.insert(3, 3);

	bl.print(std::cout);

	std::cout << "..." << bl.remove(2);
	std::cout << "..." << bl.remove(2);
	std::cout << "..." << bl.remove(0);
	std::cout << "..." << bl.remove(0);

	/*
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
	*/
	return 0;

}
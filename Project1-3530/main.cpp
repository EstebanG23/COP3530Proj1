#include <iostream>
#include <exception>
#include "SSLL.h"
#include "PSLL.h"
#include "SDAL.h"
#include "CDAL.h"


int main(){
	SDAL<int> al = SDAL<int>(7);
	SDAL<int> bl = SDAL<int>(2);
	al.push_back(8);
	al.push_back(9);
	al.push_back(10);
	al.push_back(11);
	al.push_back(12);
	al.push_back(13);
	std::cout << al.remove(5);
	try{
	std::cout << al.pop_back();
	}
	catch (std::exception e){
		std::cerr << "\nException: " << e.what() << std::endl;
	}
	al.replace(50, 0);
	al.print(std::cout);

	bl = al;
	bl.print(std::cout);

	al.push_back(100);
	al.print(std::cout);
	bl.print(std::cout);


	return 0;

}
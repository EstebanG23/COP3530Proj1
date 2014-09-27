#include <iostream>
#include <exception>
#include "SSLL.h"
#include "PSLL.h"
#include "SDAL.h"
#include "CDAL.h"

using namespace cop3530;

int main(){

	/*
	cop3530::SSLL<char> list;


	list.push_front('y');
	list.push_back('X');
	

	const cop3530::SSLL<char> const_list = list;

	cop3530::SSLL<char>::iterator iter = list.begin();
	std::cout << *iter << std::endl;        // prints an X
	++iter;
	std::cout << *iter << std::endl;        // prints a Y

	

	for (cop3530::SSLL<char>::const_iterator const_iter = const_list.begin(); const_iter != const_list.end(); ++const_iter){
		std::cout << *const_iter << std::endl;
	}

	*/

	cop3530::PSLL<char> list;

	list.push_back('y');
	list.push_back('x');
	
	for (cop3530::PSLL<char>::iterator iter = list.begin(); iter != list.end(); ++iter){
		std::cout << *iter << std::endl;
	}


	return 0;

}
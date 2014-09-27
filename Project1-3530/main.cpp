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
	/*
	cop3530::PSLL<char> list1;

	list1.push_back('*');
	list1.push_back('(');
	
	for (cop3530::PSLL<char>::iterator iter = list1.begin(); iter != list1.end(); ++iter){
		std::cout << *iter << std::endl;
	}

	cop3530::CDAL<int> list2;

	for (int i = 0; i < 201; ++i){
		//std::cout << (char)i << std::endl;
		list2.push_back(i);
	}

	list2.push_back(10000);
	cop3530::CDAL<int>::iterator end = list2.end();
	for (cop3530::CDAL<int>::iterator iter = list2.begin(); iter != end; ++iter){
		//std::cout << *iter << std::endl;
	}
	
	std::cout << std::endl << std::endl;

	const cop3530::CDAL<int> const_list = list2;
	
	for (int i = 0; i < 202; ++i){
		std::cout << const_list.item_at(i) << std::endl;
	}
	
	
	cop3530::CDAL<int>::const_iterator const_end = const_list.end();
	for (cop3530::CDAL<int>::const_iterator const_iter = const_list.begin(); const_iter != const_end; ++const_iter){
		std::cout << *const_iter << std::endl;
	}
	
	*/

	cop3530::SDAL<int> SD;


	for (int i = 0; i < 10000; ++i){
		SD.push_back(i);
	}


	for (int i = 0; i < 10000; ++i){
		std::cout<< SD.pop_front() << " ";
	}

	return 0;

}
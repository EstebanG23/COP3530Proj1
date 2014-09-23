#include <iostream>
#include "SSLL.h"
#include "PSLL.h"
#include "SDAL.h"
#include "CDAL.h"

/*--------------------------------- Daves Methods  ---------------------------------------*/
bool same_char(const char& a, const char& b) { // argument for contains()
	return (a == b);
}

void in_list(const SSLL<char>& list, char c, std::ostream& out) {
	out << c << " is " << (list.contains(c, same_char) ? "" : "not ")
		<< "in the list ";
	list.print(out);
	out << std::endl;
}

/*------------------------------ End Of Daves Methods  ----------------------------------*/


int main(){

	CDAL<int> al;

	for (int i = 0; i < 75; ++i){
		al.push_back(i);
	}
	/*
	for (int i = 0; i < 75; ++i){
		std::cout << " " << al.pop_back() << " " << std::endl;

	}
		*/

	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front(); 
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();
	std::cout << al.pop_front();



	//for (int i = 0; i < 50; i++){
	//	std::cout << "tail->data[" << i << "] = tail->data[" << i + 1 << "]" << std::endl;
	//}

	return 0;

}
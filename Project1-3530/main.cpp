#include <iostream>
#include "SSLL.h"
#include "PSLL.h"
#include "SDAL.h"

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

	SDAL<int> al = SDAL<int>(5);

	//al.print(std::cout);

	for (int i = 0; i < 12; ++i){
		std::cout << i << std::endl;
			al.push_back(i);
	}
	al.push_front(100);
	al.print(std::cout);
	std::cout << std::endl;
	for (int i = 0; i < 13; ++i){
		std::cout <<"i = " << i << " " << al.pop_back() << std::endl;
	}

	return 0;
}
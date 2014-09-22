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


	al.push_back(1);
	al.push_back(2);
	al.push_back(3);
	al.push_front(0);
	al.push_back(4);




	al.print(std::cout);


	std::cout << al.remove(0);

	std::cout << std::endl << std::endl;

	al.print(std::cout);

	al.push_back(4);
	std::cout << std::endl << std::endl;

	al.print(std::cout);

	return 0;
}
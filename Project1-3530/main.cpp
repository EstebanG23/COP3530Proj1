#include <iostream>
#include <exception>
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
	SDAL<int> al = SDAL<int>(7);

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

	return 0;

}
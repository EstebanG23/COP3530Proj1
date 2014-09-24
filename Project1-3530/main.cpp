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
	SDAL<int> al = SDAL<int>(25);

	al.insert(0, 0);
	al.insert(2, 0);
	al.insert(3, 0);
	al.insert(4, 0);
	al.insert(5, 4);
	al.push_back(12);
	std::cout << al.item_at(5);


	return 0;

}
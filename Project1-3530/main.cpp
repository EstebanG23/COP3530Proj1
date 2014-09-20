#include <iostream>
#include "SSLL.h"
#include "PSLL.h"

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
	/*
	//Creating a list
	SSLL<char> a;
	//Curent Size
	std::cout << "Size: " << a.size();

	//Dave's Test Cases//
	std::cout << std::endl << std::endl;
	SSLL<char> l;

	l.print(std::cout);
	std::cout << std::endl;
	l.insert('X', 0);
	l.print(std::cout);
	std::cout << std::endl;
	l.insert('Y', 0);
	l.print(std::cout); std::cout << std::endl;

	in_list(l, 'x', std::cout);
	in_list(l, 'X', std::cout);

	std::cout << std::endl << std::endl;

	a = l;
	a.size();
	a.print(std::cout);
	*/


	PSLL<int> b;

	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);
	b.push_front(0);

	std::cout << b.pop_back() << std::endl;
	std::cout << b.pop_back() << std::endl;
	std::cout << b.pop_back() << std::endl;
	std::cout << b.pop_back() << std::endl;
	b.push_back(31);
	b.push_back(21);
	b.push_back(11);
	std::cout << b.pop_back() << std::endl;
	std::cout << b.pop_back() << std::endl;

	return 0;
}



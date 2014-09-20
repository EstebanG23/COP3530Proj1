#include <iostream>
#include "SSLL.H"

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

	SSLL<int> a;

	a.push_back(4012);
	a.push_back(1337);
	a.push_back(231);
	a.push_back(166);
	a.push_front(0);
	a.print(std::cout);
	
	//std::cout << "Pop Back Data: " << a.pop_back();
	std::cout << std::endl << "Size: " << a.size() << std::endl;
	//std::cout << a.remove(4);
	std::cout << a.item_at(4);
	std::cout << std::endl << "Size: " << a.size() << std::endl;
	std::cout << "True/False: " << a.is_empty() << std::endl;
	a.clear();
	
	a.push_back(1111);
	std::cout << a.pop_back();
	std::cout << std::endl << "Size: " << a.size() << std::endl;

	a.print(std::cout);
	
	a.push_back(4012);
	a.push_back(1337);
	a.push_back(231);
	a.push_back(166);
	a.push_front(0);
	a.insert(3, 5);
	
	a.print(std::cout);
	std::cout << a.replace(76, 0);
	a.print(std::cout);


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



	return 0;
}



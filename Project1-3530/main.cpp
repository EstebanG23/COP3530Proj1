#include "ssll.h"
#include <ostream>
int main(){

	SSLL<int> *a = new SSLL<int>();

	a->push_back(4012);
	a->push_back(1337);
	a->push_back(231);
	a->push_back(166);
	a->push_front(0);
	a->print(std::cout);
	
	//std::cout << "Pop Back Data: " << a->pop_back();
	std::cout << std::endl << "Size: " << a->size() << std::endl;
	//std::cout << a->remove(4);
	std::cout << a->item_at(4);
	std::cout << std::endl << "Size: " << a->size() << std::endl;
	std::cout << a->is_empty() << std::endl;
	a->clear();
	
	a->push_back(1111);
	std::cout << a->pop_back();
	std::cout << std::endl << "Size: " << a->size() << std::endl;

	a->print(std::cout);
	return 0;
}
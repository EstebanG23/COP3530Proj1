#include <iostream>
#include <exception>
#include "SSLL.h"
#include "PSLL.h"
#include "SDAL.h"
#include "CDAL.h"


int main(){

	CDAL<int> CD = CDAL<int>();
	CD.insert(13, 0);
	CD.insert(12, 0);
	CD.insert(11, 0);
	CD.insert(10, 0);
	CD.insert(9, 0);
	CD.insert(8, 0);
	CD.insert(7, 0);
	CD.insert(6, 0);
	CD.insert(5, 0);
	CD.insert(4, 0);
	CD.insert(3, 0);
	CD.insert(2, 0);
	CD.insert(1, 0);
	CD.insert(0, 0);
	CD.insert(14, 14); 


	CD.push_back(15);
	CD.push_back(16);
	CD.push_back(17);
	CD.push_back(18);
	CD.push_back(19);
	CD.push_back(20);
	CD.push_back(21);
	CD.insert(100, 21);
	CD.push_back(23);
	CD.push_back(24);
	CD.push_back(25);
	CD.insert(21, 21);
	CD.push_back(26);
	CD.push_back(27);
	CD.push_back(28);
	CD.push_back(29);
	CD.insert(30, 31);
	CD.push_back(31);
	CD.print(std::cout);

	return 0;

}
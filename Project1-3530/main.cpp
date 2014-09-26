#include <iostream>
#include <exception>
#include "SSLL.h"
#include "PSLL.h"
#include "SDAL.h"
#include "CDAL.h"


int main(){

	CDAL<int> CD = CDAL<int>();


	for (int i = 0; i < 150; ++i){
		CD.push_back(i);
	}



	CD.print(std::cout);
	return 0;

}
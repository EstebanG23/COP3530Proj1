#include <iostream>
#include <exception>
#include "SSLL.h"
#include "PSLL.h"
#include "SDAL.h"
#include "CDAL.h"

using namespace cop3530;

int main(){

	cop3530::SSLL<int> SS;
	cop3530::PSLL<int> PS;
	cop3530::SDAL<int> SD;
	cop3530::CDAL<int> CD;
	SS.push_back(10000);

	return 0;

}
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch\catch.hpp"

#include <iostream>
#include <exception>
#include "ssll.h"
#include "PSLL.h"
#include "SDAL.h"
#include "CDAL.h"


using namespace cop3530;

TEST_CASE("SSLL IS CREATED", "[SSLL]"){
	cop3530::SSLL<char> SS;

	SS.push_back('e');
	SS.push_back('g');
	SS.push_back('l');
	SS.push_back('e');
	SS.push_back('y');
	SS.push_front('k');
	REQUIRE(SS.pop_front() == 'k'); 
	REQUIRE(SS.pop_front() == 'e');
	REQUIRE(SS.remove(0) == 'g');
	REQUIRE(SS.pop_front() == 'l');
	REQUIRE(SS.pop_front() == 'e');
	REQUIRE(SS.pop_front() == 'y');
}

TEST_CASE("SSLL <int?> is created with I loop", "[SSLLi]"){
	cop3530::SSLL<int> SSi;

	for (int i = 0; i < 100; ++i){
		SSi.push_back(i);
	}
	for (int i = 0; i < 100; ++i){
		REQUIRE(SSi.pop_front() == i);
	}
}


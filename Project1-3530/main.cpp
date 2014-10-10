#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch\catch.hpp"

#include <iostream>
#include <exception>
#include "ssll.h"
#include "PSLL.h"
#include "SDAL.h"
#include "CDAL.h"


using namespace cop3530;

TEST_CASE("SSLL IS CREATED", "[SSLL<char>]"){
	//-------------------------------------------------------------------------
	//  SSLL<char>
	//	PUSHING: push_back, push_front, and insert
	//
	//	POPPING: pop_front, pop_back, and remove
	//	IN: egleyk
	//	OUT: kegley
	//-------------------------------------------------------------------------
	cop3530::SSLL<char> SS;

	SS.push_back('e');
	SS.push_back('g');
	SS.insert('l', 2);
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

TEST_CASE("SSLL<int> is created, [0,1000000)", "[SSLL<int>]"){
	//-------------------------------------------------------------------------
	//  SSLL<int>
	//	PUSH_BACK: [0, 100000)
	//
	//	POP_FRONT: [0, 100000)
	//-------------------------------------------------------------------------
	cop3530::SSLL<int> SSi;

	for (int i = 0; i < 100; ++i){
		SSi.push_back(i);
	}
	for (int i = 0; i < 100; ++i){
		REQUIRE(SSi.pop_front() == i);
	}
}

TEST_CASE("SSLL<char>: Using all functions", "[SSLL<char>: All Functions]"){
	//-------------------------------------------------------------------------
	//  SSLL<char>
	//	
	//-------------------------------------------------------------------------

	cop3530::SSLL<char> SSLLFuncts;

	for (int i = 97; i < 96+27; ++i){
		SSLLFuncts.push_back((char)i);
	}
	SSLLFuncts.replace('E', 4);
	REQUIRE(SSLLFuncts.item_at(3) == 'd');
	REQUIRE(SSLLFuncts.item_at(4) == 'E');

	/*
		replace(element, position)
		insert(element, position)
		push_back(element)
		push_front(element)
		remove(position)
		pop_back()
		pop_front()
		item_at(position)
		is_empty()
		size()
		clear()
		contains(element, equals_function);
		print(ostream);
	*/


}
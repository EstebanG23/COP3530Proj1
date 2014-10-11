#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch\catch.hpp"

#include <iostream>
#include <exception>
#include "ssll.h"
#include "PSLL.h"
#include "SDAL.h"
#include "CDAL.h"

using namespace cop3530;

bool same_char(const char& a, const char& b) { // argument for contains()
	return (a == b);
}

bool in_list(const cop3530::SSLL<char>& list, char c) {
	if(list.contains(c, same_char)){
		return true;
	}
	return false;
}

bool in_list(const cop3530::PSLL<char>& list, char c) {
	if (list.contains(c, same_char)){
		return true;
	}
	return false;
}

bool in_list(const cop3530::SDAL<char>& list, char c) {
	if (list.contains(c, same_char)){
		return true;
	}
	return false;
}


TEST_CASE("SSLL", "[SSLL]"){

	SECTION("USING OTHER REQUIRED FUNCTIONS"){
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
		
		//-------------------------------------------------------------------------
		//  SSLL<char>
		//	Testing all Functions 
		//-------------------------------------------------------------------------
		cop3530::SSLL<char> SSLLFuncts;

		for (int i = 97; i < 96 + 27; ++i){
			SSLLFuncts.push_back((char)i);
		}
		//SSLLFuncts.print(std::cout);
		//std::cout << std::endl;
		REQUIRE(in_list(SSLLFuncts, 'x'));
		REQUIRE(SSLLFuncts.size() == 26);
		REQUIRE(SSLLFuncts.item_at(4) == 'e');
		SSLLFuncts.replace('E', 4);
		REQUIRE(SSLLFuncts.item_at(3) == 'd');
		REQUIRE(SSLLFuncts.item_at(4) == 'E');
		SSLLFuncts.insert('e', 4);
		REQUIRE(SSLLFuncts.item_at(3) == 'd');
		REQUIRE(SSLLFuncts.item_at(4) == 'e');
		REQUIRE(SSLLFuncts.item_at(5) == 'E');
		REQUIRE(SSLLFuncts.remove(4) == 'e');
		REQUIRE(SSLLFuncts.item_at(4) == 'E');
		REQUIRE(SSLLFuncts.is_empty() == false);
		SSLLFuncts.clear();
		REQUIRE(SSLLFuncts.is_empty() == true);
		REQUIRE(SSLLFuncts.size() == 0);
		REQUIRE(!in_list(SSLLFuncts, 'x'));


	}
}

TEST_CASE("PSLL", "[PSLL]"){

	SECTION("USING OTHER REQUIRED FUNCTIONS"){
		//-------------------------------------------------------------------------
		//  PSLL<char>
		//	PUSHING: push_back, push_front, and insert
		//
		//	POPPING: pop_front, pop_back, and remove
		//	IN: egleyk
		//	OUT: kegley
		//-------------------------------------------------------------------------
		cop3530::PSLL<char> PSL;

		PSL.push_back('e');
		PSL.push_back('g');
		PSL.insert('l', 2);
		PSL.push_back('e');
		PSL.push_back('y');
		PSL.push_front('k');
		REQUIRE(PSL.pop_front() == 'k');
		REQUIRE(PSL.pop_front() == 'e');
		REQUIRE(PSL.remove(0) == 'g');
		REQUIRE(PSL.pop_front() == 'l');
		REQUIRE(PSL.pop_front() == 'e');
		REQUIRE(PSL.pop_front() == 'y');

		//-------------------------------------------------------------------------
		//  PSLL<int>
		//	PUSH_BACK: [0, 100000)
		//
		//	POP_FRONT: [0, 100000)
		//-------------------------------------------------------------------------
		cop3530::PSLL<int> PSLi;

		for (int i = 0; i < 100; ++i){
			PSLi.push_back(i);
		}
		for (int i = 0; i < 100; ++i){
			REQUIRE(PSLi.pop_front() == i);
		}

		//-------------------------------------------------------------------------
		//  PSLL<char>
		//	Testing all Functions 
		//-------------------------------------------------------------------------
		cop3530::PSLL<char> PSLLFuncts;

		for (int i = 97; i < 96 + 27; ++i){
			PSLLFuncts.push_back((char)i);
		}
		REQUIRE(in_list(PSLLFuncts, 'x'));
		REQUIRE(PSLLFuncts.size() == 26);
		REQUIRE(PSLLFuncts.item_at(4) == 'e');
		PSLLFuncts.replace('E', 4);
		REQUIRE(PSLLFuncts.item_at(3) == 'd');
		REQUIRE(PSLLFuncts.item_at(4) == 'E');
		PSLLFuncts.insert('e', 4);
		REQUIRE(PSLLFuncts.item_at(3) == 'd');
		REQUIRE(PSLLFuncts.item_at(4) == 'e');
		REQUIRE(PSLLFuncts.item_at(5) == 'E');
		REQUIRE(PSLLFuncts.remove(4) == 'e');
		REQUIRE(PSLLFuncts.item_at(4) == 'E');
		REQUIRE(PSLLFuncts.is_empty() == false);
		PSLLFuncts.clear();
		REQUIRE(PSLLFuncts.is_empty() == true);
		REQUIRE(PSLLFuncts.size() == 0);
		REQUIRE(!in_list(PSLLFuncts, 'x'));


	}
}


TEST_CASE("SDAL", "[SDAL]"){

	SECTION("USING OTHER REQUIRED FUNCTIONS"){
		//-------------------------------------------------------------------------
		//  SDAL<char>
		//	PUSHING: push_back, push_front, and insert
		//
		//	POPPING: pop_front, pop_back, and remove
		//	IN: egleyk
		//	OUT: kegley
		//-------------------------------------------------------------------------
		cop3530::SDAL<char> SDAL;

		SDAL.push_back('e');
		SDAL.push_back('g');
		SDAL.insert('l', 2);
		SDAL.push_back('e');
		SDAL.push_back('y');
		SDAL.push_front('k');
		REQUIRE(SDAL.pop_front() == 'k');
		REQUIRE(SDAL.pop_front() == 'e');
		REQUIRE(SDAL.remove(0) == 'g');
		REQUIRE(SDAL.pop_front() == 'l');
		REQUIRE(SDAL.pop_front() == 'e');
		REQUIRE(SDAL.pop_front() == 'y');

		//-------------------------------------------------------------------------
		//  SDAL<int>
		//	PUSH_BACK: [0, 100000)
		//
		//	POP_FRONT: [0, 100000)
		//-------------------------------------------------------------------------
		cop3530::SDAL<int> SDALi;

		for (int i = 0; i < 1001; ++i){
			SDALi.push_back(i);
		}
		for (int i = 0; i < 1001; ++i){
			REQUIRE(SDALi.pop_front() == i);
		}

		//-------------------------------------------------------------------------
		//  SDAL<char>
		//	Testing all Functions 
		//-------------------------------------------------------------------------
		cop3530::SDAL<char> SDALFuncts;

		for (int i = 97; i < 96 + 27; ++i){
			SDALFuncts.push_back((char)i);
		}
		REQUIRE(in_list(SDALFuncts, 'x'));
		REQUIRE(SDALFuncts.size() == 26);
		REQUIRE(SDALFuncts.item_at(4) == 'e');
		SDALFuncts.replace('E', 4);
		REQUIRE(SDALFuncts.item_at(3) == 'd');
		REQUIRE(SDALFuncts.item_at(4) == 'E');
		SDALFuncts.insert('e', 4);
		REQUIRE(SDALFuncts.item_at(3) == 'd');
		REQUIRE(SDALFuncts.item_at(4) == 'e');
		REQUIRE(SDALFuncts.item_at(5) == 'E');
		REQUIRE(SDALFuncts.remove(4) == 'e');
		REQUIRE(SDALFuncts.item_at(4) == 'E');
		REQUIRE(SDALFuncts.is_empty() == false);
		SDALFuncts.clear();
		REQUIRE(SDALFuncts.is_empty() == true);
		REQUIRE(SDALFuncts.size() == 0);
		REQUIRE(!in_list(SDALFuncts, 'x'));


	}
}
#ifndef _SDAL_H_
#define _SDAL_H_

/*
Skeleton created by Dave Small

Methods and Logic Written by Joshua Kegley
*/

#include <iostream>



template <typename T>
class SDAL {
private:
	struct Node {
		T data;
		Node *next;

	}; // end struct Node
	Node * head;
	Node * tail;
	Node * poolHead;
	Node * poolTail;
	int amount;
	int poolAmount;



public:


	SDAL() {

	}

	SDAL(const SDAL& src){}

	~SDAL() {

	}


	SDAL& operator=(const SDAL& src) {
		if (&src == this) // check for self-assignment
			return *this;     // do nothing

		// safely dispose of this SDAL's contents
		// populate this SDAL with copies of the other SDAL's contents
		clear();
		for (int i = 0; i < src.size(); i++){
			push_back(src.item_at(i));
		}
	}


	//Replaces orginal element with specified element, returns orginal
	T replace(const T& element, int position) {


	}


	//inserts elemenet, and shifts all elements after to the "left"
	void insert(const T& element, int position) {
	

	}
	//#done


	//pushes element to the front of the list
	void push_front(const T& element) {

	}
	//#done

	//pushes elemets to the back
	void push_back(const T& element) {

	}
	//#done

	//pops the first element, assigns pointer to temp, replaces head with the next value
	T pop_front() {

	}
	//#done

	//pops elements off the back, moves tail to the previous element
	T pop_back() {

	}
	//#done


	//Removes an element from the list, from specified location
	T remove(int position) {

	}
	//#done

	//Looks at item at position
	T item_at(int position) const {

	}
	//#done

	//Checks for emptiness
	bool is_empty() const {
		return (amount == 0 ? true : false);
	}
	//#done

	//checks for size
	int size() const { return amount; }
	//#done

	//clears list
	void clear() {

	}
	//done

	bool contains(const T& element,
		bool equals(const T& a, const T& b)) const {


	}

	std::ostream& print(std::ostream& out) const {


	}

};

#endif
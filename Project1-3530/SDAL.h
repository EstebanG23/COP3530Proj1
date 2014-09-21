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
	struct Node{
		T data;
		int next;
	};
	Node ** list;
	int head;
	int tail;

	//length = amount of items in the array
	int length;
	//amount = amount of avail space
	int amount;

	
public:


	SDAL() {
		SDAL(50);
	}

	SDAL(int size) {
		list = new Node*[size];
		head = 0; tail = 0;
		amount = 0; length = size;
		for (amount; amount < length; ++amount){
			list[amount] = new Node;
			list[amount]->next = -1;
		}
		amount = 0;
	}

	SDAL(const SDAL& src){}

	~SDAL() {}


	SDAL& operator=(const SDAL& src) {
		if (&src == this){ // check for self-assignment
			return *this;     // do nothing
		}
		// safely dispose of this SDAL's contents
		// populate this SDAL with copies of the other SDAL's contents
	}


	//Replaces orginal element with specified element, returns orginal
	T replace(const T& element, int position) {}


	//inserts elemenet, and shifts all elements after to the "left"
	void insert(const T& element, int position) {}



	//pushes element to the front of the list
	void push_front(const T& element) {
		if (is_full()){
			//do something to make it not full
		}
		if (amount == 0){
			list[head]->data = element;
		}
		else{
			int temp = head;
			head = is_free();
			list[head]->next = temp;
			list[head]->data = element;

		}
		++amount;
	}


	//pushes elemets to the back
	void push_back(const T& element) {
		if (is_full()){
			//do something to make it not full
		}
		if (amount == 0){
			list[head]->data = element;

		}
		else{
			list[tail]->next = is_free();
			tail = list[tail]->next;
			list[tail]->data = element;
		}
		++amount;
	}


	//pops the first element, assigns pointer to temp, replaces head with the next value
	T pop_front() {

	}

	//pops elements off the back, moves tail to the previous element
	T pop_back() {

	}



	//Removes an element from the list, from specified location
	T remove(int position) {

	}


	//Looks at item at position
	T item_at(int position) const { return list[position]->data;}
	//#done

	//Checks for emptiness
	bool is_empty() const { return (amount == 0 ? true : false);}


	//checks for size
	int size() const { return amount; }

	bool is_full(){
		return (amount == length ? true : false);
	}
	//clears list
	void clear() {}


	bool contains(const T& element,
		bool equals(const T& a, const T& b)) const {}

	std::ostream& print(std::ostream& out) const {

		for (int i = 0; i < amount; ++i){
			out << list[i]->data <<  " " << list[i]->next << std::endl;
		}
		return out;
	}


	private:
		void grow_list(){

		}

		void shrink_list(){

		}

		int is_free(){
			for (int i = 0; i < length; ++i){
				if (list[i]->next == -1 && i != tail){
					return i;
				}
			}
		}




};

#endif
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
			list[head]->next = -2;
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
			list[head]->next = -2;

		}
		else{
			list[tail]->next = is_free();
			tail = list[tail]->next;
			list[tail]->data = element;
			list[tail]->next = -2;
		}
		++amount;
	}


	//pops the first element, assigns pointer to temp, replaces head with the next value
	T pop_front() {
		T data = list[head]->data;
		int temp = head;
		head = list[temp]->next;
		list[temp]->next = -1;
		--amount;
		if (amount == 0){
			head = 0; 
			tail = 0;
		}
		return data;
	}

	//pops elements off the back, moves tail to the previous element
	T pop_back() {
		int temp = head;
		while (list[temp]->next != tail){
			temp = list[temp]->next;
		}
		T data = list[tail]->data;
		list[tail]->next = -1;
		tail = temp;
		list[temp]->next = -2;
		return data;
	}



	//Removes an element from the list, from specified location
	T remove(int position) {
		int temp = head;
		T data;
		if (position == 0){
			data = list[head]->data;
			head = list[temp]->next;
			list[temp]->next = -1;
		}
		else{
			for (int i = 1; i < position; ++i){
				temp = list[temp]->next;
			}
			data = list[list[temp]->next]->data;

		}
		--amount;
		return data;
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
		std::cout << "head: " << head << std::endl;
		std::cout << "tail: " << tail << std::endl;
		int temp = head;
		out << "[";
		while (temp != -2){
			out << list[temp]->data << "..." << list[temp]->next << "..." <<  temp << ", ";
			temp = list[temp]->next;
		}
		out << "]";
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
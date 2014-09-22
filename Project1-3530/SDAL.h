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
	T replace(const T& element, int position) {
		T data;
		if (position == 0){
			data = list[head]->data;
			list[head]->data = element;
		}
		else{
			int temp = head;
			for (int i = 0; i < position; ++i){
				temp = list[temp]->next;
			}
			data = list[temp]->data;
			list[temp]->data = element;

		}
	
		return data;
	
	}//done

	//inserts elemenet, and shifts all elements after to the "left"
	void insert(const T& element, int position) {
		if (position == 0){
			push_front(element);
		}

		else{
			int temp = is_free();
			list[temp]->data = element;
			int before = head;
			for (int i = 1; i < position; ++i){
				before = list[before]->next;
			}
			int after = list[before]->next;
			list[before]->next = temp;
			list[temp]->next = after;

		}
		++amount;
	}//done

	//pushes element to the front of the list
	void push_front(const T& element) {
		if (is_full()){
			grow_list();
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
	}//done

	//pushes elemets to the back
	void push_back(const T& element) {
		if (is_full()){
			grow_list();
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
	}//done

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
		shrink_list();
		return data;
	}//done

	//pops elements off the back, moves tail to the previous element
	T pop_back() {
		std::cout << "tail = " << tail;
		int temp = head;
		while (amount != 1 && list[temp]->next != tail){
			temp = list[temp]->next;
		}
		T data = list[tail]->data;
		list[tail]->next = -1;
		tail = temp;
		
		list[temp]->next = -2;
		--amount;
		shrink_list();
		return data;
	}//done

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
		shrink_list();
		return data;
	}//done

	//Looks at item at position
	T item_at(int position) const { 
		int temp = head;
		T data;
		if (position == 0){
			data = list[head]->data;
		}
		else{
			for (int i = 0; i < position; ++i){
				temp = list[temp]->next;
			}
			data = list[temp]->data;

		}
		
		return data;
	}//#done

	//Checks for emptiness
	bool is_empty() const { return (amount == 0 ? true : false);}
	//done

	//checks for size
	int size() const { return amount; }
	//done

	//clears list
	void clear() {
		amount = 0;
		for (amount; amount < length; ++amount){
			list[amount]->next = -1;
		}
		amount = 0;head = 0; tail = 0;
	}//done

	bool contains(const T& element,
		bool equals(const T& a, const T& b)) const {}

	std::ostream& print(std::ostream& out) const {

		int temp = head;
		if (amount != 0){
			std::cout << "head: " << head << std::endl;
			std::cout << "tail: " << tail << std::endl;
			out << "[";
			while (temp != -2 && amount != 0){
				out << list[temp]->data << "..." << list[temp]->next << "..." <<  temp << ", ";
				temp = list[temp]->next;
			}
			out << "]";
		}
		else{
			out << "<is empty>";
		}
		return out;
	}//done

	private:
		void grow_list(){
			length = (int)(length * 1.5);
			Node ** temp = new Node*[length];
			for (int i = 0; i < length; ++i){
				if (i < amount){
					temp[i] = list[i];
				}
				else{
					temp[i] = new Node;
					temp[i]->next = -1;
				}

			}
			list = temp;

		}

		void shrink_list(){
			//LOGIC FOR LATER
			/*	Need to shrink list if list is >= 100 and amount < 50
				Need to reorder all of the items including what they point to. 
			*/
			if (length >= 10 && amount < length / 2){
				std::cout << "Shrinking List: " << std::endl;
				int tempLength = length;
				int position = head;
				length /= 2;
				Node ** temp = new Node*[length];
				for (int i = 0; i < amount; ++i){
					temp[i] = new Node;
					temp[i]->data = list[position]->data;
					temp[i]->next = i + 1;
					position = list[position]->next;
				}
				for (int i = 0; i < tempLength; ++i){
					delete list[i];
				}
				delete[] list;
				head = 0;
				tail = amount - 1;
				list = temp;


			}
		}

		int is_free(){
			for (int i = 0; i < length; ++i){
				if (list[i]->next == -1 && i != tail){
					return i;
				}
			}
			return -1;
		}

		bool is_full(){
			return (amount == length ? true : false);
		}




};
#endif
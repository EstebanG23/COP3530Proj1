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
	const int DEFAULT = 50;
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
		head = 0;
		tail = head;
		length = size;
		for (amount = 0; amount < size; ++amount){
			list[amount] = new Node;
			if (amount == size - 1){
				list[amount]->next = -1;
			}
			else{
				list[amount]->next = amount + 1;
			}
		}
		amount = 0;

	}

	SDAL(const SDAL& src){}

	~SDAL() {

	}


	SDAL& operator=(const SDAL& src) {
		if (&src == this){ // check for self-assignment
			return *this;     // do nothing
		}
		// safely dispose of this SDAL's contents
		// populate this SDAL with copies of the other SDAL's contents


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
		if (is_full()){
			grow_list();
		}
		if (amount == 0) {
			list[head]->data = element;
			tail = list[head]->next;
		}
		else{
			list[tail]->data = element;
			tail = list[tail]->next;
		}
		++amount;
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
		return list[position]->data;
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

	bool is_full(){
		return (tail == -1 ? true : false);
	}
	//clears list
	void clear() {

	}
	//done

	bool contains(const T& element,
		bool equals(const T& a, const T& b)) const {


	}

	std::ostream& print(std::ostream& out) const {

		for (int i = 0; i < amount; ++i){
			out << list[i]->data <<  " " << list[i]->next << std::endl;
		}
		return out;
	}


	private:
		void grow_list(){
			Node ** temp = list;
			length = (int) (length*1.5);
			list = new Node*[length];
			for (int i = 0; i < length; ++i){
				if (i < amount){
					list[i] = temp[i];
					list[i]->next = i+1;
				}
				else {
					list[i] = new Node;
					if (i != length - 1){
						list[i]->next = i+1;
					}
					else{
						list[i]->next = -1;
					}
				}
			}
			delete[] temp;
			tail = amount;
		}

		void shrink_list(){

		}






};

#endif
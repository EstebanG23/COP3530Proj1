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
	T * list;
	int tail = 0;
	//amount of items
	int amount;
	//total size
	int length;
	
public:


	SDAL() {
		SDAL(50);
	}

	SDAL(int size) {
		length = size;
		list = new T[size];
		amount = 0;
	}

	SDAL(const SDAL& src):this(src){}

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

	
	}//done

	//inserts elemenet, and shifts all elements after to the "left"
	void insert(const T& element, int position) {
		if (amount != length){
			for (int i = amount; i > position; --i){
				list[i] = list[i - 1];
			}
			list[position] = element;
		}
		else{
			grow_list();
			insert(element, position);
		}
		++tail;
		++amount;
	}//done

	//pushes element to the front of the list
	void push_front(const T& element) {
		insert(element, 0);
	}//done

	//pushes elemets to the back
	void push_back(const T& element) {
		insert(element, tail);
	}//done

	//pops the first element, assigns pointer to temp, replaces head with the next value
	T pop_front() {

	}//done

	//pops elements off the back, moves tail to the previous element
	T pop_back() {

	}//done

	//Removes an element from the list, from specified location
	T remove(int position) {
		
	}//done

	//Looks at item at position
	T item_at(int position) const { 
		return list[position];
	}//#done

	//Checks for emptiness
	bool is_empty() const { return (amount == 0 ? true : false);}
	//done

	//checks for size
	int size() const { return amount; }
	//done

	//clears list
	void clear() {

	}//done

	bool contains(const T& element,
		bool equals(const T& a, const T& b)) const {
	}

	std::ostream& print(std::ostream& out) const {

		
	}//done

	private:
		void grow_list(){
		

		}

		void shrink_list(){
			//LOGIC FOR LATER
			/*	Need to shrink list if list is >= 100 and amount < 50
				Need to reorder all of the items including what they point to. 
			*/
			
		}//done

		int is_free(){

		}//done

		bool is_full(){

		}//done

};
#endif
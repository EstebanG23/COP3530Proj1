#ifndef _CDAL_H_
#define _CDAL_H_

/*
Skeleton created by Dave Small

Methods and Logic Written by Joshua Kegley
*/

#include <iostream>


template <typename T>
class CDAL {
private:
	struct Node{
		T data[5];
		Node * next;
		int arrayTail = 0;
	};
	Node * head;
	Node * tail;
	int amount;
	int nodeAmount;

public:

	CDAL() {
		head = new Node;
		tail = head;
		nodeAmount = 1;
		amount = 0;
	}

	CDAL(const CDAL& src) :this(src){}

	~CDAL() {

	}


	CDAL& operator=(const CDAL& src) {
		if (&src == this){ // check for self-assignment
			return *this;     // do nothing
		}
		// safely dispose of this CDAL's contents
		// populate this CDAL with copies of the other CDAL's contents
	
	}


	//Replaces orginal element with specified element, returns orginal
	T replace(const T& element, int position) {
		
	}/*	
	 struct Node{
		T data[5];
		Node * next;
		int arrayTail = 0;
	};
	Node * head;
	Node * tail;
	int amount;
	int nodeAmount;
	*/

	//inserts elemenet, and shifts all elements after to the "left"
	void insert(const T& element, int position) {

		int nodePosition = position / 5;
		int arrayPosition = position % 5;

		Node * temp;

		if (arrayPosition == 0){
			//insert onto top, push everything back;
			for (int i = nodeAmount; i > 0; --i){
				temp = get_node(i); 
				if (temp->arrayTail == 4){
					temp->next = new Node;
					tail = temp->next;
					tail->data[0] = temp->data[4];
					++nodeAmount;
					++temp->arrayTail;
				}
				for (int i = temp->arrayTail; i > 0; --i){
					temp->data[i] = temp->data[i - 1];
				}
			}
			head->data[0] = element;
			if (head->arrayTail != 4){
				++head->arrayTail;
			}
			
		}

		

		++amount;
		
	}

	//pushes element to the front of the list
	void push_front(const T& element) {

	}

	//pushes elemets to the back
	void push_back(const T& element) {

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
	T item_at(int position) const {

	}

	//Checks for emptiness
	bool is_empty() const { return (amount == 0 ? true : false); }
	//done

	//checks for size
	int size() const { return amount; }
	//done

	//clears list
	void clear() {

	}

	bool contains(const T& element,
		bool equals(const T& a, const T& b)) const {

	}

	std::ostream& print(std::ostream& out) const {
		Node * temp = tail;
		std::cout << nodeAmount << "..." << amount << "..." << std::endl;
			for (int j = 0; j < temp->arrayTail; ++j){
				out << temp->data[j] << " ";
			}
	
		return out;
	}

private:

	Node* get_node(int position){
		Node * next = head;
		for (int i = 1; i < position; ++i){
			next = next->next;
		}

		return next;
	}




};
#endif;
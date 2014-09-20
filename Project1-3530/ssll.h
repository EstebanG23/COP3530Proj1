#ifndef _SSLL_H_
#define _SSLL_H_

// SSLL.H
// 
// Singly-linked list (non-polymorphic)
//
// by Dave Small
// for COP 3530
// 201409.16 - created

#include <iostream>



template <typename T>
class SSLL {
private:
	struct Node {
		T data;
		Node *next;

	}; // end struct Node
	Node *head;
	Node *tail;
	int amount;


public:

	//--------------------------------------------------
	// Constructors/destructor/assignment operator
	//--------------------------------------------------

	SSLL() {
		amount = 0;
		tail = new Node();
		head = tail;
	}

	//--------------------------------------------------
	SSLL(const SSLL& src){}

	//--------------------------------------------------
	~SSLL() {
		// safely dispose of this SSLL's contents
		clear();
		delete head;
	}

	//--------------------------------------------------
	SSLL& operator=(const SSLL& src) {
		if (&src == this) // check for self-assignment
			return *this;     // do nothing

		// safely dispose of this SSLL's contents
		// populate this SSLL with copies of the other SSLL's contents
		clear();
		for (int i = 0; i < src.size(); i++){
			push_back(src.item_at(i));
		}
	}


	//Replaces orginal element with specified element, returns orginal
	T replace(const T& element, int position) {
		Node * temp = head;
		T data;
		for (int i = 0; i <= position; ++i){
			if (i == position){
				data = temp->data;
				temp->data = element;
			}
			else{
				temp = temp->next;
			}

		}
			return data;

	}
	//#done

	//inserts elemenet, and shifts all elements after to the "left"
	void insert(const T& element, int position) {
		Node * next = head;
		Node * prev;

		if (position != 0 && position != amount - 1){
			for (int i = 0; i < position; ++i){
				prev = next;
				next = next->next;
				if (position - 1 == i){
					prev->next = new Node;
					prev->next->data = element;
					prev->next->next = next;

				}

			}
			++amount;
		}
		else if (position == 0){ push_front(element); }
		else { push_back(element); }
		
	}
	//#done

	//pushes element to the front of the list
	void push_front(const T& element) {
		if (amount == 0){
			head->data = element;
		}
		else{
			Node *temp = head;
			head = new Node;
			head->data = element;
			head->next = temp;
		}
		++amount;
	}
	//#done

	//pushes elemets to the back
	void push_back(const T& element) {
		if (amount == 0){
			head->data = element;
		}
		else {
			tail->next = new Node;
			tail = tail->next;
			tail->data = element;
			
		}
		++amount;	
	}
	//#done

	//pops the first element, assigns pointer to temp, replaces head with the next value
	T pop_front() {
		T data = head->data;
		Node * temp = head;
		head = head->next;
		delete temp;
		--amount;
		return data;
	}
	//#done

	//pops elements off the back, moves tail to the previous element
	T pop_back() {
		T data = tail->data;
		if (amount == 1){
			delete tail;
			head = new Node;
			tail = head;
		}
		else{
			delete tail;
			tail = head;
			for (int i = 0; i < amount - 2; ++i){
				tail = tail->next;
				//std::cout << tail->data << std::endl;
			}
		}

		--amount;
		return data;
	}
	//#done


	//Removes an element from the list, from specified location
	T remove(int position) {
		Node * prev = head;
		Node * select;
		T data;
		//if position is the last position, handle it differenly, reassign tail. 
		if (position == amount - 1){
			tail = head;
			for (int i = 1; i < position; i++){
				tail = tail->next;
				std::cout << "tail position: " << i << tail->data << std::endl;
				select = tail->next;
				data = select->data;
			}
		}
		//if it isn't the last or the first, iterate to the one before, set select to the one, and reassign pointer for the one before.
		else if (position != 0){
			for (int i = 1; i < position; i++){
				prev = prev->next;
				select = prev->next;
				data = select->data;

			}
		}
		//if 0 position, reasign head
		else{
			select = head;
			head = select->next;
			data = select->data;			
		}
		//delete the old!
		delete select;
		--amount;
		return data;
	}
	//#done

	//Looks at item at position
	T item_at(int position) const {
		Node * select = head;
		T data;
		for (int i = 0; i < position; i++){
			select = select->next;
		}
		data = select->data;
		return data;
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
		Node * temp = head;
		for (int i = 0; i < amount; i++){
			tail = temp;
			temp = temp->next;
			delete tail;
		}
		head = new Node;
		tail = head;
		amount = 0;
	
	}
	//done

	bool contains(const T& element,
		bool equals(const T& a, const T& b)) const {

		Node* temp = head;
		for (int i = 0; i < amount; i++){
			if (temp->data == element){
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	std::ostream& print(std::ostream& out) const {
		Node * temp = head;
		if (this->is_empty()){
			out << "<empty list>";
		}
		else{
			out << "[";
			for (int i = 0; i < amount; i++){
				if (i == amount - 1){
					out << temp->data;

					
				}
				else{
				out << temp->data << ",";

				}
				temp = temp->next;
			}
			out << "]";
		}
		
		return out;
	
	}

}; 
 
#endif
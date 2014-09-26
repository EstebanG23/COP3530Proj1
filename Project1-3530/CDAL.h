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
		
	}
	 

	//inserts elemenet, and shifts all elements after to the "left"
	void insert(const T& element, int position) {

		if (is_full()){
			grow();
		}


		Node * temp = tail;
		Node * prev;
		////////////////////////////FOR ENTERING AT HEAD//////////////////////////////////
		if (position == 0){
			for (int i = nodeAmount; i > 0; --i){
				prev = temp;
				for (int j = prev->arrayTail; j > 0; --j){
					if (j < 5){
						prev->data[j] = prev->data[j - 1];
					}				
				}
				
				temp = get_node(i-1);
				if (i == 1){
					temp->data[0] = element;
					if (head->arrayTail < 4){
						++head->arrayTail;
					}
					else{
						++tail->arrayTail;
					}
				}
				else{
					prev->data[0] = temp->data[4];
				}
			}
		}
		////////////////////////////FOR ENTERING AT TAIL//////////////////////////////////
		else if (position == amount){
			temp->data[position % 5] = element;
			++temp->arrayTail;
		}
		////////////////////////////FOR ENTERING ELSE WHERE//////////////////////////////////

		else{
			int nodePosition = position / 5;
			int arrayPosition = (position % 5);
			std::cout << nodePosition << ">>>" << arrayPosition << std::endl;
			
			
			for (int i = nodeAmount; i > nodePosition; --i){
				std::cout << temp << std::endl;
				prev = temp;
				if (i - 1 != nodePosition){
					for (int i = temp->arrayTail; i > 0; --i){
						temp->data[i] = temp->data[i - 1];
					}
				}
				else{
					for (int i = temp->arrayTail; i > arrayPosition; --i){
						if (i < 5){
						temp->data[i] = temp->data[i - 1];
						}
					}
					temp->data[arrayPosition] = element;

				}
				if (temp == tail){ ++temp->arrayTail; }
				temp = get_node(i - 1);
				prev->data[0] = temp->data[4];

			}


		}
		

		++amount;
		
	}

	//pushes element to the front of the list
	void push_front(const T& element) {

	}

	//pushes elemets to the back
	void push_back(const T& element) {
		insert(element, amount);
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
		Node * temp = head;
		std::cout << "Nodes: " << nodeAmount << std::endl;
		std::cout << "Amount: " << amount << std::endl;
		std::cout << "Max Size: " << nodeAmount * 5 << std::endl;
		std::cout << "head: " << head << std::endl;
		std::cout << "tail: " << tail << std::endl;

		for (int i = 0; i < nodeAmount; ++i){
			out << "(((Node#: " << i << " " << temp << " tail: "<< temp->arrayTail << " [";
			for (int j = 0; j <= temp->arrayTail-1; ++j){
					out << temp->data[j] << " ";
			}
			out << "] " << ")))" << std::endl;
			temp = temp->next;
		}

		return out;
	}

private:

	bool is_full(){
		return (amount == 5 * nodeAmount) ? true : false;
	}
	
	void grow(){
		tail->next = new Node;
		tail = tail->next;
		++nodeAmount;
	}


	Node* get_node(int position){
		Node * next = head;
		for (int i = 1; i < position; ++i){
			next = next->next;
		}
		return next;
	}




};
#endif;
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
		T data[50];
		Node * next;
		int nodeTail = 0;
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
		
	}

	//pushes element to the front of the list
	void push_front(const T& element) {

	}

	//pushes elemets to the back
	void push_back(const T& element) {
		if (tail->nodeTail != 49){
			if (amount == 0){
				std::cout << "Should go here" << amount << std::endl;
				tail->data[tail->nodeTail] = element;
	
			}
			else {
				++tail->nodeTail;
				tail->data[tail->nodeTail] = element;
			}
		}
		else{
			std::cout << "Creating New Node" << amount << std::endl; 
			tail->next = new Node;
			tail = tail->next;
			tail->data[tail->nodeTail] = element;
			++nodeAmount;
		}
	
		++amount;
	}

	//pops the first element, assigns pointer to temp, replaces head with the next value
	T pop_front() {
		T data = head->data[0];
		tail = head;
		Node * prev = tail;
		for (int i = 0; i < nodeAmount; i++){
			tail->data[0] = tail->data[1];
			tail->data[1] = tail->data[2];
			tail->data[2] = tail->data[3];
			tail->data[3] = tail->data[4];
			tail->data[4] = tail->data[5];
			tail->data[5] = tail->data[6];
			tail->data[6] = tail->data[7];
			tail->data[7] = tail->data[8];
			tail->data[8] = tail->data[9];
			tail->data[9] = tail->data[10];
			tail->data[10] = tail->data[11];
			tail->data[11] = tail->data[12];
			tail->data[12] = tail->data[13];
			tail->data[13] = tail->data[14];
			tail->data[14] = tail->data[15];
			tail->data[15] = tail->data[16];
			tail->data[16] = tail->data[17];
			tail->data[17] = tail->data[18];
			tail->data[18] = tail->data[19];
			tail->data[19] = tail->data[20];
			tail->data[20] = tail->data[21];
			tail->data[21] = tail->data[22];
			tail->data[22] = tail->data[23];
			tail->data[23] = tail->data[24];
			tail->data[24] = tail->data[25];
			tail->data[25] = tail->data[26];
			tail->data[26] = tail->data[27];
			tail->data[27] = tail->data[28];
			tail->data[28] = tail->data[29];
			tail->data[29] = tail->data[30];
			tail->data[30] = tail->data[31];
			tail->data[31] = tail->data[32];
			tail->data[32] = tail->data[33];
			tail->data[33] = tail->data[34];
			tail->data[34] = tail->data[35];
			tail->data[35] = tail->data[36];
			tail->data[36] = tail->data[37];
			tail->data[37] = tail->data[38];
			tail->data[38] = tail->data[39];
			tail->data[39] = tail->data[40];
			tail->data[40] = tail->data[41];
			tail->data[41] = tail->data[42];
			tail->data[42] = tail->data[43];
			tail->data[43] = tail->data[44];
			tail->data[44] = tail->data[45];
			tail->data[45] = tail->data[46];
			tail->data[46] = tail->data[47];
			tail->data[47] = tail->data[48];
			tail->data[48] = tail->data[49];
			if (i < nodeAmount-1){
				tail->data[49] = tail->next->data[0];
			}
			tail = tail->next;
		}
		--amount;
		return data;
	}

	//pops elements off the back, moves tail to the previous element
	T pop_back() {
		std::cout << "Node Tail: " << tail->nodeTail;
		T data = tail->data[tail->nodeTail];
		if (tail->nodeTail == 0){
			tail = head;
			for (int i = 1; i < nodeAmount-1; ++i){
				tail = tail->next;
			}
		}
		else{
			--tail->nodeTail;
		}
		--amount;
		return data;
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

		
	}

private:
	void grow_list(){
		
	}

	void shrink_list(){
			
	}

	int is_free(){
		
	}

	bool is_node_full(){
		if (tail->nodeTail = -1){
			return true;
		}
		return false;
	}




};
#endif;
#ifndef _PSLL_H_
#define _PSLL_H_


/*
Skeleton created by Dave Small

Methods and Logic Written by Joshua Kegley
*/

#include <iostream>

namespace cop3530 {

	template <typename T>
	class PSLL {
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
		size_t poolAmount;



	public:
		class PSLL_Iter //: public std::iterator<std::forward_iterator_tag, T>
		{
		public:
			// inheriting from std::iterator<std::forward_iterator_tag, T>
			// automagically sets up these typedefs...
			typedef T value_type;
			typedef std::ptrdiff_t difference_type;
			typedef T& reference;
			typedef T* pointer;
			typedef std::forward_iterator_tag iterator_category;

			// but not these typedefs...
			typedef PSLL_Iter self_type;
			typedef PSLL_Iter& self_reference;

		private:
			Node* here;

		public:
			explicit PSLL_Iter(Node* start = NULL) : here(start) {}
			PSLL_Iter(const PSLL_Iter& src) : here(src.here) {}

			reference operator*() const { return here->data; }
			pointer operator->() const { return here; }
			self_reference operator=(const PSLL_Iter& src) {
				delete this;
				*this = src;
			}//done

			self_reference operator++() {
				here = here->next;
				return *this;
			} // preincrement
			self_type operator++(int) {
				PSLL_iter temp(*this);
				here = here->next;
				return here;
			} // postincrement

			bool operator==(const PSLL_Iter& rhs) const {
				if (here == rhs.here){
					return true;
				}
				return false;
			}//done
			bool operator!=(const PSLL_Iter& rhs) const {
				if (here != rhs.here){
					return true;
				}
				return false;
			}
		}; // end PSLL_Iter 


	public:
		class PSLL_Const_Iter //: public std::iterator<std::forward_iterator_tag, T>
		{
		public:
			// inheriting from std::iterator<std::forward_iterator_tag, T>
			// automagically sets up these typedefs...
			typedef T value_type;
			typedef std::ptrdiff_t difference_type;
			typedef const T& reference;
			typedef const T* pointer;
			typedef std::forward_iterator_tag iterator_category;

			// but not these typedefs...
			typedef PSLL_Const_Iter self_type;
			typedef PSLL_Const_Iter& self_reference;

		private:
			const Node* here;

		public:
			explicit PSLL_Const_Iter(Node* start = NULL) : here(start) {}
			PSLL_Const_Iter(const PSLL_Const_Iter& src) : here(src.here) {}

			reference operator*() const { return here->data; }//done
			pointer operator->() const { return here; }//done

			self_reference operator=(const PSLL_Const_Iter& src) {
				delete this;
				*this = src;
			}//done

			self_reference operator++() {
				here = here->next;
				return *this;
			} // preincrement//done
			self_type operator++(int) {
				SSLL_iter temp(*this);
				here = here->next;
				return here;
			} // postincrement//done

			bool operator==(const PSLL_Const_Iter& rhs) const {
				if (here == rhs.here){
					return true;
				}
				return false;
			}//done

			bool operator!=(const PSLL_Const_Iter& rhs) const {
				if (here != rhs.here){
					return true;
				}
				return false;
			}
		}; // end PSLL_Iter 

		//--------------------------------------------------
		// types
		//--------------------------------------------------
		typedef std::size_t size_t;
		typedef T value_type;
		typedef PSLL_Iter iterator;
		typedef PSLL_Const_Iter const_iterator;

		//--------------------------------------------------
		// Constructors/destructor/assignment operator
		//--------------------------------------------------

		PSLL() {
			amount = 0;
			tail = new Node();
			head = tail;
			poolAmount = 0;
		}

		//--------------------------------------------------
		PSLL(const PSLL& src){}

		//--------------------------------------------------
		~PSLL() {
			// safely dispose of this PSLL's contents
			clear();
			delete head;
		}

		//--------------------------------------------------
		PSLL& operator=(const PSLL& src) {
			if (&src == this) // check for self-assignment
				return *this;     // do nothing

			// safely dispose of this PSLL's contents
			// populate this PSLL with copies of the other PSLL's contents
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
						prev->next = pop_pool();
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
				head = pop_pool();
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
				tail->next = pop_pool();
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
			//Adding removed Node to Pool
			push_pool(temp);
			--amount;
			return data;
		}
		//#done

		//pops elements off the back, moves tail to the previous element
		T pop_back() {
			T data = tail->data;
			//Adding removed Node to Pool
			push_pool(tail);
			if (amount == 1){
				head = pop_pool();
				tail = head;
			}
			else{
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
		size_t size() const { return amount; }
		//#done
		//clears list
		void clear() {
			Node * temp = head;
			for (int i = 0; i < amount; i++){
				tail = temp;
				temp = temp->next;
				delete tail;
			}
			head = pop_pool();
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

	private:
		//pushes all emptied, unused nodes to the back
		void push_pool(Node* src){
			std::cout << "Pool size: ";
			std::cout << poolAmount << std::endl;
			if (amount >= 100 && poolAmount > amount / 2){
				delete src;
				int i = poolAmount / 2;
				while (poolAmount > i){
					std::cout << "Trying to delete half nodes" << std::endl;
					Node * temp = poolHead;
					poolHead = poolHead->next;
					delete temp;
					--poolAmount;
				}
			}
			else{
				if (poolAmount != 0){
					poolTail->next = src;
					poolTail = poolTail->next;
				}
				else{
					poolHead = src;
					poolTail = src;
				}
				++poolAmount;
			}

		}

		//Either creates a new Node or sends one from the pool if it exist. 
		Node* pop_pool(){
			if (poolAmount != 0){
				Node * temp = poolHead;
				poolHead = poolHead->next;
				--poolAmount;
				return temp;
			}
			else{
				Node * temp = new Node;
				return temp;
			}

		}

	};
}//end namespace
#endif
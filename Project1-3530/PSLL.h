#ifndef _PSLL_H_
#define _PSLL_H_
#include <cstddef>
#include <cstdlib>
#include <stdexcept>
#include <exception>
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
		std::size_t amount;
		std::size_t poolAmount;



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
			}

			self_reference operator++() {
				here = here->next;
				return *this;
			} // preincrement
			self_type operator++(int) {
				PSLL_Iter temp(*this);
				here = here->next;
				return here;
			} // postincrement

			bool operator==(const PSLL_Iter& rhs) const {
				if (here == rhs.here){
					return true;
				}
				return false;
			}
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

			reference operator*() const { return here->data; }
			pointer operator->() const { return here; }

			self_reference operator=(const PSLL_Const_Iter& src) {
				delete this;
				*this = src;
			}

			self_reference operator++() {
				here = here->next;
				return *this;
			} // preincrement
			self_type operator++(int) {
				PSLL_Const_Iter temp(*this);
				here = here->next;
				return here;
			} // postincrement

			bool operator==(const PSLL_Const_Iter& rhs) const {
				if (here == rhs.here){
					return true;
				}
				return false;
			}

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
		// Iterator Begin & Begin Helpers
		//--------------------------------------------------

		iterator begin() { return PSLL_Iter(head); }
		iterator end() { return PSLL_Iter(tail->next); }

		const_iterator begin() const { return PSLL_Const_Iter(head); }
		const_iterator end() const { return PSLL_Const_Iter(tail->next); }



		//--------------------------------------------------
		// Constructors/destructor/assignment operator
		//--------------------------------------------------

		PSLL() {
			amount = 0;
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

		T& operator[](int position){
			if (position < 0 || position >(int)amount){
				if (position < 0){ throw std::invalid_argument("Argument Incorrect: does not take negative integers."); }
				else{ throw std::invalid_argument("Argument Incorrect: Position does not exist."); }
			}
			Node * select = head;
			
			for (int i = 0; i < position; i++){
				select = select->next;
			}
			T& data = select->data;
			return data;
		}

		T const& operator[](int position) const{
			if (position < 0 || position >(int)amount){
				if (position < 0){ throw std::invalid_argument("Argument Incorrect: does not take negative integers."); }
				else{ throw std::invalid_argument("Argument Incorrect: Position does not exist."); }
			}
			Node * select = head;

			for (int i = 0; i < position; i++){
				select = select->next;
			}
			const data = select->data;
			return data;
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
			Node * temp;
			Node * prev;
			if (position == 0 && amount == 0){
				head = pop_pool();
				head->data = element;
				tail = head;
			}
			else if (position == 0){
				temp = pop_pool();
				temp->data = element;
				temp->next = head;
				head = temp;
			}
			else if (position == amount){
				tail->next = pop_pool();
				tail = tail->next;
				tail->data = element;
			}
			else{
				prev = head;
				temp = pop_pool();
				temp->data = element;
				for (int i = 0; i < position-1; ++i){
					prev = prev->next;
				}
				temp->next = prev->next;
				prev->next = temp;
			}

			++amount;
		}
		//#done

		//pushes element to the front of the list
		void push_front(const T& element) {
			insert(element, 0);
		}
		//#done

		//pushes elemets to the back
		void push_back(const T& element) {
			insert(element, amount);
		}
		//#done 

		//pops the first element, assigns pointer to temp, replaces head with the next value
		T pop_front() {
			return remove(0);
		}
		//#done

		//pops elements off the back, moves tail to the previous element
		T pop_back() {
			return remove(amount - 1);
		}
		//#done

		//Removes an element from the list, from specified location
		T remove(int position) {
			Node * temp;
			Node * prev;
			T data;
			if (position == 0){
				temp = head;
				head = head->next;
				data = temp->data;
				push_pool(temp);
			}
			else if (position == amount - 1){
				prev = head;
				for (int i = 0; i < position - 1; ++i){
					prev = prev->next;
				}
				data = tail->data;
				push_pool(tail);
				tail = prev;
			}
			else{
				prev = head;
				for (int i = 0; i < position - 1; ++i){
					prev = prev->next;
				}
				temp = prev->next;
				data = temp->data;
				prev->next = temp->next;
				push_pool(temp);
				
			}
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
		std::size_t size() const { return amount; }
		//#done
		//clears list
		void clear() {
			Node * temp = head;
			for (int i = 0; i < (int)amount; i++){
				tail = temp;
				temp = temp->next;
				delete tail;
			}
			head = pop_pool();
			tail = head;
			amount = 0;

		}
		

		bool contains(const T& element,
			bool equals(const T& a, const T& b)) const {

			Node* temp = head;
			for (int i = 0; i < (int)amount; i++){
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
				for (int i = 0; i < (int)amount; i++){
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
			if ((int)amount >= 100 && (int)poolAmount > (int)amount / 2){
				delete src;
				int i = (int)poolAmount / 2;
				while ((int)poolAmount > i){
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
				try{
					Node * temp = new Node;
					return temp;
				}
				catch (std::bad_alloc)
				{
					std::cerr << "Memory Allocation Failed " << std::endl;
				}
				
			}
			return 0;

		}

	};
}//end namespace
#endif
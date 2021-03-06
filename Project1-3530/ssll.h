#ifndef _SSLL_H_
#define _SSLL_H_
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
	class SSLL {
	private:
		struct Node {
			T data;
			Node *next;

		}; // end struct Node
		Node *head;
		Node *tail;
		std::size_t amount;


	public:
		//-------------------------------------------------------------------------
		//  Non Const Iterator
		//-------------------------------------------------------------------------
		class SSLL_Iter //: public std::iterator<std::forward_iterator_tag, T>
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
			typedef SSLL_Iter self_type;
			typedef SSLL_Iter& self_reference;

		private:
			Node* here;

		public:
			explicit SSLL_Iter(Node* start = NULL) : here(start) {}
			SSLL_Iter(const SSLL_Iter& src) : here(src.here) {}

			reference operator*() const { return here->data; }
			pointer operator->() const { return here; }
			self_reference operator=(const SSLL_Iter& src) {
				delete this;
				*this = src;
			}

			self_reference operator++() {
				here = here->next;
				return *this;
			} // preincrement
			self_type operator++(int) {
				SSLL_Iter temp(*this);
				here = here->next;
				return here;
			} // postincrement

			bool operator==(const SSLL_Iter& rhs) const {
				if (here == rhs.here){
					return true;
				}
				return false;
			}
			bool operator!=(const SSLL_Iter& rhs) const {
				if (here != rhs.here){
					return true;
				}
				return false;
			}
		}; // end SSLL_Iter 

	//-------------------------------------------------------------------------
	//  Const Iterator
	//-------------------------------------------------------------------------

	public:
		class SSLL_Const_Iter //: public std::iterator<std::forward_iterator_tag, T>
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
			typedef SSLL_Const_Iter self_type;
			typedef SSLL_Const_Iter& self_reference;

		private:
			const Node* here;

		public:
			explicit SSLL_Const_Iter(Node* start = NULL) : here(start) {}
			SSLL_Const_Iter(const SSLL_Const_Iter& src) : here(src.here) {}

			reference operator*() const { return here->data; }
			pointer operator->() const { return here; }

			self_reference operator=(const SSLL_Const_Iter& src) {
				delete this;
				*this = src;
			}

			self_reference operator++() {
				here = here->next;
				return * this;
			} // preincrement
			self_type operator++(int) {
				SSLL_Const_Iter temp(*this);
				here = here->next;
				return here;
			} // postincrement

			bool operator==(const SSLL_Const_Iter& rhs) const {
				if (here == rhs.here){
					return true;
				}
				return false;
			}
	
			bool operator!=(const SSLL_Const_Iter& rhs) const {
				if (here != rhs.here){
					return true;
				}
				return false;
			}
		}; // end SSLL_Iter 

		//--------------------------------------------------
		// types
		//--------------------------------------------------
		typedef std::size_t size_t;
		typedef T value_type;
		typedef SSLL_Iter iterator;
		typedef SSLL_Const_Iter const_iterator;

		//--------------------------------------------------
		// Iterator Begin & Begin Helpers
		//--------------------------------------------------


		iterator begin() { return SSLL_Iter(head); }
		iterator end() { return SSLL_Iter(tail->next); }

		const_iterator begin() const { return SSLL_Const_Iter(head); }
		const_iterator end() const { return SSLL_Const_Iter(tail->next); }

		//--------------------------------------------------
		// Constructors/destructor/assignment operator
		//--------------------------------------------------

		SSLL() {
			amount = 0;
			tail = get_new_Node();
			head = tail;
		}

		//--------------------------------------------------
		SSLL(const SSLL& src){
			*this = src;
		}

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
			for (int i = 0; i < (int)src.size(); i++){
				push_back(src.item_at(i));
			}
			return *this;
		}

		//-------------------------------------------------------------------------
		//  []
		//
		//	returns a non const reference to a specified position
		//-------------------------------------------------------------------------
		T& operator[](int position){
			if (position < 0 || position > (int)amount){
				if (position < 0){ throw std::invalid_argument("Domain Incorrect: does not take negative integers."); }
				else{ throw std::invalid_argument("Domain Incorrect: Position does not exist."); }
			}
			Node * select = head;
			for (int i = 0; i < position; i++){
				select = select->next;
			}
			T& data = select->data;
			return data;
		}

		//-------------------------------------------------------------------------
		//  []
		//
		//	returns a const reference to a specified position
		//-------------------------------------------------------------------------
		T const& operator[](int position) const{
			if (position < 0 || position > amount){
				if (position < 0){ throw std::invalid_argument("Domain Incorrect: does not take negative integers."); }
				else{ throw std::invalid_argument("Domain Incorrect: Position does not exist."); }
			}
			Node * select = head;
			for (int i = 0; i < position; i++){
				select = select->next;
			}
			const T& data = select->data;
			return data;
		}

		//-------------------------------------------------------------------------
		//  Replace
		//
		//	replaces an element with a specified element at a specified position
		//	returning the original element
		//-------------------------------------------------------------------------
		T replace(const T& element, int position) {
			if (position < 0 || position > (int)amount - 1 ){
				if (position < 0){ throw std::invalid_argument("Domain Incorrect: does not take negative integers."); }
				else{ throw std::invalid_argument("Domain Incorrect: Position does not exist."); }
			}
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


		//-------------------------------------------------------------------------
		//  Insert
		//
		//	inserts an element to desired position
		//-------------------------------------------------------------------------
		void insert(const T& element, int position) {
			if (position < 0 || position >(int)amount){
				if (position < 0){ throw std::invalid_argument("Domain Incorrect: does not take negative integers."); }
				else{ throw std::invalid_argument("Domain Incorrect: Position does not exist."); }
			}
			Node * next = head;
			Node * temp = get_new_Node();
			temp->data = element;

			if (amount == 0){
				head->data = element;
			}
			else if (position == 0){
				temp->next = head;
				head = temp;
			}
			else if (position == amount){
				tail->next = temp;
				tail = temp;
			}
			else{
				for (int i = 0; i < position - 1; ++i){
					next = next->next;
				}
				temp->next = next->next;
				next->next = temp;
			}
			++amount;
		}

		//-------------------------------------------------------------------------
		//  Push back
		//
		//	adds an element to the front, using insert
		//-------------------------------------------------------------------------
		void push_front(const T& element) {
			insert(element, 0);
		}

		//-------------------------------------------------------------------------
		//  Push back
		//
		//	adds an element to the back, using insert
		//-------------------------------------------------------------------------
		void push_back(const T& element) {
			insert(element, amount);
		}

		//-------------------------------------------------------------------------
		//  Pop Front
		//
		//	removes an element from the from, using remove()
		//-------------------------------------------------------------------------
		T pop_front() {
			return remove(0);
		}

		//-------------------------------------------------------------------------
		//	Pop Back
		//
		//	removes an element from the end, using remove()
		//-------------------------------------------------------------------------
		T pop_back() {
			return remove(amount - 1);
		}


		//-------------------------------------------------------------------------
		//	Remove
		//
		//	Removes an element from the list, from specified location
		//-------------------------------------------------------------------------
		T remove(int position) {
			if (position < 0 || position > (int)amount){
				if (position < 0){ throw std::invalid_argument("Argument Incorrect: does not take negative integers."); }
				else{ throw std::invalid_argument("Argument Incorrect: Position does not exist."); }
			}
			Node * next = head;
			Node * prev = head;
			T data;
			if (position == 0){
				data = next->data;
				next = next->next;
				delete head;
				head = next;
			}
			else if (position == amount - 1){
				for (int i = 0; i < position - 1; ++i){
					next = next->next;
					std::cout << next->data;

				}
				data = next->next->data;
				delete tail;
				tail = next;

			}
			else{
				for (int i = 0; i < position - 1; ++i){
					next = next->next;
					//std::cout << next->data;

				}
				data = next->next->data;
				Node * temp = next->next;
				next->next = temp->next;
				delete temp;
			}

			--amount;
			return data;
		}

		//-------------------------------------------------------------------------
		//	Item At
		//
		//	find the element held at position
		//-------------------------------------------------------------------------
		T item_at(int position) const {
			if (position < 0 || position > (int)amount ){
				if (position < 0){ throw std::invalid_argument("Argument Incorrect: does not take negative integers."); }
				else{ throw std::invalid_argument("Argument Incorrect: Position does not exist."); }
			}
			Node * select = head;
			T data;
			for (int i = 0; i < position; i++){
				select = select->next;
			}
			data = select->data;
			return data;
		}
		//#done

		//-------------------------------------------------------------------------
		//  Is Empty
		//
		//	Checks to see if the structure is empty
		//-------------------------------------------------------------------------
		bool is_empty() const {
			return (amount == 0 ? true : false);
		}

		//-------------------------------------------------------------------------
		//  Size
		//
		//	returns size of type size_t
		//-------------------------------------------------------------------------
		//checks for size
		std::size_t size() const { return amount; }
		//#done

		//-------------------------------------------------------------------------
		//  Clear
		//
		//	Clears the structure and then creates a new head node
		//-------------------------------------------------------------------------
		void clear() {
			Node * temp = head;
			for (int i = 0; i < (int)amount; i++){
				tail = temp;
				temp = temp->next;
				delete tail;
			}
			head = get_new_Node();
			tail = head;
			amount = 0;

		}


		//-------------------------------------------------------------------------
		//  Contains
		//
		//	does the structure have an element that matches the element provided
		//-------------------------------------------------------------------------
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

		//-------------------------------------------------------------------------
		//  ostream print method
		//-------------------------------------------------------------------------
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
		//-------------------------------------------------------------------------
		//  Return new node
		//
		//	Tries to allocate a new node, if it can it returns the node.
		//-------------------------------------------------------------------------

		Node* get_new_Node(){
			try{
				return new Node;
			}
			catch (std::bad_alloc)
			{
				std::cerr << "Memory Allocation Failed " << std::endl;
			}
			return 0;

			//BST* Node; WHAT?
		}

	};
}//end namepace
#endif
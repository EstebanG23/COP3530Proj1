#ifndef _SDAL_H_
#define _SDAL_H_
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
	class SDAL {
	private:
		T * list;
		int tail;
		//amount of items
		std::size_t amount;
		//total size
		int length;

	public:
		class SDAL_Iter //: public std::iterator<std::forward_iterator_tag, T>
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
			typedef SDAL_Iter self_type;
			typedef SDAL_Iter& self_reference;

		private:
			T * here;

		public:
			explicit SDAL_Iter(T * start = NULL) : here(start) {}
			SDAL_Iter(const SDAL_Iter& src) : here(src.here) {}

			reference operator*() const { return *here; }
			pointer operator->() const { return here; }
			self_reference operator=(const SDAL_Iter& src) {
				delete this;
				*this = src;
			}

			self_reference operator++() {
				here = ++here;
				return *this;
			} // preincrement
			self_type operator++(int) {
				SDAL_Iter temp(*this);
				here = ++here;
				return here;
			} // postincrement

			bool operator==(const SDAL_Iter& rhs) const {
				if (here == rhs.here){
					return true;
				}
				return false;
			}
			bool operator!=(const SDAL_Iter& rhs) const {
				if (here != rhs.here){
					return true;
				}
				return false;
			}
		}; // end SDAL_Iter 


	public:
		class SDAL_Const_Iter //: public std::iterator<std::forward_iterator_tag, T>
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
			typedef SDAL_Const_Iter self_type;
			typedef SDAL_Const_Iter& self_reference;

		private:
			T * here;

		public:
			explicit SDAL_Const_Iter(T * start = NULL) : here(start) {}
			SDAL_Const_Iter(const SDAL_Const_Iter& src) : here(src.here) {}

			reference operator*() const { return *here; }
			pointer operator->() const { return here; }

			self_reference operator=(const SDAL_Const_Iter& src) {
				delete this;
				*this = src;
			}

			self_reference operator++() {
				here = here->next;
				return *this;
			} // preincrement
			self_type operator++(int) {
				SDAL_Const_Iter temp(*this);
				here = &here->next;
				return here;
			} // postincrement

			bool operator==(const SDAL_Const_Iter& rhs) const {
				if (here == rhs.here){
					return true;
				}
				return false;
			}

			bool operator!=(const SDAL_Const_Iter& rhs) const {
				if (here != rhs.here){
					return true;
				}
				return false;
			}
		}; // end SDAL_Iter 

		//--------------------------------------------------
		// types
		//--------------------------------------------------

		typedef std::size_t size_t;
		typedef T value_type;
		typedef SDAL_Iter iterator;
		typedef SDAL_Const_Iter const_iterator;

		//--------------------------------------------------
		// Iterator Begin & Begin Helpers
		//--------------------------------------------------

		iterator begin() { return SDAL_Iter(&list[0]); }
		iterator end() { return SDAL_Iter(&list[amount]); }

		const_iterator begin() const { return SDAL_Const_Iter(&list[0]); }
		const_iterator end() const { return SDAL_Const_Iter(&list[amount]); }


		SDAL() {
			length = 50;
			list = get_new_T(length);
			amount = 0;
			tail = 0;
		}

		SDAL(int size) {
			length = size;
			list = get_new_T(length);
			amount = 0;
			tail = 0;
		}

		SDAL(const SDAL& src){ *this = src; }
		
		~SDAL() {

		}


		SDAL& operator=(const SDAL& src) {
			if (&src == this){ // check for self-assignment
				return *this;     // do nothing
			}
			// safely dispose of this SDAL's contents
			// populate this SDAL with copies of the other SDAL's contents
			clear();
			delete[] list;

			tail = src.tail;
			amount = src.amount;
			length = src.length;
			list = new T[length];
			for (int i = 0; i < amount; ++i){
				list[i] = src.list[i];
			}

		}

		T& operator[](int position){
			if (position < 0 || position > (int)amount){
				if (position < 0){ throw std::invalid_argument("Argument Incorrect: does not take negative integers."); }
				else{ throw std::invalid_argument("Argument Incorrect: Position does not exist."); }
			}
			return list[position];
		}

		T const& operator[](int position) const{
			if (position < 0 || position >(int)amount){
				if (position < 0){ throw std::invalid_argument("Argument Incorrect: does not take negative integers."); }
				else{ throw std::invalid_argument("Argument Incorrect: Position does not exist."); }
			}
			return list[position];
		}

		//Replaces orginal element with specified element, returns orginal
		T replace(const T& element, int position) {
			if (position < 0 || position > amount){
				if (position < 0){ throw std::invalid_argument("Argument Incorrect: does not take negative integers."); }
				else{ throw std::invalid_argument("Argument Incorrect: Position does not exist."); }
			}
			T data = list[position];
			list[position] = element;
			return data;
		}

		//inserts elemenet, and shifts all elements after to the "left"
		void insert(const T& element, int position) {
			if (amount == length){ grow_list(); }
			if (position < 0 || position > (int)amount + 1){
				if (position < 0){ throw std::invalid_argument("Argument Incorrect: does not take negative integers."); }
				else{ throw std::invalid_argument("Argument Incorrect: Position does not exist."); }
			}

			if (amount != length){
				for (int i = amount; i > position; --i){
					list[i] = list[i - 1];
				}
				list[position] = element;
			}
			++amount;
			++tail;
		}

		//pushes element to the front of the list
		void push_front(const T& element) {
			insert(element, 0);
		}

		//pushes elemets to the back
		void push_back(const T& element) {
			insert(element, tail);
		}

		//pops the first element, assigns pointer to temp, replaces head with the next value
		T pop_front() {
			return remove(0);
		}

		//pops elements off the back, moves tail to the previous element
		T pop_back() {
			return remove(tail);

		}

		//Removes an element from the list, from specified location
		T remove(int position) {
			if (length >= 100 && amount < length / 2){ shrink_list(); }
			if (position < 0 || position > amount){
				if (position < 0){ throw std::invalid_argument("Argument Incorrect: does not take negative integers."); }
				else{ throw std::invalid_argument("Argument Incorrect: Position does not exist."); }
			}

			T data = list[position];
			for (int i = position; i < amount; ++i){
				list[i] = list[i + 1];
			}
			--amount;
			--tail;

			return data;
		}

		//Looks at item at position
		T item_at(int position) const {
			if (position < 0 || position > amount){
				if (position < 0){ throw std::invalid_argument("Argument Incorrect: does not take negative integers."); }
				else{ throw std::invalid_argument("Argument Incorrect: Position does not exist."); }
			}
			return list[position];
		}//#done

		//Checks for emptiness
		bool is_empty() const { return (amount == 0 ? true : false); }
		

		//checks for size
		size_t size() const { return amount; }
		

		//clears list
		void clear() {
			amount = 0;
			tail = 0;

		}

		bool contains(const T& element,
			bool equals(const T& a, const T& b)) const {
			for (int i = 0; i < (int)amount; ++i){
				if (list[i] == element){ return true; }
			}
		}

		std::ostream& print(std::ostream& out) const {
			for (int i = 0; i < (int)amount; ++i){
				if (i == 0){
					out << "[" << list[i] << ",";
				}
				else if (i != amount - 1){
					out << list[i] << ",";
				}
				else{
					out << list[i] << "]";
				}
			}
			return amount != 0 ? out : out << "<empty list>";
		}

	private:
		void grow_list(){
			length = (int)(length * 1.5);

			T * temp = get_new_T(length);
			
			for (int i = 0; i < (int)amount; ++i){
				temp[i] = list[i];
			}
			delete[] list;
			tail = amount - 1;
			list = temp;
		}

		void shrink_list(){
			length = length / 2;
			
			T * temp = get_new_T(length);
			
			for (int i = 0; i < amount; ++i){
				temp[i] = list[i];
			}
			delete[] list;
			tail = amount - 1;
			list = temp;
		}
		T* get_new_T(size_t length){
			try
			{		
				return new T[length];
			}
			catch (std::bad_alloc)
			{
				std::cerr << "Memory Allocation Failed "<< std::endl;
			}
			return 0;
		}



	};
}//end namespace
#endif
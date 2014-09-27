#ifndef _CDAL_H_
#define _CDAL_H_

/*
Skeleton created by Dave Small

Methods and Logic Written by Joshua Kegley
*/

#include <iostream>

namespace cop3530 {

	template <typename T>
	class CDAL {
	private:
		struct Node{
			T data[50];
			Node * next = NULL;
			int arrayTail = 0;
		};
		Node * head;
		Node * tail;
		int amount;
		int nodeAmount;

	public:
		class CDAL_Iter //: public std::iterator<std::forward_iterator_tag, T>
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
			typedef CDAL_Iter self_type;
			typedef CDAL_Iter& self_reference;

		private:
			Node * node;
			T * here;
			int i = 0;

		public:
			explicit CDAL_Iter(Node * head = NULL, T * start = NULL) : here(start), node(head) {}
			CDAL_Iter(const CDAL_Iter& src) : here(src.here), node(src.node) {}

			reference operator*() const { return *here; }
			pointer operator->() const { return here; }
			self_reference operator=(const CDAL_Iter& src) {
				delete this;
				*this = src;
			}//done

			self_reference operator++() {
				++i;
				if (i == 50 && node->next != NULL){
					node = node->next;
					here = &node->data[0];
					i = 0;
				}
				else{
					++here;
				}
				return *this;
			} // preincrement
			self_type operator++(int) {
				CDAL_Iter temp(*this);
				++i;
				if (i == 50 && node->next != NULL){
					node = node->next;
					here = &node->data[0];
					i = 0;
				}
				else{
					++here;
				}
				return temp;
			} // postincrement

			bool operator==(const CDAL_Iter& rhs) const {
				if (here == rhs.here){
					return true;
				}
				return false;
			}//done
			bool operator!=(const CDAL_Iter& rhs) const {
				if (here != rhs.here){
					return true;
				}
				return false;
			}
		}; // end CDAL_Iter 


	public:
		class CDAL_Const_Iter //: public std::iterator<std::forward_iterator_tag, T>
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
			typedef CDAL_Const_Iter self_type;
			typedef CDAL_Const_Iter& self_reference;

		private:
			const Node * node;
			const T * here;
			int i = 0;

		public:
			explicit CDAL_Const_Iter(Node * head = NULL, T * start = NULL) : here(start), node(head) {}
			CDAL_Const_Iter(const CDAL_Const_Iter& src) : here(src.here), node(src.node) {}

			reference operator*() const { return *here; }//done
			pointer operator->() const { return here; }//done

			self_reference operator=(const CDAL_Const_Iter& src) {
				delete this;
				*this = src;
			}//done

			self_reference operator++() {
				++i;
				if (i == 50 && node->next != NULL){
					node = node->next;
					here = &node->data[0];
					i = 0;
				}
				else{
					++here;
				}
				return *this;
			} // preincrement//done
			self_type operator++(int) {
				CDAL_Const_Iter temp(*this);
				++i;
				if (i == 50 && node->next != NULL){
					node = node->next;
					here = &node->data[0];
					i = 0;
				}
				else{
					++here;
				}
				return temp;
			} // postincrement//done

			bool operator==(const CDAL_Const_Iter& rhs) const {
				if (here == rhs.here){
					return true;
				}
				return false;
			}//done

			bool operator!=(const CDAL_Const_Iter& rhs) const {
				if (here != rhs.here){
					return true;
				}
				return false;
			}
		}; // end CDAL_Iter 

		//--------------------------------------------------
		// types
		//--------------------------------------------------

		typedef std::size_t size_t;
		typedef T value_type;
		typedef CDAL_Iter iterator;
		typedef CDAL_Const_Iter const_iterator;

		//--------------------------------------------------
		// Iterator Begin & Begin Helpers
		//--------------------------------------------------

		iterator begin() { return CDAL_Iter(head, &head->data[0]); }
		iterator end() { return CDAL_Iter(tail, &tail->data[tail->arrayTail]); }

		const_iterator begin() const { return CDAL_Const_Iter(head, &head->data[0]); }
		const_iterator end() const { return CDAL_Const_Iter(tail, &tail->data[tail->arrayTail]); }


		CDAL() {
			head = new Node;
			tail = head;
			nodeAmount = 1;
			amount = 0;
		}

		CDAL(const CDAL& src){ *this = src; }

		~CDAL() {
		}


		CDAL& operator=(const CDAL& src) {
			if (&src == this){ // check for self-assignment
				return *this;     // do nothing
			}
			// safely dispose of this CDAL's contents
			// populate this CDAL with copies of the other CDAL's contents
			clear();
			for (int i = 0; i < (int)src.size(); ++i){
				push_back(src.item_at(i));
			}
			return *this;
		}


		//Replaces orginal element with specified element, returns orginal
		T replace(const T& element, int position) {
			if (position > amount - 1 || position < 0){
				throw std::domain_error("Domain Error: Position doesn't exist");
			}
			int nodePosition = position / 50;
			int arrayPosition = position % 50;
			T data;
			Node * temp = head;
			for (int i = 0; i < nodePosition; ++i){
				temp = temp->next;
			}
			data = temp->data[arrayPosition];
			temp->data[arrayPosition] = element;
			return data;
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
						if (j < 50){
							prev->data[j] = prev->data[j - 1];
						}
					}

					temp = get_node(i - 1);
					if (i == 1){
						temp->data[0] = element;
						if (head->arrayTail < 49){
							++head->arrayTail;
						}
						else{
							++tail->arrayTail;
						}
					}
					else{
						prev->data[0] = temp->data[49];
					}
				}
			}
			////////////////////////////FOR ENTERING AT TAIL//////////////////////////////////
			else if (position == amount){
				temp->data[position % 50] = element;
				++temp->arrayTail;
			}
			////////////////////////////FOR ENTERING ELSE WHERE//////////////////////////////////

			else{
				int nodePosition = position / 50;
				int arrayPosition = (position % 50);
				//std::cout << nodePosition << ">>>" << arrayPosition << std::endl;


				for (int i = nodeAmount; i > nodePosition; --i){
					//std::cout << temp << std::endl;
					prev = temp;
					if (i - 1 != nodePosition){
						for (int i = temp->arrayTail; i > 0; --i){
							temp->data[i] = temp->data[i - 1];
						}
					}
					else{
						for (int i = temp->arrayTail; i > arrayPosition; --i){
							if (i < 50){
								temp->data[i] = temp->data[i - 1];
							}
						}
						temp->data[arrayPosition] = element;

					}
					if (temp == tail){ ++temp->arrayTail; }
					temp = get_node(i - 1);
					if (i - 1 == nodePosition){}
					else{
						prev->data[0] = temp->data[49];
					}

				}


			}


			++amount;

		}

		//pushes element to the front of the list
		void push_front(const T& element) {
			insert(element, 0);
		}

		//pushes elemets to the back
		void push_back(const T& element) {
			insert(element, amount);
		}

		//pops the first element, assigns pointer to temp, replaces head with the next value
		T pop_front() {
			return remove(0);
		}

		//pops elements off the back, moves tail to the previous element
		T pop_back() {
			return remove(amount - 1);
		}

		//Removes an element from the list, from specified location
		T remove(int position) {
			int nodePosition = position / 50;
			int arrayPosition = position % 50;
			T data;
			Node * prev;
			Node * temp = get_node(nodePosition + 1);
			//std::cout << temp << std::endl;
			data = temp->data[arrayPosition];
			for (int i = nodePosition; i < nodeAmount; ++i){
				prev = temp;
				if (i == nodePosition){
					//std::cout << "First Node, Position: " << arrayPosition << std::endl;
					for (int j = arrayPosition; j < 49; ++j){
						prev->data[j] = prev->data[j + 1];
					}
				}
				else{
					temp = temp->next;
					//std::cout << "Node After: " << temp << std::endl;
					//prev->data[49] = temp->data[0];
					for (int j = 0; j < 49; ++j){
						if (j == 0){
							prev->data[49] = temp->data[0];
						}
						temp->data[j] = temp->data[j + 1];
					}

				}

			}

			--amount;
			tail = get_node((amount / 50) + 1);
			--tail->arrayTail;
			if (tail->arrayTail == 0){
				tail = get_node(amount / 50);
			}
			if (amount <= (nodeAmount * 50) / 2){
				shrink();
			}

			return data;
		}

		//Looks at item at position
		T item_at(int position) const {
			int nodePosition = position / 50;
			int arrayPosition = position % 50;
			T data;
			Node * temp = head;
			for (int i = 0; i < nodePosition; ++i){
				temp = temp->next;
			}
			data = temp->data[arrayPosition];
			return data;
		}

		//Checks for emptiness
		bool is_empty() const { return (amount == 0 ? true : false); }
		//done

		//checks for size
		size_t size() const { return amount; }
		//done

		//clears list
		void clear() {
			Node * temp = head;
			for (int i = 0; i < nodeAmount; ++i){
				head = head->next;
				delete temp;
				temp = head;
			}
			head = new Node;
			tail = head;
			amount = 0;
			nodeAmount = 1;

		}

		bool contains(const T& element,
			bool equals(const T& a, const T& b)) const {

		}

		std::ostream& print(std::ostream& out) const {
			Node * temp = head;
			std::cout << std::endl << std::endl;
			std::cout << "Nodes: " << nodeAmount << std::endl;
			std::cout << "Amount: " << amount << std::endl;
			std::cout << "Max Size: " << nodeAmount * 50 << std::endl;
			std::cout << "head: " << head << std::endl;
			std::cout << "tail: " << tail << std::endl;
			out << "0[";
			for (int i = 0; i < amount; ++i){
				if (i != 0 && i % 50 == 0){
					out << "]" << std::endl << std::endl << i / 50 << "Node: " << temp << "[";
					temp = temp->next;
				}
				out << temp->data[i % 50] << " ";
			}
			out << "]";
			return out;
		}

	private:

		bool is_full(){
			return (amount == 50 * nodeAmount) ? true : false;
		}

		void grow(){
			tail->next = new Node;
			tail = tail->next;
			++nodeAmount;
		}

		void shrink(){
			std::cout << "SHRINKING" << std::endl;
			Node * temp = get_node(nodeAmount);
			for (int i = nodeAmount - 1; i > ((nodeAmount / 2) + 1); --i){
				std::cout << "Temp: ";
				std::cout << temp << std::endl;
				delete temp;

				temp = get_node(--nodeAmount);
			}
			tail = get_node((nodeAmount));
		}

		Node* get_node(int position){
			Node * next = head;
			for (int i = 1; i < position; ++i){
				next = next->next;
			}
			return next;
		}

	};
}
#endif;
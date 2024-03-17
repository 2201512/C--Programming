/*!*************************************************************************
****
\file dllist.cpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: HLP2
\par Section: nil
\par Ass 06
\date 02-03-2023
\brief
This program is the source file for functions used in dllist-driver-cpp. The functions include:
- construct_node, destruct_node, ctor, dtor,
size, push_front, push_back, find, insert, remove_first, copy assignment and copy constructor
and operator overloading
    produces a linked list and allows for modification of it
****************************************************************************
***/
#include <iostream>
#include <iomanip>
#include "dllist.h"

namespace hlp2 {
    /**************************************************************************/
    /*!
      \brief
        constructs a new list CTOR
      
      \param nil
      
      \return nil
        
    */
    /**************************************************************************/
	dllist::dllist() :
		head(nullptr),
		
		tail(nullptr)
	{}
    /**************************************************************************/
    /*!
      \brief
        destroy a list Dtor
      
      \param nil
      
      \return nil
        
    */
    /**************************************************************************/
	dllist::~dllist()
	{
		
		node* current = head;
		
		while (current != nullptr) {
			
			node* next = current->next;
			
			delete current;
			
			current = next;
		}
		
		head = nullptr;
		tail = nullptr;
		
	}

	/**************************************************************************/
    /*!
      \brief
        find the size of dllist
      
      \param nil
       
      
      \return size_t
        size of dllist
    */
    /**************************************************************************/
	size_t dllist::size() const
	{
		
		size_t count = 0;
		
		node* current = head;
		
		while (current != nullptr) {
			
			count++;
			
			current = current->next;
		}
		
		return count;
	}
     /**************************************************************************/
    /*!
      \brief
        print values in nodes
      
      \param nil
        
        
      \return void
        nil
    */
    /**************************************************************************/
	void dllist::print() const
	{
		node const* l_pCur = head;
		while (l_pCur) {
			std::cout << l_pCur->value << "    ";
			l_pCur = l_pCur->next;
		}
		std::cout << "\n";
	}

	/**************************************************************************/
    /*!
      \brief
        constructs a copy CTOR
      
      \param dllist const& other
        copyying para
      
      \return dllist::dllist
        return copy value
        
    */
    /**************************************************************************/
	dllist::dllist(dllist const& other) :
		head(nullptr),
		tail(nullptr)
	{
		
		if (other.head == nullptr) {
			return;
		}

		
		node const* current = other.head;
		
		while (current != nullptr) {
			
			push_back(current->value);
			
			current = current->next;
		}
	}
	
	/**************************************************************************/
    /*!
      \brief
        constructs a copy CTOR to assign
      
      \param dllist const& other
        copyying para
      
      \return dllist::dllist
        return copy value
        
    */
    /**************************************************************************/
	dllist& dllist::operator=(dllist const& other)
	{
		
		if (this != &other) {
			
			node* curr = head;
			
			while (curr != nullptr) {
				
				node* temp = curr;
				
				curr = curr->next;
				
				delete temp;
			}
			
			head = tail = nullptr;

			
			node* other_curr = other.head;
			
			while (other_curr != nullptr) {
				
				push_back(other_curr->value);
				
				other_curr = other_curr->next;
			}
		}
		
		return *this;
	}



	/**************************************************************************/
    /*!
      \brief
        operator overlord ==
      
      \param dllist const& other
        params to check
      
      \return dllist::dllist
        return BOOL TRUE OR FALSE
        
    */
    /**************************************************************************/
	bool operator==(dllist const& lhs, dllist const& rhs) {
		
		if (&lhs == &rhs) {
			return true;
		}

		
		if (lhs.size() != rhs.size()) {
			return false;
		}

		
		dllist::node const* currentLhs = lhs.head;
		
		dllist::node const* currentRhs = rhs.head;
		
		while (currentLhs != nullptr) {
			
			if (currentLhs->value != currentRhs->value) {
				return false;
			}
			
			currentLhs = currentLhs->next;
			currentRhs = currentRhs->next;
		}
		
		return true;
	}

	/**************************************************************************/
    /*!
      \brief
        operator overload+
      
      \param dllist const& other
        params to add
      
      \return dllist::dllist
        return added param
        
    */
    /**************************************************************************/
	dllist operator+(dllist const& lhs, dllist const& rhs) {
		
		dllist result = lhs;
		
		dllist::node const* current = rhs.head;
		
		while (current != nullptr) {
			
			result.push_back(current->value);
			
			current = current->next;
		}
		
		return result;
	}

	/**************************************************************************/
    /*!
      \brief
        operator overload+=
      
      \param dllist const& other
        params to add
      
      \return dllist::dllist
        return reference added param
        
    */
    /**************************************************************************/
	dllist& dllist::operator+=(dllist const& rhs)
	{
		
		if (&rhs == this) {
			
			dllist copy = rhs;
			
			return *this += copy;
		}
		
		if (rhs.head == nullptr) {
			
			return *this;
		}
		
		if (head == nullptr) {
			
			head = new node{ nullptr, rhs.head->value, nullptr };
			tail = head;
			
			node* rhs_curr = rhs.head->next;
			
			while (rhs_curr != nullptr) {
				
				node* new_node = new node{ tail, rhs_curr->value, nullptr };
				
				tail->next = new_node;
				
				tail = new_node;
				
				rhs_curr = rhs_curr->next;
			}
			
			return *this;
		}
		
		node* curr = tail;
		
		node* rhs_curr = rhs.head;
		
		while (rhs_curr != nullptr) {
			
			node* new_node = new node{ curr, rhs_curr->value, nullptr };
			
			curr->next = new_node;
			
			curr = new_node;
			
			rhs_curr = rhs_curr->next;
		}
		
		tail = curr;
		
		return *this;
	}




	
	
	/**************************************************************************/
    /*!
      \brief
        operator overload-
      
      \param 
        no params due to using object itself
      
      \return dllist::dllist
        return  subtracted param
        
    */
    /**************************************************************************/
	dllist const dllist::operator-() const {
		
		dllist result = *this;
		
		node* current = result.head;
		
		while (current != nullptr) {
			
			current->value = -current->value;
			
			current = current->next;
		}
		
		return result;
		
	}

	
	/**************************************************************************/
    /*!
      \brief
        operator overload--
      
      \param 
        no params due to using object itself
      
      \return dllist::dllist
        return  subtracted param
        
    */
    /**************************************************************************/
	dllist& dllist::operator--() {
		
		if (head == nullptr) {
			return *this;
		}
		
		if (head == tail) {
			
			delete head;
			
			head = nullptr;
			tail = nullptr;
			
			return *this;
		}
		
		node* current = head;
		
		while (current->next != tail) {
			
			current = current->next;
		}
		
		delete tail;
		
		tail = current;
		
		tail->next = nullptr;
		
		return *this;
	}
	
	/**************************************************************************/
    /*!
      \brief
        operator overload--
      
      \param 
        int, to specift order of operation
      
      \return dllist::dllist
        return  subtracted param
        
    */
    /**************************************************************************/
	dllist const dllist::operator--(int) {
		
		dllist result = *this;
		
		if (head == nullptr) {
			return result;
		}
		
		if (head == tail) {
			
			delete head;
			
			head = nullptr;
			tail = nullptr;
			
			return result;
		}
		
		node* current = head;
		
		while (current->next != tail) {
			
			current = current->next;
		}
		
		delete tail;
		
		tail = current;
		
		tail->next = nullptr;
		
		return result;
	}

	/**************************************************************************/
    /*!
      \brief
        operator overload[]
      
      \param 
        element of linked liset
      
      \return dllist::dllist
        return  reference to value in param index
        
    */
    /**************************************************************************/
	int& dllist::operator[](size_t index)
	{
		
		if (index >= size()) {
			
			throw std::out_of_range("Index out of bounds");
		}

		
		node* current = head;
		
		for (size_t i = 0; i < index; ++i) {
			
			current = current->next;
		}

		
		return current->value;
	}
	/**************************************************************************/
    /*!
      \brief
        operator overload[] of const
      
      \param 
        element of linked liset
      
      \return dllist::dllist
        return  reference to value in param index
        
    */
    /**************************************************************************/
	int const& dllist::operator[](size_t index) const
	{
		
		if (index >= size()) {
			
			throw std::out_of_range("Index out of bounds");
		}

		
		node* current = head;
		
		for (size_t i = 0; i < index; ++i) {
			
			current = current->next;
		}

		
		return current->value;
	}

	
	
	/**************************************************************************/
    /*!
      \brief
        print
      
      \param std::ostream& os, dllist const& list
        printing list and stream object
      
      \return std::ostream&
        reference to ostream
        
    */
    /**************************************************************************/
	std::ostream& operator<<(std::ostream& os, dllist const& list) {
		
		list.print();
		
		return os;
	}
	
	/**************************************************************************/
    /*!
      \brief
        make new node right after head
      
        
      \param int value
        value to store in new node
            
      \return void
        nil
    */
    /**************************************************************************/
	void hlp2::dllist::push_front(int value) {
		
		node* newNode = new node{ nullptr, value, nullptr };
		
		if (!head) {
			head = tail = newNode;
		}
		else {
			
			head->prev = newNode;
			
			newNode->next = head;
			
			head = newNode;
		}
	}



	/**************************************************************************/
    /*!
      \brief
        pop a node infront
      
        
      \param int value
        void
            
      \return void
        nil
    */
    /**************************************************************************/
	void dllist::pop_front() {
		
		if (head == nullptr) {
			return;
		}
		
		else if (head == tail) {
			
			delete head;
			
			head = nullptr;
			tail = nullptr;
		}
		else {
			
			node* new_head = head->next;
			
			delete head;
			
			head = new_head;
			
			head->prev = nullptr;
		}
	}

	/**************************************************************************/
    /*!
      \brief
        make new node right before tail
      
      \param int value
        value to store in new node
            
      \return void
        nil
    */
    /**************************************************************************/
	void hlp2::dllist::push_back(int value) {
		
		node* new_node = new node{ tail, value, nullptr };
		
		if (tail != nullptr) {
			
			tail->next = new_node;
		}
		else {
			
			head = new_node;
		}
		
		tail = new_node;
	}



	/**************************************************************************/
    /*!
      \brief
        find node with specified value
      
      \param int value
        value to stored in  node
            
      \return node*
        return pointer to node
    */
    /**************************************************************************/
	hlp2::dllist::node* hlp2::dllist::find(int value) const {
		
		node* current = head;
		
		while (current != nullptr) {
			
			if (current->value == value) {
				return current;
			}
			
			current = current->next;
		}
		
		return nullptr;
	}

	/**************************************************************************/
    /*!
      \brief
        insert node insde linked list
      
      \param int value
        value to be stored
        
      \param size_t position
        location in linked list to store
        
      \return void
        nil
    */
    /**************************************************************************/
	void dllist::insert(int value, size_t position) {
		
		if (head == nullptr) {
			push_front(value);
			
			return;
		}
		
		else if (position == 0) {
			push_front(value);
			
			return;
		}
		
		node* current = head;
		
		for (size_t i = 0; i < position - 1; i++) {
			
			if (current->next == nullptr) {
				push_back(value);
				// return
				return;
			}
			
			current = current->next;
		}
		
		node* newNode = new node{ current, value, current->next };
		
		current->next = newNode;
		
		if (newNode->next != nullptr) {
			
			newNode->next->prev = newNode;
		}
		else {
			
			tail = newNode;
		}
	}

	/**************************************************************************/
    /*!
      \brief
        remove first node with specified value
        
      \param int value
        value to be check
        
      \return void
        nil
    */
    /**************************************************************************/
	void dllist::remove_first(int value) {
		
		if (head == nullptr) {
			return;
		}

		
		if (head->value == value) {
			
			pop_front();
			
			return;
		}
		
		node* current = head;
		
		while (current->next != nullptr) {
			
			if (current->next->value == value) {
				
				node* temp = current->next;
				
				current->next = current->next->next;
				
				if (current->next != nullptr) {
					
					current->next->prev = current;
				}
				else {
					
					tail = current;
				}
				
				delete temp;
				
				return;
			}
			
			current = current->next;
		}
	}

	/**************************************************************************/
    /*!
      \brief
        operator overload !=
      
        
      \param int value
        params to compare
            
      \return void
        bool TRUE or FALSE
    */
    /**************************************************************************/
	bool operator!=(dllist const& lhs, dllist const& rhs)
	{
		
		return !(lhs == rhs); 
	}
} 
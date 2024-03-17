/*!*************************************************************************
****
\file dllist.cpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: HLP2
\par Section: nil
\par Ass 05
\date 09-02-2023
\brief
This program is the source file for functions used in dllist-driver-cpp. The functions include:
- construct_node, destruct_node, ctor, dtor,
size, push_front, push_back, find, insert, remove_first, copy assignment and copy constructor
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
		// Initialize head and tail to nullptr
		head(nullptr),
		//TODO
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
		//TODO
		// Delete all nodes in the list
		
		node* current = head;
		while (current) {
			
			node* next = current->next;
			
			delete current;
			
			current = next;
		}
		
		head = tail = nullptr;
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
		//TODO
		
		size_t count = 0;
		
		node* current = head;
		
		while (current) {
			
			++count;
			
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
        find node with specified value
      
      \param int value
        value to stored in  node
            
      \return node*
        return pointer to node
    */
    /**************************************************************************/
	dllist::node* dllist::find(int value) const
	{
		
		node* curr = head;
		
		while (curr) {
			
			if (curr->value == value) {
				
				return curr;
			}
			
			curr = curr->next;
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
	void dllist::insert(int value, size_t position)
	{
		
		if (position > size()) {
			
			push_back(value);
		}
		
		else if (position == 0) {
			
			push_front(value);
		}
		else {
			
			node* curr = head;
			
			for (size_t i = 0; i < position; ++i) {
				
				curr = curr->next;
			}
			
			node* newNode = new node{ curr->prev, value, curr };
			
			curr->prev->next = newNode;
			
			curr->prev = newNode;
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
	void dllist::remove_first(int value)
	{
		
		node* curr = head;
		
		while (curr) {
			
			if (curr->value == value) {
				
				if (curr->prev) {
					
					curr->prev->next = curr->next;
				}
				
				else {
					
					head = curr->next;
				}
				
				if (curr->next) {
					
					curr->next->prev = curr->prev;
				}
				
				else {
					
					tail = curr->prev;
				}
				
				delete curr;
				
				break;
			}
			
			curr = curr->next;
		}
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
	void dllist::push_front(int value)
	{
		
		node* newNode = new node{ nullptr, value, head };
		
		if (head) {
			
			head->prev = newNode;
		}
		
		else { 
			
			tail = newNode;
		}
		
		head = newNode;
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
	void dllist::push_back(int value)
	{
		
		node* newNode = new node{ tail, value, nullptr };
		
		if (tail) {
			
			tail->next = newNode;
		}
		
		else {
			
			head = newNode;
		}
		
		tail = newNode;
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
	dllist::dllist(dllist const& other) : head(nullptr), tail(nullptr)
	{
		
		for (node* curr = other.head; curr; curr = curr->next) {
			
			push_back(curr->value);
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
			
			dllist copy(other);
			
			std::swap(head, copy.head);
			std::swap(tail, copy.tail);
		}
		
		return *this;
	}

	

} 
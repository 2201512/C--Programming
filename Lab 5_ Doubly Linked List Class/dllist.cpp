/*!*************************************************************************
****
\file dllist.cpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: HLP2
\par Section: nil
\par Ass 05
\date 04-02-2023
\brief
This program is the source file for functions used in dllist-driver-cpp. The functions include:
- construct_node, destruct_node, ctor, dtor,
size, push_front, push_back, find, insert, remove_first
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
        constructs a newe node
      
      \param int value
        value to be stored
        
      \param node* prev
        pointer to previous node
        
      \param node* next
        pointer to next node
      
      \return dllist::node
        pointer to newly constructed node
    */
    /**************************************************************************/
  	dllist::node* construct_node(int value, dllist::node* prev = nullptr, dllist::node* next = nullptr) 
	{
		return new dllist::node{ prev, value, next };
	}
	/**************************************************************************/
    /*!
      \brief
        delete node
      
      \param dllist::node* ptr_node
        pointer to node
      
      \return void 
        nil
    */
    /**************************************************************************/
	void destruct_node(dllist::node* ptr_node) 
	{
		delete ptr_node;
	}
	/**************************************************************************/
    /*!
      \brief
        constructs a new list CTOR
      
      \param nil
      
      \return nil
        
    */
    /**************************************************************************/
	dllist::dllist() :head(nullptr),tail(nullptr)
	{
	    //no input required for new as ctor does it automatically
	}
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
		/*if (!head) {
			return;
		}
		node* temp;
		for (node* current = head->next; current; current = temp) {
			temp = current->next;
			destruct_node(current);
			current = nullptr;
		}
		delete head;
	    head = nullptr;*/
	    
	    while (head != nullptr)
        {
          node* temp = head;
          head = head->next;
          delete temp;
        }

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
		size_t cnt = 0;
		for (node const* current = head; current; current = current->next) {
			cnt++;
		}
		return cnt;
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
		/*head = construct_node(value, nullptr, head);
		node* l_pHead = head;
		node* l_pNx = l_pHead->next;
		if (l_pNx)
			l_pNx->prev = l_pHead;
		if (!tail)
		    tail = l_pHead;*/
		 
		 /* node* newNode = new node();
          newNode->value = value;
          newNode->next = head;
          newNode->prev = nullptr;
          if (head != nullptr)
          {
            head->prev = newNode;
          }
          head = newNode;
          if (tail == nullptr)
          {
            tail = newNode;
          }*/
          node* newNode = new node;
      newNode->value = value;
      newNode->next = NULL;
      newNode->prev = NULL; 
      if(head == NULL) {
        head = newNode;
      } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
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
	void dllist::push_back(int value)
	{
		
		node* newLast = construct_node(value, nullptr, nullptr);
		node* last = tail;
		if (last) {
			last->next = newLast;
			newLast->prev = last;
			tail = newLast;
		}
		else {
			head = newLast;
			tail = newLast;
		}
	
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
	    
		node*  f = head;
		while (f) {
			if (f->value == value) {
				return f;
			}
			f = f->next;
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
		if (!head) return;
		node* nodeInsert = construct_node(value, nullptr, nullptr);
		node* start = head;
		size_t count = 0;
		if (!head) {
			push_front(value);
		}
		while (start) {
			if (count == position) {
				if (start->prev) {
					nodeInsert->prev = start->prev;
					nodeInsert->next = start;
					start->prev->next = nodeInsert;
					start->prev = nodeInsert;
				}
				else {
					head = nodeInsert;
					nodeInsert->next = start;
					start->prev = nodeInsert;
				}

				break;
			}
			count++;
			start = start->next;
			if (!start) {
				push_back(value);
			}
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
	    if(!head)
	    {
			return;
		}
		for (node* hea = head; hea; hea = hea->next) {
			if (hea->value == value) {
				if (hea->prev) hea->prev->next = hea->next;
				if (hea->next) hea->next->prev = hea->prev;
				if (head == hea) head = hea->next;
				delete hea;
				break;
			}
		}

	}

	//TODO: Rest of the member functions

} // end namespace hlp2
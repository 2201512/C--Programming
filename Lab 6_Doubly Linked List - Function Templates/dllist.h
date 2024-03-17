/*!*************************************************************************
****
\file dllist.h
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: HLP2
\par Section: nil
\par Lab 7
\date 23-02-2023
\brief
This program is the header file for functions used in dllist-driver-cpp. The functions include:
- construct_node, destruct_node, get_value, construct_list,destruct_list,
size, push_front, push_back, find, insert, remove, remove_first
    produces a linked list and allows for modification of it
****************************************************************************
***/
#ifndef DLLIST_H
#define DLLIST_H

#include <iostream>
#include <iomanip>
#include <iostream>

namespace hlp2 {

	/*******************************************************************************
	 * DATA TYPES
	 ******************************************************************************/
    template <typename T>
	struct node {
		node* prev; // pointer to previous node
		T value;  // data portion
		node* next; // pointer to next node
	};

    template <typename T>
	struct dllist {
		node<T> *head, *tail;
	};

	/*******************************************************************************
	 * HELPER FUNCTIONS
	 ******************************************************************************/

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
      
      \return node* 
        pointer to newly constructed node
        uses initalized template
    */
    /**************************************************************************/
    template<typename T>
	node<T>* construct_node(T value, node<T>* prev = nullptr, node<T>* next = nullptr) {
		return new node<T>{ prev, value, next };
	}

	/**************************************************************************/
    /*!
      \brief
        delete node
      
      \param node* ptr_node
        pointer to node
      
      \return void 
        nil
    */
    /**************************************************************************/
    template<typename T>
	void destruct_node(node<T>* ptr_node) {
		delete ptr_node;
	}

	/**************************************************************************/
    /*!
      \brief
        gets the value inside node
      
      \param node const* pn
        pointer to node of const
        
      \return int
        value stored in node
    */
    /**************************************************************************/
    template<typename T>
	int get_value(node<T> const* pn) {
		return pn->value;
	}
    /**************************************************************************/
    /*!
      \brief
        constructs a new list
      
      \param nil
      
      \return dllist* 
        pointer head of dllist
    */
    /**************************************************************************/
    template<typename T>
	dllist<T>* construct_list() {
		return new dllist<T>{ nullptr, nullptr };
	}

	/**************************************************************************/
    /*!
      \brief
        destroy a list
      
      \param dllist* ptr_dll
        pointer to head
      
      \return void
        nil
    */
    /**************************************************************************/
    template<typename T>
	void destruct_list(dllist<T>* ptr_dll) 
	{
	if (!ptr_dll) {
	  return;
	}
	node<T> *temp;
	for (node<T> *current = ptr_dll->head; current; current = temp) {
		temp = current->next;
		destruct_node<T>(current);
		current = nullptr;
  	}
	delete ptr_dll;
	ptr_dll = nullptr;
	}

	/**************************************************************************/
    /*!
      \brief
        find the size of dllist
      
      \param dllist* const ptr_dll
        pointer to head
      
      \return size_t
        size of dllist
    */
    /**************************************************************************/
    template<typename T>
	size_t size(dllist<T> const* ptr_dll) {
		size_t cnt = 0;
		for(node<T>* current = ptr_dll->head;current;current = current->next){
			cnt++;
		}
		return cnt;
	}

	/**************************************************************************/
    /*!
      \brief
        make new node right after head
      
      \param dllist* ptr_dll
        pointer to head
        
      \param int value
        value to store in new node
            
      \return void
        nil
    */
    /**************************************************************************/
    template<typename T>
	void push_front(dllist<T>* ptr_dll, T value) {
		if (!ptr_dll)
			return;
		ptr_dll->head = construct_node<T>(value, nullptr, ptr_dll->head);
		node<T>* l_pHead = ptr_dll->head;
		node<T>* l_pNx = l_pHead->next;
		if (l_pNx)
			l_pNx->prev=l_pHead;
		if (!ptr_dll->tail)
			ptr_dll->tail = l_pHead;
	}

	/**************************************************************************/
    /*!
      \brief
        make new node right before tail
      
      \param dllist* ptr_dll
        pointer to head
        
      \param int value
        value to store in new node
            
      \return void
        nil
    */
    /**************************************************************************/
    template<typename T>
	void push_back(dllist<T>* ptr_dll, T value) {
		if(!ptr_dll){
			return;
		}
		//(value, prev, next)
		node<T>* newLast = construct_node<T>(value, nullptr, nullptr);
		node<T>* last = ptr_dll->tail;
		if(last){
		last->next = newLast;
		newLast->prev = last;
		ptr_dll->tail = newLast;
		}else{
			ptr_dll->head = newLast;
			ptr_dll->tail = newLast;
		}
	}

	/**************************************************************************/
    /*!
      \brief
        print values in nodes
      
      \param dllist const* ptr_dll
        pointer to head
        
      \return void
        nil
    */
    /**************************************************************************/
    template<typename T>
	void print(dllist<T> const* ptr_dll) {
		node<T> const* head = ptr_dll->head;
		while (head) {
			std::cout << head->value << "    ";
			head = head->next;
		}
		std::cout << "\n";
	}

	
	/**************************************************************************/
    /*!
      \brief
        find node with specified value
      
      \param dllist* ptr_dll
        pointer to head
        
      \param int value
        value to stored in  node
            
      \return node*
        return pointer to node
    */
    /**************************************************************************/
    template<typename T>
	node<T>* find(dllist<T>* ptr_dll, T value) {
		node<T>* head = ptr_dll->head;
		while(head){
			if(head->value == value){
				return head;
			}
			head = head->next;
		}
		return nullptr;
	}
	
	/**************************************************************************/
    /*!
      \brief
        insert node insde linked list
      
      \param dllist const* ptr_dll
        pointer to head
        
      \param int value
        value to be stored
        
      \param size_t position
        location in linked list to store
        
      \return void
        nil
    */
    /**************************************************************************/
    template<typename T>
	void insert(dllist<T>* ptr_dll, T value, size_t position) {
		if(!ptr_dll) return;
		node<T>* nodeInsert = construct_node<T>(value, nullptr, nullptr);
		node<T>* head = ptr_dll->head;
		size_t count = 0;
		if(!ptr_dll->head){
			push_front<T>(ptr_dll,value);
		}
		while(head){
			if(count==position){
				//std::cout<<"count:"<<count<<" value"<<value<<std::endl;
				if(head->prev){
					nodeInsert->prev = head->prev;
					nodeInsert->next = head;
					head->prev->next = nodeInsert;
					head->prev = nodeInsert;
				}else{
					ptr_dll->head = nodeInsert;
					nodeInsert->next = head;
					head->prev = nodeInsert;
				}
				
				break;
			}
			count++;
			head = head->next;
			if(!head){
				push_back<T>(ptr_dll, value);
			}
		}
	}
	
	/**************************************************************************/
    /*!
      \brief
        remove first node with specified value
      
      \param dllist const* ptr_dll
        pointer to head
        
      \param int value
        value to be check
        
      \return void
        nil
    */
    /**************************************************************************/
    template<typename T>
	void remove_first(dllist<T>* ptr_dll, T value) {
	if (!ptr_dll->head) return;
	for (node<T>* head = ptr_dll->head; head; head = head->next) {
		if (head->value == value) {
			if (head->prev) head->prev->next = head->next;
			if (head->next) head->next->prev = head->prev;
			if (ptr_dll->head == head) ptr_dll->head = head->next;
			delete head;
			break;
		}
	}
}
	
} // end namespace hlp2

#endif
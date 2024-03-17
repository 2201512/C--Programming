/*!*************************************************************************
****
\file sllist.hpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: HLP2
\par Section: nil
\par Lab 04
\date 28-01-2023
\brief
This program header file for functions used in sllist.cpp. The functions include:
- data, next, construct, destruct, push_front, push_back,insert, remove_first,
    front, find, empty, size
    creates a linked list and functions to manupilate said linked list
****************************************************************************
***/
#ifndef SLLIST_HPP
#define SLLIST_HPP

#include <iostream>
#include <cstddef>

namespace hlp2{
    struct node;
    struct sllist;

    /*!*************************************************************************
    ****
    \brief
    accessor to node's data

    \param node const *p
    pointer to node

    \return int
    value of data
    ****************************************************************************
    ***/
    int data(node const *p);
    /*!*************************************************************************
    ****
    \brief
    change node data

    \param node const *p
    pointer to node
    
    \param int newvak
    new value to be stoed
    
    \return void
    nil
    ****************************************************************************
    ***/
    void data(node *p, int newval); 
    /*!*************************************************************************
    ****
    \brief
    points to next node

    \param node  *p
    pointer to node
    
    \return node*
    pointer to next node
    ****************************************************************************
    ***/
    node* next(node *p);
    /*!*************************************************************************
    ****
    \brief
    points to next node

    \param node const *p
    pointer to node
    
    \return node* const* 
    pointer to next node
    ****************************************************************************
    ***/
    node const* next(node const *p); 

    /**************************************************************************/
    /*!
    \brief
    contructs a new linked list
      
    \return sllist* 
    pointer to new head
    */
    /**************************************************************************/
    sllist* construct();

    /**************************************************************************/
    /*!
    \brief
    destroys linked list
        
    \param sllist *ptr_sll
    pointer of linked list to destroy
      
    \return void
    nil
    */
    /**************************************************************************/
    void destruct(sllist *ptr_sll);

    /**************************************************************************/
    /*!
    \brief
    put a new node at the front
        
    \param sllist *ptr_sll
    pointer of linked list to insert new node
      
    \param int value
    value to store
      
    \return void
    nil
    */
    /**************************************************************************/
    void push_front(sllist *ptr_sll, int value);

    /**************************************************************************/
    /*!
    \brief
    put a new node at the front
        
    \param sllist *ptr_sll
    pointer of linked list to insert new node
      
    \param int value
    value to store
      
    \return void
    nil
    */
    /**************************************************************************/
    void push_back(sllist *ptr_sll, int value);

    /**************************************************************************/
    /*!
    \brief
    put a new node at a specified location
        
    \param sllist *ptr_sll
    pointer of linked list to insert new node
      
    \param size_t index
    index of location to make new node
      
    \param int value
    value to store
      
    \return void
    nil
    */
    /**************************************************************************/
    void insert(sllist *ptr_sll, int value, size_t index);

    /**************************************************************************/
    /*!
    \brief
    remove first instance of node with specified value
        
    \param sllist *ptr_sll
    pointer of linked list to remove new node
      
      
    \param int value
    value to check
      
    \return void
    nil
    */
    /**************************************************************************/
    void remove_first(sllist *ptr_sll, int value);

    /**************************************************************************/
    /*!
    \brief
    get the front of linked list
        
    \param sllist *ptr_sll
    pointer of linked list 
      
    \return node*
    node at front
    */
    /**************************************************************************/
    node* front(sllist *ptr_sll);

    /**************************************************************************/
    /*!
    \brief
    get the front of linked list
        
    \param sllist *ptr_sll
    pointer of linked list 
      
    \return node*
    node at front
    */
    /**************************************************************************/
    node const* front(sllist const *ptr_sll);

    /**************************************************************************/
    /*!
    \brief
    find node with specified value
        
    \param sllist *ptr_sll
    pointer of linked list
        
    \param int value
    value to find
      
    \return node*
    node found
    */
    /**************************************************************************/
    node* find(sllist const *ptr_sll, int value);

    /**************************************************************************/
    /*!
    \brief
    check if linked list empty
        
    \param sllist *ptr_sll
    pointer of linked list
      
    \return bool
    true or false for finding
    */
    /**************************************************************************/
    bool empty(sllist const *ptr_sll);

     /**************************************************************************/
    /*!
    \brief
    find size of linked list
        
    \param sllist *ptr_sll
    pointer of linked list
      
    \return size_t 
    size of linked list
    */
    /**************************************************************************/
    size_t size(sllist const *ptr_sll);

}


#endif
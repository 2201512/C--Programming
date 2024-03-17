/*!*************************************************************************
****
\file sllist.cpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: HLP2
\par Section: nil
\par Lab 04
\date 28-01-2023
\brief
This program is the source file for functions used in sllist.cpp. The functions include:
- data, next, construct, destruct, push_front, push_back,insert, remove_first,
    front, find, empty, size
    creates a linked list and functions to manupilate said linked list
****************************************************************************
***/
#include "sllist.hpp"

namespace hlp2{
    struct node{
        int value;
        node *next;
    };
    struct sllist{
        node *head;
    };


}
namespace{
    /**************************************************************************/
    /*!
    \brief
    takes in a value and pointer and creates a node
      
    \param int value
    value to be stored
        
    \param hlp2::node *next
    where node points to
      
    \return  hlp2::node*
    node location
    */
    /**************************************************************************/
    hlp2::node* create_node(int value, hlp2::node *next = nullptr);
    hlp2::node* create_node(int value, hlp2::node* next) {
        return new hlp2::node {value, next};
    }
}


namespace hlp2{

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
    int         data(node const *p){return p->value;} 
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
    void        data(node *p, int newval){p->value = newval;} 
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
    node*       next(node *p){return p->next;}
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
    node const* next(node const *p){return p->next;} 

    /**************************************************************************/
    /*!
    \brief
    contructs a new linked list
      
    \return sllist* 
    pointer to new head
    */
    /**************************************************************************/
    sllist* construct(){
        return new sllist{nullptr};
    }

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
    void destruct(sllist *ptr_sll){
        node* head = ptr_sll->head, *next;
        while(head){
            next = head->next;
            delete head;
            head = next;
        }
        delete ptr_sll;
    }

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
    void push_front(sllist *ptr_sll, int value){
        ptr_sll->head = create_node(value, ptr_sll->head);
    }

    /**************************************************************************/
    /*!
    \brief
    put a new node at the back
    
    \param sllist *ptr_sll
    pointer of linked list to insert new node
      
    \param int value
    value to store
      
    \return void
    nil
    */
    /**************************************************************************/
    void push_back(sllist *ptr_sll, int value){
        if(empty(ptr_sll)){
            push_front(ptr_sll, value);
        }
        else{
            node*head = ptr_sll->head;
            while(head->next){
                head = head->next;
            }
            head->next = create_node(value);
        }
    }

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
    void insert(sllist *ptr_sll, int value, size_t index){
        //start from zero
        if(index == 0){
            push_front(ptr_sll, value);
            return;
        }
        node* head = ptr_sll->head;
        while(--index && head->next){
            head = head->next;
        }
        head->next = create_node(value, head->next);
    }

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
    void remove_first(sllist *ptr_sll, int value){
        //empty list
        if(empty(ptr_sll))return;
        //delete first
        node* head = ptr_sll->head;
        if(head->value == value){
            ptr_sll->head = head->next;
            delete head;
            return;
        }
        while(head->next){
            if(head->next->value == value){
                node*temp = head->next;
                head->next = temp->next;
                delete temp;
                break;;
            }
            head = head->next;
        }
    }


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
    node* front(sllist *ptr_sll){return ptr_sll->head;}

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
    node const* front(sllist const *ptr_sll){return ptr_sll->head;}

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
    node* find(sllist const *ptr_sll, int value){
        node* head = ptr_sll->head;
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
    check if linked list empty
        
    \param sllist *ptr_sll
    pointer of linked list
      
    \return bool
    true or false for finding
    */
    /**************************************************************************/
    bool empty(sllist const *ptr_sll){
        return ptr_sll->head ? false : true;
    }

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
    size_t size(sllist const *ptr_sll){
        size_t cnt {};
        for (node *head = ptr_sll->head; head; head = next(head)) {
            ++cnt;
        }
        return cnt;
    }
}
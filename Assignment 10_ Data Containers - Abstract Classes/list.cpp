/*!*************************************************************************
****
\file list.cpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: HLP2
\par Section: nil
\par Ass 10
\date 02-04-2023
\brief
This program is source file for sllist into dllist
****************************************************************************
***/
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <array>
#include "list.h"

namespace hlp2 
{
/**************************************************************************/
/*!
  \brief
    constructs a new node
  
  \param nil
  
  \return nil
    
*/
/**************************************************************************/
sllist::slnode::slnode(int value, slnode* next) : value(value), next(next) {}


/**************************************************************************/
/*!
  \brief
    constructs a new list CTOR
  
  \param nil
  
  \return nil
    
*/
/**************************************************************************/
sllist::sllist() : head(nullptr) {}

/**************************************************************************/
/*!
  \brief
    acting as a  Dtor
  
  \param nil
  
  \return nil
    
*/
/**************************************************************************/
void sllist::clear() 
{
    while (head) 
    {
        slnode* temp = head;
        head = head->next;
        delete temp;
    }
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
sllist::sllist(sllist const& other) : head(nullptr) 
{
    // Copy nodes from other list
    slnode* curr = other.head;
    slnode* prev = nullptr;
    while (curr != nullptr) 
    {
        slnode* newNode = new slnode(curr->value);
        if (prev == nullptr) 
        {
            head = newNode; // The new node is the head of the list
        } 
        else 
        {            
            prev->next = newNode; // Add the new node after the previous node
        }
        prev = newNode;
        curr = curr->next;
    }
}


/**************************************************************************/
/*!
  \brief
    destroy a list Dtor
  
  \param nil
  
  \return nil
    
*/
/**************************************************************************/
sllist::~sllist() 
{
    clear(); // delete all nodes in the list
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
sllist& sllist::operator=(sllist const& other) 
{
    if (this != &other) 
    {
        // Delete nodes from current list
        slnode* curr = head;
        while (curr != nullptr) 
        {
            slnode* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
        
        // Copy nodes from other list
        curr = other.head;
        while (curr != nullptr) 
        {
            push_back(curr->value);
            curr = curr->next;
        }
    }
    return *this;
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
size_t sllist::size() const 
{
    size_t count = 0;
    slnode* curr = head;
    while (curr != nullptr) 
    {
            ++count;
        curr = curr->next;
    }
    return count;
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
void sllist::push_front(int value) 
{
    head = new slnode(value, head);
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
void sllist::pop_front()
{
    // Check if there is a head node
    if (head == nullptr) 
    {
        return; // no elements to remove
    }
    slnode* temp = head; // Save the current head node
    head = head->next; // Update the head node to the next node in the list

    delete temp; // Delete the previous head node
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
void sllist::push_back(int value)
{
    slnode* new_node = new slnode(value); // Create a new node with the given value
    
    // If the list is empty, set the new node as the head
    if (head == nullptr) 
    {
        head = new_node;
    } 
    // Otherwise, traverse the list to find the last node and set its next pointer to the new node
    else 
    {
        slnode* temp = head;
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}


/**************************************************************************/
/*!
  \brief
    print llist
  
  \param void
    nil
        
  \return void
    nil
*/
/**************************************************************************/
void sllist::print() const
{
    slnode const* curr = head; // Start at the head of the list

    // Traverse the list and print each element's value
    while (curr) 
    {
        std::cout << curr->value << "    ";
        curr = curr->next;
    }
    std::cout << "\n"; // Print a new line character to end the output
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
sllist::slnode* sllist::find(int value) const // Find the first occurrence of an integer value in the linked list
{
    slnode* temp = head; // Start from the head of the linked list
    while (temp != nullptr && temp->value != value) // Iterate through the linked list until either the end is reached or the value is found
    { 
        temp = temp->next;
    }
    return temp; // Return a pointer to the node containing the value or nullptr if the value is not found
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
void sllist::insert(int value, size_t position)
{
    slnode* new_node = new slnode(value); // Create a new node with the given value

    // If position is 0, insert new node at the head of the list
    if (position == 0) 
    {
        new_node->next = head;
        head = new_node;
    } 

    else 
    {
        slnode* temp = head;
        // Traverse the list until the previous node of the specified position is found or end of list
        for (size_t i = 0; i < position - 1 && temp != nullptr; i++) 
        {
            temp = temp->next;
        }
        // If the previous node is not found, insert the new node at the end of the list
        if (temp == nullptr) 
        {
            push_back(value);
        } 
        else 
        {
            // Insert the new node between the previous and current node at the specified position
            new_node->next = temp->next;
            temp->next = new_node;
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
void sllist::remove_first(int value)
{
    // Initialize pointers to traverse list
    slnode* temp = head; // current node to check
    slnode* prev = nullptr; // previous node

    // Traverse the list until value is found or reach the end
    while (temp != nullptr && temp->value != value) 
    {
        prev = temp;
        temp = temp->next;
    }

    // If value is found, remove it
    if (temp != nullptr) 
    {
        if (prev != nullptr) // If the element is not the first one
        { 
            prev->next = temp->next; // point the previous node to the next node
        } 
        else // If the element is the first one
        { 
            head = temp->next; // update head pointer
        }
        delete temp; // free the memory of the node
    }
}



/**************************************************************************/
/*!
  \brief
    constructs a new node
  
  \param nil
  
  \return nil
    
*/
/**************************************************************************/
dllist::dlnode::dlnode(dlnode* prev, int value, dlnode* next) : slnode(value, next), prev(prev) {}



/**************************************************************************/
/*!
  \brief
    constructs a new list CTOR
  
  \param nil
  
  \return nil
    
*/
/**************************************************************************/
dllist::dllist() : sllist(), tail(nullptr) {}

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
dllist::dllist(dllist const& other) : sllist(other), tail(nullptr) // call base class constructor and initialize tail to nullptr
{
    // Iterate over the other list and add each node to this list
    for (dlnode* node = static_cast<dlnode*>(other.head); node != nullptr; node = static_cast<dlnode*>(node->next)) 
    {
        push_back(node->value); // call push_back function to add node to the end of the list
    }
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
    // Delete nodes starting from the head
    while (head != nullptr) 
    {
        dlnode* node = static_cast<dlnode*>(head->next); // Set node to the next node of head
        delete head; // Delete head
        head = node; // Set head to the next node
    }
    tail = nullptr; // Update tail to null
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
    // Check for self-assignment
    if (this != &other) {
        dllist temp(other); // Create a temporary list with a copy of the other list

        // Swap the head and tail pointers of the current and temporary lists
        std::swap(head, temp.head);
        std::swap(tail, temp.tail);
    }
    return *this; // Return a reference to the current list
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
    dlnode* new_node = new dlnode(nullptr, value, static_cast<dlnode*>(head)); // Create a new node with a null prev pointer, the given value, and the current head as its next pointer

    if (head != nullptr)
    {
        static_cast<dlnode*>(head)->prev = new_node; // If the list is not empty, set the prev pointer of the old head node to the new node
    }
    else
    {
        tail = new_node; // If the list is empty, set the tail pointer to the new node
    }
    head = new_node;  // Set the head pointer to the new node
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
void dllist::pop_front()
{
    if (head == nullptr)
    {
    // The list is empty, there is no node to remove
    return;
    }
    // Store a pointer to the old head node
    dlnode* old_head = static_cast<dlnode*>(head);
    
    if (old_head->next != nullptr)
    {
        static_cast<dlnode*>(old_head->next)->prev = nullptr; // If the old head has a next node, update its prev pointer to null
    }
    else
    {
        tail = nullptr; // If the old head was the only node in the list, update tail pointer to null
    }
    head = old_head->next; // Update the head pointer to the second node
    
    delete old_head; // Delete the old head node

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
    dlnode* new_node = new dlnode(tail, value, nullptr); // Create a new node with a previous pointer to the current tail and a null next pointer
    
    if (tail == nullptr)
    {
        head = tail = new_node; // If the list is empty, set both the head and tail pointers to the new node
    }
    else
    {
        // If the list is not empty, set the next pointer of the current tail to the new node and update the tail pointer to the new node
        tail->next = new_node;
        tail = new_node;
    }
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
void dllist::insert(int value, size_t index) 
{
    if (index == 0) 
    {
        push_front(value); // If the index is 0, insert the new node at the front of the list
    } 
    else 
    {
        // Traverse the list to find the node at the index
        dlnode* current = static_cast<dlnode*>(head);
        size_t current_index = 0;
        while (current != nullptr && current_index < index - 1) 
        {
            current = static_cast<dlnode*>(current->next);
            current_index++;
        }
        if (current != nullptr) 
        {
            current->next = new dlnode(current, value, static_cast<dlnode*>(current->next)); // If the node at the index exists, insert the new node after it
                if (static_cast<dlnode*>(current->next->next) != nullptr) 
                {
                    static_cast<dlnode*>(current->next->next)->prev = static_cast<dlnode*>(current->next); // If the new node is not the last node, update its next node's prev pointer
                }
                else 
                {
                    tail = static_cast<dlnode*>(current->next); // If the new node is the last node, update the tail pointer
                }
        } 
        else 
        {
            push_back(value); // If the index is greater than the size of the list, insert the new node at the back
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
    if (head != nullptr) 
    {
        if (head->value == value)  // Check if the value to remove is at the head of the list
        {
            pop_front();
        } 
        else 
        {
            // Traverse the list to find the node with the value to remove
            dlnode* current = static_cast<dlnode*>(head);
            while (current->next != nullptr && current->next->value != value) {
                current = static_cast<dlnode*>(current->next);
            }
            if (current->next != nullptr) 
            {
                dlnode* temp = static_cast<dlnode*>(current->next); // Store a pointer to the node to be removed
                current->next = current->next->next; // Update the next pointer of the previous node to skip the removed node
                if (static_cast<dlnode*>(current->next) != nullptr) // Update the prev pointer of the new next node
                {
                    static_cast<dlnode*>(current->next)->prev = current;
                } 
                else 
                {
                    tail = current; // If the removed node was the last in the list, update the tail pointer
                }
                delete temp; // Delete the removed node
            }
        }
    }
}

} 
// end namespace hlp2

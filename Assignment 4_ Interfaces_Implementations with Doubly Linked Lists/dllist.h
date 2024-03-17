#ifndef DLLIST_H
#define DLLIST_H

namespace hlp2 {

	// Forward declarations of encapsulating data types
	struct dllist;
	struct node;

	// Constructs a new doubly-linked list
	dllist* construct_list();

	// Destroys an existing doubly-linked list
	void destruct_list(dllist* ptr_dll);

	// Returns int value encapsulated in object of type node
	// Clients can only deduce that a doubly-linked list consists of a sequence
	// of ordered nodes with each node containing an int data attribute
	int get_value(node const* pn);

	// Returns the count of elements in a doubly-linked list
	size_t size(dllist const* ptr_dll);

	// Adds a new value to beginning of a doubly-linked list
	void push_front(dllist* ptr_dll, int value);

	// Adds a new value to the end of a doubly-linked list
	void push_back(dllist* ptr_dll, int value);

	// Prints the contents of a doubly-linked list
	void print(dllist const* ptr_dll);

	// Find first occurrence in doubly-linked list with data attribute equivalent to value
	node* find(dllist* ptr_dll, int value);

	// Insert value in linked list at index.
	// Assume zero-based indexing with 1st element at index 0, the second element
	// at index 1, and so on. If list has 4 elements, their indices range from
	// 0 to 3. Then a call to insert() with index 4 would insert value as last
	// element of list. In the same example, if index is 10, then the value is
	// inserted at index 4. 
	void insert(dllist* ptr_dll, int value, size_t position);

	// Remove the first element in list with value
	void remove_first(dllist* ptr_dll, int value);

} // end namespace hlp2

#endif
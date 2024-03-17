#ifndef DLLIST_H
#define DLLIST_H

namespace hlp2 {

	class dllist
	{
	public:

		struct node
		{
			node* prev;
			int value;  // data portion
			node* next;
		};

		dllist();

		// Copy ctor
		dllist(dllist const&);

		~dllist();

		// Copy assignment
		dllist& operator=(dllist const&);

		// If data is the same and in the same order, return true
		friend bool operator==(dllist const&, dllist const&);

		// Add the data of the right dllist to the end of the left dllist, preserving the 
		// order of the data
		friend dllist operator+(dllist const&, dllist const&);

		// Add the data of the right dllist to the end of this dllist, preserving the 
		// order of the data and returning a reference to self
		dllist& operator+=(dllist const&);

		// Return a dllist with data in same order but negated
		dllist const operator-() const;

		// Pop back node and return reference to self
		dllist& operator--();

		// Copy self, pop back node, and return copy
		dllist const operator--(int);

		// Return data of node using input parameter as index where 0 is the head
		int& operator[](size_t);
		int const& operator[](size_t) const;

		// Print using print()
		friend std::ostream& operator<<(std::ostream&, dllist const&);

		// Return the count of elements 
		size_t size() const;

		// Add a new value to the beginning 
		void push_front(int value);

		// Remove the front node
		void pop_front();

		// Add a new value to the end
		void push_back(int value);

		// Print the contents 
		void print() const;

		// Find first occurrence 
		node* find(int value) const;

		// Insert value in linked list at index.
		// Assume zero-based indexing with 1st element at index 0, the second element
		// at index 1, and so on. If list has 4 elements, their indices range from
		// 0 to 3. Then a call to insert() with index 4 would insert value as last
		// element of list. In the same example, if index is 10, then the value is
		// inserted at index 4. 
		void insert(int value, size_t position);

		// Remove the first element in list with value
		void remove_first(int value);

	private:
		
		node* head;
		node* tail;
	};

	// If data of the dllists is different in terms of value, sequence, or number of 
	// items, return false
	bool operator!=(dllist const&, dllist const&);
} // end namespace hlp2

#endif
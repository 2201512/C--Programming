#ifndef LIST_H
#define LIST_H
#include "cont.h"

namespace hlp2 {

	class sllist : public cont
	{
	public:

		struct slnode
		{
			slnode(int = 0, slnode* = nullptr);
			virtual ~slnode() = default;
			
			int value;  // data portion
			slnode* next;
		};

		sllist();

		// Copy ctor
		sllist(sllist const&);

		virtual ~sllist();

		// Copy assignment operator
		sllist& operator=(sllist const&);

		// Return the count of elements 
		size_t size() const override;

		// Add a new value to the beginning 
		virtual void push_front(int value);

		// Remove the front node
		virtual void pop_front();

		// Add a new value to the end
		virtual void push_back(int value);

		void clear() override;

		// Print the contents 
		void print() const;

		// Find first occurrence 
		slnode* find(int value) const;

		// Insert value in linked list at index.
		// Assume zero-based indexing with 1st element at index 0, the second element
		// at index 1, and so on. If list has 4 elements, their indices range from
		// 0 to 3. Then a call to insert() with index 4 would insert value as last
		// element of list. In the same example, if index is 10, then the value is
		// inserted at index 4. 
		virtual void insert(int value, size_t position);

		// Remove the first element in list with value
		virtual void remove_first(int value);

	protected:

		slnode* head;
	};

	class dllist : public sllist
	{
	public:

		struct dlnode : public sllist::slnode
		{
			dlnode(dlnode* prev = nullptr, int = 0, dlnode* next = nullptr);
			dlnode* prev;
		};

		dllist();

		// Copy ctor
		dllist(dllist const&);

		~dllist();

		// Copy assignment operator
		dllist& operator=(dllist const&);

		// Add a new value to the beginning 
		void push_front(int value) override;

		// Remove the front node
		void pop_front() override;

		// Add a new value to the end
		void push_back(int value) override;

		// Insert value in linked list at index.
		// Assume zero-based indexing with 1st element at index 0, the second element
		// at index 1, and so on. If list has 4 elements, their indices range from
		// 0 to 3. Then a call to insert() with index 4 would insert value as last
		// element of list. In the same example, if index is 10, then the value is
		// inserted at index 4. 
		void insert(int value, size_t position) override;

		// Remove the first element in list with value
		void remove_first(int value) override;

	private:
		
		dlnode* tail;
	};

} // end namespace hlp2

#endif
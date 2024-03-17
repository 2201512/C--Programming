/*!*****************************************************************************
\file dllist.hpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: RSE1202
\par Lab 07
\date 04 Mar 2023
\brief This program defines functions which use interface-implementation separation for  a doubly linked list 
*******************************************************************************/
namespace hlp2 {
  template <typename T>
  class dllist
  {
  public:
    template <typename U>
    struct node
    {
      node* prev;
      U value;  // data portion
      node* next;
    };
    /**************************************************************************/
    /*!
      \brief
        constructs a new list CTOR
      
      \param nil
      
      \return nil
        
    */
    /**************************************************************************/    
    dllist();
        
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
    dllist(dllist<T> const&);
    /**************************************************************************/
    /*!
      \brief
        destroy a list Dtor
      
      \param nil
      
      \return nil
        
    */
    /**************************************************************************/    
    ~dllist();
        
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
    dllist<T>& operator=(dllist<T> const&);

    /**************************************************************************/
    /*!
      \brief
        find size of ddlist
      
      \param nil
      
      \return size_T
        size of dllist
        
    */
    /**************************************************************************/ 
    size_t size() const;

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
    void push_front(T value);

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
    void pop_front();


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
    void push_back(T value);

    /**************************************************************************/
    /*!
      \brief
        print contents
      
      \param nil

            
      \return nil
        
    */
    /**************************************************************************/
    void print() const;

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
    node<T>* find(T value) const;

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
    void insert(T value, T position);
    
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
      void remove_first(T value);
        
    // Remaining functions to be declared

  private:
    node<T>* head;
    node<T>* tail;
  };
    /**************************************************************************/
    /*!
      \brief
        constructs a new list CTOR
      
      \param nil
      
      \return nil
        
    */
    /**************************************************************************/    
    template<typename T>
  dllist<T>::dllist() :head(nullptr),tail(nullptr) {}
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
  template<typename T>
  dllist<T>::dllist(dllist<T> const&other):head(nullptr), tail(nullptr){
    if(other.head==nullptr){
      return;
    }
    node<T> const* current=other.head;
    while(current!=nullptr){
      push_back(current->value);
      current=current->next;
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
    template<typename T>    
  dllist<T>::~dllist(){
    node<T>* current = head;
    while (current != nullptr) {
      node<T>* next = current->next;
      delete current;
      current = next;
    }
    head = nullptr;
    tail = nullptr;
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
    template<typename T>
  dllist<T>& dllist<T>::operator=(dllist<T> const& rhs){
    if (this != &rhs) {
      node<T>* curr = head;
      while (curr != nullptr) {
        node<T>* temp = curr;
        curr = curr->next;
        delete temp;
      }
      head = tail = nullptr;
      node<T>* other_curr = rhs.head;
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
        find size of ddlist
      
      \param nil
      
      \return size_T
        size of dllist
        
    */
    /**************************************************************************/
  template<typename T>
  size_t dllist<T>::size() const{
    size_t count = 0;
    node<T>* current = head;
    while (current != nullptr) {
      count++;
      current = current->next;
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
  template<typename T>
  void dllist<T>:: push_front(T value){
    node<T>* newNode = new node<T>{ nullptr, value, nullptr };
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
  template<typename T>
  void dllist<T>:: pop_front(){
    if (head == nullptr) {
      return;
    }
    else if (head == tail) {
      delete head;
      head = nullptr;
      tail = nullptr;
    }
    else {
      node<T>* new_head = head->next;
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
  template<typename T>
  void dllist<T>:: push_back(T value){
    node<T>* new_node = new node<T>{ tail, value, nullptr };
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
        print contents
      
      \param nil

            
      \return nil
        
    */
    /**************************************************************************/
  template<typename T>
  void dllist<T>:: print() const{
    node<T> const* l_pCur = head;
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
  template<typename T>
  dllist<T>::node<T>* dllist<T>::find(T value) const{
    node<T>* current = head;
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
template<typename T>
  void dllist<T>:: insert(T value, T position){
    if (head == nullptr) {
    push_front(value);    
    return;
    }
    else if (position == 0) {
      push_front(value);
      return;
    }
    node<T>* current = head;
    for (size_t i = 0; i < position - 1; i++) {
      if (current->next == nullptr) {
        push_back(value);
        // return
        return;
      }
      current = current->next;
    }
    node<T>* newNode = new node<T>{ current, value, current->next };
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
  template<typename T>
  void dllist<T>:: remove_first(T value){
    if (head == nullptr) {
      return;
    }
    if (head->value == value) {
      pop_front();
      return;
    }
    node<T>* current = head;
    while (current->next != nullptr) {
      if (current->next->value == value) {
        node<T>* temp = current->next;
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
}
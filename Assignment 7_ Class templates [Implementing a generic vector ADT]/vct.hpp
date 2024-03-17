/*!*************************************************************************
****
\file except.cpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: RSE 1202
\par Section:
\par Assignment 7
\date 16-03-2023
\brief
This program does error checking and throws associated exceptions for the
operator overload assignment
****************************************************************************
***/
////////////////////////////////////////////////////////////////////////////////
#ifndef VICTOR_HPP
#define VICTOR_HPP
////////////////////////////////////////////////////////////////////////////////
#include <cstddef>          // need this for size_t
#include <initializer_list> // need this for std::initializer_list<int>


#include <cstddef>          // for size_t
#include <iostream>         // for std::ostream
#include <initializer_list> // for std::initializer_list


namespace hlp2 {
	
template <typename T>class vector {
public:
  // @todo: using declarations required!!!
  // types to declare: size_type, value_type,
  // reference, const_reference, pointer, const_pointer
  using size_type = size_t;
  using value_type = T;
  using pointer = value_type*;
  using const_pointer = value_type const*;
  using reference = value_type&;
  using const_reference = value_type const&;

  public:
  public:
  vector(){sz=0; space = 0; allocs = 0; data = nullptr;} // default ctor
  explicit vector(size_type n); // non-default ctor

  vector(std::initializer_list<T> rhs); // non-default ctor
  vector(vector const& rhs); // copy ctor
  ~vector(){if(this->data) delete[] this->data;}
  vector& operator=(vector const&);
  vector& operator=(std::initializer_list<T> rhs);
  reference operator[](size_type index);
  const_reference operator[](size_type index) const;

  void reserve(size_type n);
  void resize(size_type n);
  void push_back(value_type val);
  bool empty() const; // is container empty?
  size_type size() const; // what is sz?
  size_type capacity() const; // what is space?
  size_type allocations() const; // how many allocations or "growths"?

  pointer begin(); // pointer to first element
  pointer end(); // pointer to one past last element
  const_pointer begin() const;
  const_pointer end() const;
  const_pointer cbegin() const;
  const_pointer cend() const;

  void swap(vector& rhs);
  void pop_back();
private:
  size_type sz;     // the number of elements in the array
  size_type space;  // the allocated size (in terms of elements) of the array
  size_type allocs; // number of times space has been updated
  pointer   data;   // the dynamically allocated array
};

// non-default ctor
template <typename T>
vector<T>::vector(size_type n){
        sz=n; 
        space = n; 
        allocs = 1; 
        data = new vector::value_type[n];
  } 
// non-default ctor
  template <typename T>
  vector<T>::vector(std::initializer_list<T> rhs){
    sz=0; space = 0; allocs = 0; data = nullptr;
    space = rhs.size();
    sz = rhs.size();
    data = new T[sz];
    allocs++;
    int i = 0;
    for(T value : rhs){
        data[i++] = value; 
    }

}


template <typename T>
vector<T>::vector(vector const& rhs): sz{rhs.sz}, space{rhs.sz}, allocs{1}, data{new T[space] {} } {      
        for(size_type i{0}; i < sz; ++i)
            data[i] = rhs[i];
    }

 // ~vector(){if(this->data) delete[] this->data;}
  template<typename T>
  vector<T>& vector<T>::operator=(vector const& rhs){
        pointer tmp;
        tmp = new vector<T>::value_type[rhs.space];
        for(size_type i{0}; i < rhs.sz; ++i)
            tmp[i] = rhs.data[i];

        this->sz = rhs.sz;
        this->space = rhs.sz;
        if(this->data) delete[] data;
        this->data = tmp;
        this->allocs++;
        return *this;
  }
  template<typename T>
  vector<T>& vector<T>::operator=(std::initializer_list<T> rhs){
        pointer tmp;
        tmp = new vector::value_type[rhs.size()];
        for(size_type i{0}; i < rhs.size(); ++i)
            tmp[i] = *(rhs.begin() + i);

        this->sz = rhs.size();
        this->space = rhs.size();
        if(this->data) delete[] data;
        this->data = tmp;
        this->allocs++;
        return *this;
  }
template<typename T>
typename vector<T>::reference vector<T>::operator[](size_type index){
    if (index >= this->size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return this->data[index];
}
template<typename T>
typename vector<T>::const_reference vector<T>::operator[](size_type index) const{
    if (index >= this->size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return this->data[index];
}



  /*!*****************************************************************************
	\brief
	  function that will be used by both clients and other functions to add memory for new elements.
	\param n
	  n is the size of memory to be added.
	\return
	  void
	*******************************************************************************/
template <typename T>
  void vector<T>::reserve(size_type n){
    if(this->space >= n) return;

       pointer Arr = new value_type[n];

       // std::cout<<"Size of Arr: "<<sizeof(Arr)/sizeof(value_type)<<std::endl;
        if(this->data){
            for(size_type i = 0; i < this->sz; ++i){
                Arr[i] = this->data[i];
                //sz++;
               // delete[] this->data;
            }
            delete[] this->data;
        }
        this->sz = n;
        this->data = Arr;
        /*for(value_type element:data){
            std::cout<<"element is: "<<element<<std::endl;
        }*/
        this->space = n;
        this->allocs++;
  }
  /*!*****************************************************************************
	\brief
	  resizes the container so that it contains n elements.
	\param n
	  n is the elements to resize container.
	\return
	  void
	*******************************************************************************/
  template <typename T>
  void vector<T>::resize(size_type n){
   // std::cout<<"space: "<<space<<"  n: "<<n<<std::endl;
        if(n == this->sz) return;
        if(n < this->space) this->sz = n;
        if(n > space) reserve(n);
  }
  /*!*****************************************************************************
	\brief
	  pushes back memory block.
	\param val
	  values to be pushed back.
	\return
	  void
	*******************************************************************************/
  template <typename T>
  void vector<T>::push_back(value_type val){

        if(this->space == 0){
            reserve(1);
            sz = 0;
            //std::cout<<"reached"<<std::endl;
        }else if(this->sz == this->space){ 
            size_type temp_sz = sz;
            reserve(this->space*2);
            sz = temp_sz;
            //std::cout<<"reached 2"<<std::endl;
        }
        //std::cout<<"sz is: "<<sz<<std::endl;     
        //std::cout<<"space is: "<<space<<std::endl;      
        this->data[this->sz++] = val;
  }
    /*!*****************************************************************************
	\brief
	  deletes last element of vector.
	\return
	  void
	*******************************************************************************/
    template <typename T>
    void vector<T>::pop_back() {
        --(this->sz); 
        /*
        std::cout<<"sz before is:"<<sz<<std::endl;
    if (sz > 0) {
        sz--;
        value_type* temp = new value_type[sz];
        for(size_type i; i<sz; i++){
            std::cout<<"i is:"<<i<<std::endl;
            temp[i] = data[i];
        }
        data = temp;
        delete[] data; */
    }

  /*!*****************************************************************************
	\brief
	  check if container is empty.
	\return
	  bool
	*******************************************************************************/
template <typename T>
  bool vector<T>::empty() const{
    //std::cout<<"no. of elements: "<<sz<<std::endl;
    if(this->sz != 0){
        return false;
    }
    return true;
    /*
      if(!this->data) return true;
        return false;*/
  } // is container empty?
  /*!*****************************************************************************
	\brief
	  returns space.
	\return
	  size_type
	*******************************************************************************/
template <typename T>
  typename vector<T>::size_type vector<T>::size() const{
    return this->sz;
  } // what is sz?
  /*!*****************************************************************************
	\brief
	  returns space.
	\return
	  size_type
	*******************************************************************************/
template <typename T>
  typename vector<T>::size_type vector<T>::capacity() const{
    return this->space;
  } // what is space?
  /*!*****************************************************************************
	\brief
	  returns allocs.
	\return
	  size_type
	*******************************************************************************/
template <typename T>
  typename vector<T>::size_type vector<T>::allocations() const{
    return this->allocs;
  } // how many allocations or "growths"?
  // iterators ...
  template <typename T>
  typename vector<T>::pointer vector<T>::begin(){
    return this->data;
  } // pointer to first element
  template <typename T>
  typename vector<T>::pointer vector<T>::end(){
    return this->data+this->sz;
  } // pointer to one past last element
  template <typename T>
  typename vector<T>::const_pointer vector<T>::begin() const{
    return (const_pointer)this->data;
  }
  template <typename T>
  typename vector<T>::const_pointer vector<T>::end() const{
    return this->data+this->sz;
  }
  template <typename T>
  typename vector<T>::const_pointer vector<T>::cbegin() const{
    return (const_pointer)this->data;
  }
  template <typename T>
  typename vector<T>::const_pointer vector<T>::cend() const{
    return (const_pointer)this->data+this->sz;
  }

  // @todo: declare iterators [described in spec]
  template <typename T>
  void vector<T>::swap(vector<T>& rhs){
    std::swap(sz, rhs.sz);
    std::swap(space, rhs.space);
    std::swap(data, rhs.data);
    std::swap(allocs, rhs.allocs);
  }


}

#endif 

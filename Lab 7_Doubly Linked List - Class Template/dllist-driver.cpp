#include <iostream>
#include <iomanip>
#include <array>
#include "dllist.h"

// declarations of unit tests
void tstCtor()
{
    std::cout << "\n******************** Ctor ********************\n";
    int const arr_size{ 3 };
    std::array<int, arr_size> numbers{
      12, 34, 21 };

    hlp2::dllist<int>* list1 = new hlp2::dllist<int>{};
    
    for (int x : numbers) 
        list1->push_back(x);
       
    hlp2::dllist<int> list2 = *list1;
    std::cout << "List1 (" << std::setw(2) << list1->size() << " nodes): ";
    list1->print();
    delete list1;
    list1 = nullptr;
    std::cout << "List2 (" << std::setw(2) << list2.size() << " nodes): ";
    list2.print();
}
void tstOperator1()
{
    std::cout << "\n******************** Operator1 ********************\n";
    int const arr_size{ 4 };
    std::array<double, arr_size> numbers{
      1.2, 3.4, 2.1, 5.6 };

    hlp2::dllist<double>* list1 = new hlp2::dllist<double>{};

    for (double x : numbers)
        list1->push_back(x);

    hlp2::dllist<double> list2;
    list2 = *list1;
    std::cout << "List1 (" << std::setw(2) << list1->size() << " nodes): ";
    list1->print();
    delete list1;
    list1 = nullptr;
    std::cout << "List2 (" << std::setw(2) << list2.size() << " nodes): ";
    list2.print();
}
void tstOperator2()
{
    std::cout << "\n******************** Operator2 ********************\n";
    int const arr_size{ 5 };
    std::array<char, arr_size> numbers{
      12, 34, 21, 56, 38 };

    hlp2::dllist<char>* list1 = new hlp2::dllist<char>{};

    for (char x : numbers)
        list1->push_back(x);

    int const arr_size2{ 6 };
    std::array<char, arr_size2> numbers2{
      22, 23, 38, 94, 56, 34 };

    hlp2::dllist<char> list2;
    for (char x : numbers2)
        list2.push_back(x);
    
    list2 = *list1;
    std::cout << "List1 (" << std::setw(2) << list1->size() << " nodes): ";
    list1->print();
    delete list1;
    list1 = nullptr;
    std::cout << "List2 (" << std::setw(2) << list2.size() << " nodes): ";
    list2.print();
}

// this is the purpose of the driver - to call each of these tests in turn ...
int main() {
    tstCtor();
    tstOperator1();
    tstOperator2();
}
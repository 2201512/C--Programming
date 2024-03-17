#include <iostream>
#include <iomanip>
#include <array>
#include "dllist.h"

// declarations of unit tests
void tstEqualOp()
{
    std::cout << "\n******************** Copy Assignment Operator ********************\n";

    std::array<int, 3> numbers{
          12, 34, 21 };
    hlp2::dllist list1;
    for (int x : numbers)
    list1.push_back(x);

    std::array<int, 3> numbers2{
      12, 3, 21 };
    hlp2::dllist list2;
    for (int x : numbers2)
        list2.push_back(x);

    std::array<int, 4> numbers3{
      12, 3, 21, 4 };
    hlp2::dllist list3;
    for (int x : numbers3)
      list3.push_back(x);

    std::cout << "list1 (" << std::setw(2) << list1.size() << " nodes): " << list1;
    std::cout << "list2 (" << std::setw(2) << list2.size() << " nodes): " << list2;
    std::cout << "list3 (" << std::setw(2) << list3.size() << " nodes): " << list3;

    list1 = list2 = list3;
    std::cout << "list1=list2=list3 (" << std::setw(2) << list1.size()
      << " nodes): " << list1;
}
void tstEquality()
{
    std::cout << "\n******************** Equality ********************\n";
   
    std::array<int, 3> numbers{
      12, 34, 21 };
    hlp2::dllist list1;
    for (int x : numbers)
        list1.push_back(x);

    std::array<int, 3> numbers2{
      12, 3, 21 };
    hlp2::dllist list2;
    for (int x : numbers2)
        list2.push_back(x);

    std::array<int, 4> numbers3{
      12, 3, 21, 4};
    hlp2::dllist list3;
    for (int x : numbers3)
        list3.push_back(x);
    
    std::cout << "list1 (" << std::setw(2) << list1.size() << " nodes): " << list1;
    std::cout << "list2 (" << std::setw(2) << list2.size() << " nodes): " << list2;
    std::cout << "list3 (" << std::setw(2) << list3.size() << " nodes): " << list3;
    std::cout << std::boolalpha;
    std::cout << "list1==list1 is " << (list1 == list1) << '\n';
    std::cout << "list1!=list1 is " << (list1 != list1) << '\n';
    std::cout << "list1==list2 is " << (list1 == list2) << '\n';
    std::cout << "list1!=list2 is " << (list1 != list2) << '\n';
    std::cout << "list2==list3 is " << (list2 == list3) << '\n';
    std::cout << "list2!=list3 is " << (list2 != list3) << '\n';
}
void tstJuzAdd()
{
    std::cout << "\n******************** Simple Add ********************\n";
    
    std::array<int, 3> numbers{
      12, 34, 21 };

    hlp2::dllist list1;
    
    for (int x : numbers) 
        list1.push_back(x);
       
    hlp2::dllist list2 = list1 + list1;
    std::cout << "list1 (" << std::setw(2) << list1.size() << " nodes): " << list1;
    std::cout << "list1+list1 (" << std::setw(2) << list2.size() << " nodes): " <<
        list2;
}
void tstAddEqual1()
{
    std::cout << "\n******************** Compound Add 1 ********************\n";
    std::array<int, 3> numbers{
      12, 34, 21 };

    hlp2::dllist list1;

    for (int x : numbers)
        list1.push_back(x);

    std::cout << "list1 (" << std::setw(2) << list1.size() << " nodes): " << list1;
    
    list1 += list1;
    std::cout << "list1+=list1 (" << std::setw(2) << list1.size() << " nodes): " <<
        list1;
}
void tstAddEqual2()
{
    std::cout << "\n******************** Compound Add 2 ********************\n";
    std::array<int, 3> numbers{
      12, 34, 21 };

    hlp2::dllist list1;

    for (int x : numbers)
        list1.push_back(x);

    hlp2::dllist list2 = list1;

    std::cout << "list1 (" << std::setw(2) << list1.size() << " nodes): " << list1;
    std::cout << "list2 (" << std::setw(2) << list2.size() << " nodes): " << list2;
    
    list1 += list2;
    std::cout << "list1+=list2 (" << std::setw(2) << list1.size() << " nodes): " <<
        list1;
}
void tstAddEqual3()
{
    std::cout << "\n******************** Compound Add 3 ********************\n";

    std::array<int, 3> numbers{
      12, 34, 21 };
    hlp2::dllist list1;
    for (int x : numbers)
        list1.push_back(x);

    std::array<int, 4> numbers2{
      12, 3, 21, 4 };
    hlp2::dllist list2;
    for (int x : numbers2)
        list2.push_back(x);

    std::cout << "list1 (" << std::setw(2) << list1.size() << " nodes): " << list1;
    std::cout << "list2 (" << std::setw(2) << list2.size() << " nodes): " << list2;

    list1 += list2 += list1;
    std::cout << "list1+=list2+=list1 (" << std::setw(2) << list1.size() 
        << " nodes): " << list1;
}
void tstNegatn()
{
    std::cout << "\n******************** Negation ********************\n";

    std::array<int, 3> numbers{
      12, 34, 21 };
    hlp2::dllist list1;
    for (int x : numbers)
        list1.push_back(x);
    hlp2::dllist list2 = -list1;
    std::cout << "list1 (" << std::setw(2) << list1.size() << " nodes): " << list1;
    std::cout << "list2 (" << std::setw(2) << list2.size() << " nodes): " << list2;
}
void tstPrefixPopBack()
{
    std::cout << "\n******************** Prefix Pop Back ********************\n";

    std::array<int, 3> numbers{
      12, 34, 21 };
    hlp2::dllist list1;
    for (int x : numbers)
        list1.push_back(x);
    std::cout << "list1 (" << std::setw(2) << list1.size() << " nodes): " << list1;
    
    std::cout << "--list1 (" << std::setw(2) << (--list1).size() << " nodes): " << 
        list1;
    
    std::cout << "----list1 (" << std::setw(2) << (----list1).size() << " nodes): " << 
        list1;
    
    std::cout << "--list1 (" << std::setw(2) << (--list1).size() << " nodes): " << 
        list1;
}
void tstPostfixPopBack()
{
    std::cout << "\n******************** Postfix Pop Back ********************\n";

    std::array<int, 3> numbers{
      12, 34, 21 };
    hlp2::dllist list1;
    for (int x : numbers)
        list1.push_back(x);
    std::cout << "list1 (" << std::setw(2) << list1.size() << " nodes): " << list1;
    hlp2::dllist list2 = list1--;
    std::cout << "list1-- returned (" << std::setw(2) << list2.size() << " nodes): " 
        << list2;
    std::cout << "Final list1 (" << std::setw(2) << list1.size() << " nodes): "
        << list1;
}
void tstNonconstSubscript()
{
    std::cout << "\n******************** Non-const Subscript ********************\n";

    std::array<int, 3> numbers{
      12, 34, 21 };
    hlp2::dllist list1;
    for (int x : numbers)
        list1.push_back(x);
    std::cout << "list1 (" << std::setw(2) << list1.size() << " nodes): " << list1;
    std::cout << "list1[0] = " << list1[0] << '\n';
    std::cout << "list1[1] = " << list1[1] << '\n';
}
void tstConstSubscript()
{
    std::cout << "\n******************** Const Subscript ********************\n";

    std::array<int, 3> numbers{
      12, 34, 21 };
    hlp2::dllist list1;
    for (int x : numbers)
        list1.push_back(x);
    hlp2::dllist const list2 = list1;
    std::cout << "const list2 (" << std::setw(2) << list2.size() << " nodes): " << 
        list2;
    std::cout << "list2[0] = " << list2[0] << '\n';
    std::cout << "list2[1] = " << list2[1] << '\n';
}
// this is the purpose of the driver - to call each of these tests in turn ...
int main() {
    tstEqualOp();
    tstEquality();
    tstJuzAdd();
    tstAddEqual1();
    tstAddEqual2();
    tstAddEqual3();
    tstNegatn();
    tstPrefixPopBack();
    tstPostfixPopBack();
    tstNonconstSubscript();
    tstConstSubscript();
}
#include <iostream>
#include <iomanip>
#include <array>
#include "dllist.h"

// declarations of unit tests
static void test_find();
static void test_add();
static void test_remove();
static void test_insert();

// this is the purpose of the driver - to call each of these tests in turn ...
int main() {
    test_add();
    test_find();
    test_insert();
    test_remove();
}

void test_add() {
    std::cout << "\n******************** Add ********************\n";
    int const arr_size{ 15 };
    std::array<int, arr_size> numbers{
      12, 34, 21, 56, 38,
      94, 23, 22, 67, 56,
      88, 19, 59, 10, 17
    };

    hlp2::dllist list1; 
    hlp2::dllist list2;
    for (int x : numbers) {
        list1.push_back(x);
        list2.push_front(x);

        std::cout << "List1 (" << std::setw(2) << list1.size() << " nodes): ";
        list1.print();
        std::cout << "List2 (" << std::setw(2) << list2.size() << " nodes): ";
        list2.print();

        std::cout << std::endl;
    }
}

void test_find() {
    std::cout << "\n******************** Find ********************\n";

    hlp2::dllist list;

    int const arr_size{ 12 };
    std::array<int, arr_size> numbers{
      22, 23, 38, 94, 56, 34,
      67, 56, 88, 19, 10, 59
    };

    for (int x : numbers) {
        list.push_back(x);
    }
    std::cout << "List (" << std::setw(2) << list.size() << " nodes): ";
    list.print();

    // Find an existing value
    int value = 56;
    hlp2::dllist::node* node = list.find(value);
    if (node) {
        std::cout << "Value: " << node->value << " was found.\n";
    }
    else {
        std::cout << "Value: " << value << " was not found.\n";
    }

    value = 22;
    node = list.find(value);
    if (node) {
        std::cout << "Value: " << node->value << " was found.\n";
    }
    else {
        std::cout << "Value: " << value << " was not found.\n";
    }

    value = 59;
    node = list.find(value);
    if (node) {
        std::cout << "Value: " << node->value << " was found.\n";
    }
    else {
        std::cout << "Value: " << value << " was not found.\n";
    }

    // Find a non-existent value
    value = 123;
    node = list.find( value);
    if (node) {
        std::cout << "Value: " << node->value << " was found.\n";
    }
    else {
        std::cout << "Value: " << value << " was not found.\n";
    }

    std::cout << "list (" << std::setw(2) << list.size() << " nodes): ";
    list.print();
}

void test_insert() {
    std::cout
        << "\n******************** Insert ********************\n";

    hlp2::dllist list;

    int const arr_size{ 15 };
    std::array<int, arr_size> numbers{
      12, 34, 21, 56, 38,
      94, 23, 22, 67, 56,
      88, 19, 59, 10, 17
    };

    for (int i = 0; i < 5; i++) {
        list.push_back( numbers[i]);
        std::cout << "List (" << std::setw(2) << list.size() << " nodes): ";
        list.print();
        std::cout << std::endl;
    }

    std::cout << "inserting... 91 at position 3\n";
    list.insert(91, 3);
    list.print();
    std::cout << "inserting... 92 at position 0\n";
    list.insert(92, 0);
    list.print();
    std::cout << "inserting... 93 at position 5\n";
    list.insert(93, 5);
    list.print();
    std::cout << "inserting... 94 at position 9\n";
    list.insert(94, 9);
    list.print();
}

void test_remove() {
    std::cout
        << "\n******************** Remove ********************\n";

    hlp2::dllist list;

    int const arr_size{ 12 };
    std::array<int, arr_size> numbers{
      22, 23, 38, 94, 56, 34,
      67, 56, 88, 19, 10, 59
    };
    for (int x : numbers) {
        list.push_back(x);
    }

    std::cout << "List (" << std::setw(2) << list.size() << " nodes): ";
    list.print();

    list.remove_first(56);
    std::cout
        << "Deleting: 56 (" << std::setw(2) << list.size() << " nodes): ";
    list.print();

    list.remove_first(22);
    std::cout
        << "Deleting: 22 (" << std::setw(2) << list.size() << " nodes): ";
    list.print();

    list.remove_first(59);
    std::cout
        << "Deleting: 59 (" << std::setw(2) << list.size() << " nodes): ";
    list.print();

    list.remove_first(99);
    std::cout
        << "Deleting: 99 (" << std::setw(2) << list.size() << " nodes): ";
    list.print();

    int const arr_size1{ 9 };
    std::array<int, arr_size1> numbers1{
      23, 38, 94,
      34, 67, 56,
      88, 19, 10
    };
    for (int x : numbers1) {
        list.remove_first(x);
        std::cout
            << "Deleting: " << x
            << " (" << std::setw(2) << list.size() << " nodes): ";
        list.print();
    }

    list.remove_first(99);
    std::cout
        << "Deleting: 99"
        << " (" << std::setw(2) << list.size() << " nodes): ";
    list.print();
}
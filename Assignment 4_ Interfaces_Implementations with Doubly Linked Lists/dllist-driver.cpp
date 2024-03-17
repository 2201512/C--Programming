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

    hlp2::dllist* list1 = hlp2::construct_list();
    hlp2::dllist* list2 = hlp2::construct_list();
    for (int x : numbers) {
        hlp2::push_back(list1, x);
        hlp2::push_front(list2, x);

        std::cout << "List1 (" << std::setw(2) << hlp2::size(list1) << " nodes): ";
        hlp2::print(list1);
        std::cout << "List2 (" << std::setw(2) << hlp2::size(list2) << " nodes): ";
        hlp2::print(list2);

        std::cout << std::endl;
    }

    hlp2::destruct_list(list2);
    hlp2::destruct_list(list1);
}

void test_find() {
    std::cout << "\n******************** Find ********************\n";

    hlp2::dllist* list{ nullptr };
    list = hlp2::construct_list();

    int const arr_size{ 12 };
    std::array<int, arr_size> numbers{
      22, 23, 38, 94, 56, 34,
      67, 56, 88, 19, 10, 59
    };

    for (int x : numbers) {
        hlp2::push_back(list, x);
    }
    std::cout << "List (" << std::setw(2) << hlp2::size(list) << " nodes): ";
    hlp2::print(list);

    // Find an existing value
    int value = 56;
    hlp2::node* node = hlp2::find(list, value);
    if (node) {
        std::cout << "Value: " << get_value(node) << " was found.\n";
    }
    else {
        std::cout << "Value: " << value << " was not found.\n";
    }

    value = 22;
    node = hlp2::find(list, value);
    if (node) {
        std::cout << "Value: " << get_value(node) << " was found.\n";
    }
    else {
        std::cout << "Value: " << value << " was not found.\n";
    }

    value = 59;
    node = hlp2::find(list, value);
    if (node) {
        std::cout << "Value: " << get_value(node) << " was found.\n";
    }
    else {
        std::cout << "Value: " << value << " was not found.\n";
    }

    // Find a non-existent value
    value = 123;
    node = hlp2::find(list, value);
    if (node) {
        std::cout << "Value: " << get_value(node) << " was found.\n";
    }
    else {
        std::cout << "Value: " << value << " was not found.\n";
    }

    std::cout << "list (" << std::setw(2) << hlp2::size(list) << " nodes): ";
    hlp2::print(list);

    hlp2::destruct_list(list);
}

void test_insert() {
    std::cout
        << "\n******************** Insert ********************\n";

    hlp2::dllist* list = hlp2::construct_list();

    int const arr_size{ 15 };
    std::array<int, arr_size> numbers{
      12, 34, 21, 56, 38,
      94, 23, 22, 67, 56,
      88, 19, 59, 10, 17
    };

    for (int i = 0; i < 5; i++) {
        hlp2::push_back(list, numbers[i]);
        std::cout << "List (" << std::setw(2) << size(list) << " nodes): ";
        print(list);
        std::cout << std::endl;
    }

    std::cout << "inserting... 91 at position 3\n";
    insert(list, 91, 3);
    print(list);
    std::cout << "inserting... 92 at position 0\n";
    insert(list, 92, 0);
    print(list);
    std::cout << "inserting... 93 at position 5\n";
    insert(list, 93, 5);
    print(list);
    std::cout << "inserting... 94 at position 9\n";
    insert(list, 94, 9);
    print(list);

    hlp2::destruct_list(list);
}

void test_remove() {
    std::cout
        << "\n******************** Remove ********************\n";

    hlp2::dllist* list = hlp2::construct_list();

    int const arr_size{ 12 };
    std::array<int, arr_size> numbers{
      22, 23, 38, 94, 56, 34,
      67, 56, 88, 19, 10, 59
    };
    for (int x : numbers) {
        hlp2::push_back(list, x);
    }

    std::cout << "List (" << std::setw(2) << size(list) << " nodes): ";
    print(list);

    remove_first(list, 56);
    std::cout
        << "Deleting: 56 (" << std::setw(2) << size(list) << " nodes): ";
    print(list);

    remove_first(list, 22);
    std::cout
        << "Deleting: 22 (" << std::setw(2) << size(list) << " nodes): ";
    print(list);

    remove_first(list, 59);
    std::cout
        << "Deleting: 59 (" << std::setw(2) << size(list) << " nodes): ";
    print(list);

    remove_first(list, 99);
    std::cout
        << "Deleting: 99 (" << std::setw(2) << size(list) << " nodes): ";
    print(list);

    int const arr_size1{ 9 };
    std::array<int, arr_size1> numbers1{
      23, 38, 94,
      34, 67, 56,
      88, 19, 10
    };
    for (int x : numbers1) {
        remove_first(list, x);
        std::cout
            << "Deleting: " << x
            << " (" << std::setw(2) << size(list) << " nodes): ";
        print(list);
    }

    remove_first(list, 99);
    std::cout
        << "Deleting: 99"
        << " (" << std::setw(2) << size(list) << " nodes): ";
    print(list);

    hlp2::destruct_list(list);
}
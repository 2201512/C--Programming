#include <iostream>
#include <iomanip>
#include <array>
#include "list.h"

// declarations of unit tests
void tstCtor()
{
    std::cout << "\n******************** Default & Copy Ctor ********************\n";
    int const arr_size{ 3 };
    std::array<int, arr_size> numbers{
      12, 34, 21 };

    hlp2::dllist* list1 = new hlp2::dllist{};
    std::cout << "List1 is " << (list1->is_empty() ? "" : "not ") << "empty\n";

    std::cout << "Adding to List1:\n";
    for (int x : numbers)
        list1->push_back(x);
    std::cout << "List1 is " << (list1->is_empty() ? "" : "not ") << "empty\n";

    hlp2::dllist list2 = *list1;
    std::cout << "List1 (" << std::setw(2) << list1->size() << " nodes): ";
    list1->print();
    delete list1;
    list1 = nullptr;
    std::cout << "List2 (" << std::setw(2) << list2.size() << " nodes): ";
    list2.print();
}
void tstPushFront()
{
    std::cout << "\n******************** Push Front & Clear ********************\n";
    int const arr_size{ 3 };
    std::array<int, arr_size> numbers{
      12, 34, 21 };

    hlp2::sllist* psll = new hlp2::sllist{};
    hlp2::sllist* pdll = new hlp2::dllist{};

    std::cout << "sllist is " << (psll->is_empty() ? "" : "not ") << "empty\n";
    std::cout << "dllist is " << (pdll->is_empty() ? "" : "not ") << "empty\n";

    std::cout << "Adding to Lists:\n";
    for (int x : numbers)
    {
        psll->push_front(x);
        pdll->push_front(x);
    }
    std::cout << "sllist is " << (psll->is_empty() ? "" : "not ") << "empty\n";
    std::cout << "dllist is " << (pdll->is_empty() ? "" : "not ") << "empty\n";
    
    std::cout << "SLList (" << std::setw(2) << psll->size() << " nodes): ";
    psll->print();
    
    std::cout << "DLList (" << std::setw(2) << pdll->size() << " nodes): ";
    pdll->print();

    std::cout << "About to clear:\n";
    psll->clear();
    pdll->clear();
    std::cout << "sllist is " << (psll->is_empty() ? "" : "not ") << "empty\n";
    std::cout << "dllist is " << (pdll->is_empty() ? "" : "not ") << "empty\n";

    delete psll;
    psll = nullptr;
    delete pdll;
    pdll = nullptr;
}
void tstPopFront()
{
    std::cout << "\n******************** Pop Front ********************\n";
    int const arr_size{ 3 };
    std::array<int, arr_size> numbers{
      12, 34, 21 };

    hlp2::sllist* psll = new hlp2::sllist{};
    hlp2::sllist* pdll = new hlp2::dllist{};

    for (int x : numbers)
    {
        psll->push_front(x);
        pdll->push_front(x);
    }

    std::cout << "SLList (" << std::setw(2) << psll->size() << " nodes): ";
    psll->print();
    std::cout << "DLList (" << std::setw(2) << pdll->size() << " nodes): ";
    pdll->print();

    for (int i{}; i < arr_size + 1; ++i)
    {
        psll->pop_front();
        pdll->pop_front();
        std::cout << "SLList (" << std::setw(2) << psll->size() << " nodes): ";
        psll->print();
        std::cout << "DLList (" << std::setw(2) << pdll->size() << " nodes): ";
        pdll->print();
    }

    delete psll;
    psll = nullptr;
    delete pdll;
    pdll = nullptr;
}
void tstPushBack()
{
    std::cout << "\n******************** Push Back ********************\n";
    int const arr_size{ 3 };
    std::array<int, arr_size> numbers{
      12, 34, 21 };

    hlp2::sllist* psll = new hlp2::sllist{};
    hlp2::sllist* pdll = new hlp2::dllist{};

    for (int x : numbers)
    {
        psll->push_back(x);
        pdll->push_back(x);
    }

    std::cout << "SLList (" << std::setw(2) << psll->size() << " nodes): ";
    psll->print();

    std::cout << "DLList (" << std::setw(2) << pdll->size() << " nodes): ";
    pdll->print();

    delete psll;
    psll = nullptr;
    delete pdll;
    pdll = nullptr;
}
void tstInsert()
{
    std::cout << "\n******************** Insert ********************\n";

    hlp2::sllist* psll = new hlp2::sllist{};
    hlp2::sllist* pdll = new hlp2::dllist{};

    psll->insert(1, 4);
    pdll->insert(1, 4);

    psll->insert(2, 1);
    pdll->insert(2, 1);

    psll->insert(3, 0);
    pdll->insert(3, 0);

    std::cout << "SLList (" << std::setw(2) << psll->size() << " nodes): ";
    psll->print();

    std::cout << "DLList (" << std::setw(2) << pdll->size() << " nodes): ";
    pdll->print();

    delete psll;
    psll = nullptr;
    delete pdll;
    pdll = nullptr;
}
void tstRm1st()
{
    std::cout << "\n******************** Remove 1st ********************\n";

    hlp2::sllist* psll = new hlp2::sllist{};
    hlp2::sllist* pdll = new hlp2::dllist{};

    psll->insert(1, 4);
    pdll->insert(1, 4);

    psll->insert(2, 1);
    pdll->insert(2, 1);

    psll->insert(3, 0);
    pdll->insert(3, 0);

    psll->insert(3, 2);
    pdll->insert(3, 2);

    std::cout << "SLList (" << std::setw(2) << psll->size() << " nodes): ";
    psll->print();
    std::cout << "DLList (" << std::setw(2) << pdll->size() << " nodes): ";
    pdll->print();

    psll->remove_first(3);
    pdll->remove_first(3);
    std::cout << "SLList (" << std::setw(2) << psll->size() << " nodes): ";
    psll->print();
    std::cout << "DLList (" << std::setw(2) << pdll->size() << " nodes): ";
    pdll->print();

    psll->remove_first(3);
    pdll->remove_first(3);
    std::cout << "SLList (" << std::setw(2) << psll->size() << " nodes): ";
    psll->print();
    std::cout << "DLList (" << std::setw(2) << pdll->size() << " nodes): ";
    pdll->print();

    psll->remove_first(2);
    pdll->remove_first(2);
    std::cout << "SLList (" << std::setw(2) << psll->size() << " nodes): ";
    psll->print();
    std::cout << "DLList (" << std::setw(2) << pdll->size() << " nodes): ";
    pdll->print();

    psll->remove_first(4);
    pdll->remove_first(4);
    std::cout << "SLList (" << std::setw(2) << psll->size() << " nodes): ";
    psll->print();
    std::cout << "DLList (" << std::setw(2) << pdll->size() << " nodes): ";
    pdll->print();

    delete psll;
    psll = nullptr;
    delete pdll;
    pdll = nullptr;
}

// this is the purpose of the driver - to call each of these tests in turn ...
int main() {
    tstCtor();
    tstPushFront();
    tstPopFront();
    tstPushBack();
    tstInsert();
    tstRm1st();
}
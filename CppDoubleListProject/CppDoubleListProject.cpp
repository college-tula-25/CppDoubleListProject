#include <iostream>
#include "DoubleList.h"

int main()
{
    DoubleList<int> list;

    PushFront(list, 100);
    PushFront(list, 200);
    PushFront(list, 300);

    PushBack(list, 400);
    PushBack(list, 500);
    PushBack(list, 600);

    PrintForward(list);

    Node<int>* node = Find(list, 300);

    InsertAfter(list, node, 1000);

    PrintForward(list);
}

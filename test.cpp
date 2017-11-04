#include <iostream>
#include "sortedArrayList.h"
#include "sortedLinkedList.h"

int main()
{
    SortedArrayList sa1, sa2, sa3;
    SortedLinkedList sl1, sl2, sl3;

    // sa1.push(2);
    // sa1.push(3);
    // sa2.push(14);
    // sa2.push(2);

    sl1.push(2);
    sl1.push(3);
    sl1.push(14);
    sl1.push(2);

    //sa3 = SortedArrayList::merge(sa1, sa2);
    //sl3 = SortedLinkedList::merge(sl1, sl2);

    //sa3.print();
    sl1.print();
}

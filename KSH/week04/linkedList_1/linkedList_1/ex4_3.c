#include <stdio.h>
#include "CircularLinkedList.h"

int main(void) {
    circularList_h* CL = createCircularList_h();

    insertLastNode(CL, "월");
    insertLastNode(CL, "화");
    insertLastNode(CL, "수");
    insertLastNode(CL, "목");
    insertLastNode(CL, "금");

    printList(CL);  // CL = (월, 화, 수, 목, 금)

    freeCircularList(CL);
    return 0;
}

#include <stdio.h>
#include "CircularLinkedList.h"

int main(void) {
    circularList_h* CL = createCircularList_h();

    insertLastNode(CL, "��");
    insertLastNode(CL, "ȭ");
    insertLastNode(CL, "��");
    insertLastNode(CL, "��");
    insertLastNode(CL, "��");

    printList(CL);  // CL = (��, ȭ, ��, ��, ��)

    freeCircularList(CL);
    return 0;
}

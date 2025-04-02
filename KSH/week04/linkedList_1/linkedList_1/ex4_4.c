#include <stdio.h>
#include "DoubleLinkedList.h"

int main(void) {
    dlinkedList_h* DL = createDLinkedList_h();

    insertNode(DL, NULL, "��");  // ù ���
    insertNode(DL, DL->head, "��");  // '��' �ڿ� '��'
    insertNode(DL, NULL, "��");  // �� �տ� '��'
    printList(DL);  // DL = (��, ��, ��)

    // ���� �׽�Ʈ: '��' ����
    deleteNode(DL, DL->head->rlink);  // '��'�� �� ��° ���
    printList(DL);  // DL = (��, ��)

    freeDLinkedList(DL);
    return 0;
}

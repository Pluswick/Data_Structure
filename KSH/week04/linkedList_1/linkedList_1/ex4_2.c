#include <stdio.h>
#include "LinkedList.h"

int main(void) {
    linkedList_h* L = createLinkedList_h();

    insertFirstNode(L, "��");
    insertLastNode(L, "��");
    insertFirstNode(L, "��");
    insertMiddleNode(L, L->head, "ȭ");  // '��' �ڿ� 'ȭ' ����
    printList(L);  // L = (��, ȭ, ��, ��)

    // Ž��
    listNode* found = searchNode(L, "��");
    if (found) printf("Ž�� ����: %s\n", found->data);

    // ���� ('ȭ' ���� '��' ����)
    listNode* pre = searchNode(L, "ȭ");
    deleteNode(L, pre);
    printList(L);  // L = (��, ȭ, ��)

    // ���� ��ȯ
    reverse(L);
    printList(L);  // L = (��, ȭ, ��)

    freeLinkedList_h(L);
    return 0;
}

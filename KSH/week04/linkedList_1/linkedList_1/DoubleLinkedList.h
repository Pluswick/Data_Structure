#pragma once

typedef struct DListNode {
    char data[4];
    struct DListNode* llink;  // ���� ���
    struct DListNode* rlink;  // ���� ���
} dlistNode;

typedef struct {
    dlistNode* head;
} dlinkedList_h;

// �Լ� ����
dlinkedList_h* createDLinkedList_h(void);
void insertNode(dlinkedList_h* DL, dlistNode* pre, char* x);
void deleteNode(dlinkedList_h* DL, dlistNode* old);
void printList(dlinkedList_h* DL);
void freeDLinkedList(dlinkedList_h* DL);

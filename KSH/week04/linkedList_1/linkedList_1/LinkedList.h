#pragma once

typedef struct ListNode {
    char data[4];
    struct ListNode* link;
} listNode;

typedef struct {
    listNode* head;
} linkedList_h;

// �ǽ� 1 �Լ�
linkedList_h* createLinkedList_h(void);
void freeLinkedList_h(linkedList_h* L);
void printList(linkedList_h* L);
void insertFirstNode(linkedList_h* L, char* x);
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x);
void insertLastNode(linkedList_h* L, char* x);

// �ǽ� 2 �Լ�
void deleteNode(linkedList_h* L, listNode* pre);
listNode* searchNode(linkedList_h* L, char* x);
void reverse(linkedList_h* L);

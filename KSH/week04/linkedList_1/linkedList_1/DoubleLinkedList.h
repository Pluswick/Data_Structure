#pragma once

typedef struct DListNode {
    char data[4];
    struct DListNode* llink;  // 이전 노드
    struct DListNode* rlink;  // 다음 노드
} dlistNode;

typedef struct {
    dlistNode* head;
} dlinkedList_h;

// 함수 원형
dlinkedList_h* createDLinkedList_h(void);
void insertNode(dlinkedList_h* DL, dlistNode* pre, char* x);
void deleteNode(dlinkedList_h* DL, dlistNode* old);
void printList(dlinkedList_h* DL);
void freeDLinkedList(dlinkedList_h* DL);

#pragma once

typedef struct ListNode {
    char data[4];
    struct ListNode* link;
} listNode;

typedef struct {
    listNode* tail;  // 마지막 노드를 가리킴
} circularList_h;

// 함수 원형
circularList_h* createCircularList_h(void);
void printList(circularList_h* CL);
void insertLastNode(circularList_h* CL, char* x);
void freeCircularList(circularList_h* CL);

#pragma once

typedef struct ListNode {
    char data[4];
    struct ListNode* link;
} listNode;

typedef struct {
    listNode* tail;  // ������ ��带 ����Ŵ
} circularList_h;

// �Լ� ����
circularList_h* createCircularList_h(void);
void printList(circularList_h* CL);
void insertLastNode(circularList_h* CL, char* x);
void freeCircularList(circularList_h* CL);

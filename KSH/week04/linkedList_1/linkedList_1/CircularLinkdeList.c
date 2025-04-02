#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularLinkedList.h"

// ���� ����Ʈ ����
circularList_h* createCircularList_h(void) {
    circularList_h* CL = (circularList_h*)malloc(sizeof(circularList_h));
    CL->tail = NULL;
    return CL;
}

// ������ ��� �ڿ� ����
void insertLastNode(circularList_h* CL, char* x) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);

    if (CL->tail == NULL) {
        CL->tail = newNode;
        newNode->link = newNode;  // �ڱ� �ڽ� ����Ŵ
    }
    else {
        newNode->link = CL->tail->link;     // ù ��° ��� ����
        CL->tail->link = newNode;           // ���� ������ ��� �� �� ��� ����
        CL->tail = newNode;                 // tail ����
    }
}

// ����Ʈ ���
void printList(circularList_h* CL) {
    if (CL->tail == NULL) {
        printf("CL = ()\n");
        return;
    }

    listNode* p = CL->tail->link;  // ù ������ ����
    printf("CL = (");
    do {
        printf("%s", p->data);
        p = p->link;
        if (p != CL->tail->link) printf(", ");
    } while (p != CL->tail->link);
    printf(")\n");
}

// �޸� ����
void freeCircularList(circularList_h* CL) {
    if (CL->tail == NULL) return;

    listNode* p = CL->tail->link;
    listNode* temp;
    do {
        temp = p;
        p = p->link;
        free(temp);
    } while (p != CL->tail->link);
    free(CL);
}

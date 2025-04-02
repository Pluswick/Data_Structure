#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleLinkedList.h"

// ����Ʈ ����
dlinkedList_h* createDLinkedList_h(void) {
    dlinkedList_h* DL = (dlinkedList_h*)malloc(sizeof(dlinkedList_h));
    DL->head = NULL;
    return DL;
}

// ��� ����
void insertNode(dlinkedList_h* DL, dlistNode* pre, char* x) {
    dlistNode* newNode = (dlistNode*)malloc(sizeof(dlistNode));
    strcpy(newNode->data, x);
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if (DL->head == NULL) {
        DL->head = newNode;
    }
    else if (pre == NULL) {
        newNode->rlink = DL->head;
        DL->head->llink = newNode;
        DL->head = newNode;
    }
    else {
        newNode->rlink = pre->rlink;
        newNode->llink = pre;
        if (pre->rlink != NULL)
            pre->rlink->llink = newNode;
        pre->rlink = newNode;
    }
}

// ��� ����
void deleteNode(dlinkedList_h* DL, dlistNode* old) {
    if (DL->head == NULL || old == NULL) return;

    if (old == DL->head) {
        DL->head = old->rlink;
        if (DL->head != NULL)
            DL->head->llink = NULL;
    }
    else {
        old->llink->rlink = old->rlink;
        if (old->rlink != NULL)
            old->rlink->llink = old->llink;
    }
    free(old);
}

// ����Ʈ ���
void printList(dlinkedList_h* DL) {
    dlistNode* p = DL->head;
    printf("DL = (");
    while (p != NULL) {
        printf("%s", p->data);
        p = p->rlink;
        if (p != NULL) printf(", ");
    }
    printf(")\n");
}

// �޸� ����
void freeDLinkedList(dlinkedList_h* DL) {
    dlistNode* p = DL->head;
    dlistNode* temp;
    while (p != NULL) {
        temp = p;
        p = p->rlink;
        free(temp);
    }
    free(DL);
}

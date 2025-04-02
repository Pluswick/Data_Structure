#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

// 실습 1
linkedList_h* createLinkedList_h(void) {
    linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL;
    return L;
}

void freeLinkedList_h(linkedList_h* L) {
    listNode* p;
    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;
        free(p);
    }
}

void printList(linkedList_h* L) {
    listNode* p = L->head;
    printf("L = (");
    while (p != NULL) {
        printf("%s", p->data);
        p = p->link;
        if (p != NULL) printf(", ");
    }
    printf(")\n");
}

void insertFirstNode(linkedList_h* L, char* x) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link = L->head;
    L->head = newNode;
}

void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);

    if (L->head == NULL || pre == NULL) {
        newNode->link = L->head;
        L->head = newNode;
    }
    else {
        newNode->link = pre->link;
        pre->link = newNode;
    }
}

void insertLastNode(linkedList_h* L, char* x) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link = NULL;

    if (L->head == NULL) {
        L->head = newNode;
        return;
    }

    listNode* temp = L->head;
    while (temp->link != NULL) temp = temp->link;
    temp->link = newNode;
}

// 실습 2
void deleteNode(linkedList_h* L, listNode* pre) {
    if (L->head == NULL || pre == NULL || pre->link == NULL) return;

    listNode* old = pre->link;
    pre->link = old->link;
    free(old);
}

listNode* searchNode(linkedList_h* L, char* x) {
    listNode* temp = L->head;
    while (temp != NULL) {
        if (strcmp(temp->data, x) == 0)
            return temp;
        temp = temp->link;
    }
    return NULL;
}

void reverse(linkedList_h* L) {
    listNode* p = L->head, * q = NULL, * r = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    L->head = q;
}

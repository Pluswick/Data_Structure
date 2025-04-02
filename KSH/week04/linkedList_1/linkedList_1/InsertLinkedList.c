#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "InsertLinkedList.h"

// ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void) {
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL;  // ���� ����Ʈ�̹Ƿ� NULL�� ����
    return L;
}

// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList_h(linkedList_h* L) {
    listNode* p;
    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;
        free(p);
        p = NULL;
    }
}

// ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* L) {
    listNode* p;
    printf("L = (");
    p = L->head;
    while (p != NULL) {
        printf("%s", p->data);
        p = p->link;
        if (p != NULL) printf(", ");
    }
    printf(")\n");
}

// ù ��° ���� �����ϴ� ����
void insertFirstNode(linkedList_h* L, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));  // ������ �� ��� �Ҵ�
    strcpy(newNode->data, x);                       // �� ����� ������ �ʵ忡 x ����
    newNode->link = L->head;                        // �� ����� ��ũ�� ���� head ����Ű��
    L->head = newNode;                              // ����Ʈ�� head �� �� ���� ������Ʈ
}

// ��带 pre �ڿ� �����ϴ� ����
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));  // �� ��� ���� �Ҵ�
    strcpy(newNode->data, x);                       // �� ��忡 ������ ����

    if (L->head == NULL) {                          // ���� ����Ʈ�� ���
        newNode->link = NULL;
        L->head = newNode;
    }
    else if (pre == NULL) {                       // pre�� NULL�� ��� (ù ��°�� ����)
        newNode->link = L->head;
        L->head = newNode;
    }
    else {                                        // �߰� ����
        newNode->link = pre->link;                  // �� ��尡 pre �� ��带 ����Ŵ
        pre->link = newNode;                        // pre�� �� ��带 ����Ű�� ��
    }
}

// ������ ���� �����ϴ� ����
void insertLastNode(linkedList_h* L, char* x) {
    listNode* newNode;
    listNode* temp;
    newNode = (listNode*)malloc(sizeof(listNode));  // �� ��� ���� �Ҵ�
    strcpy(newNode->data, x);                       // ������ ����
    newNode->link = NULL;

    if (L->head == NULL) {                          // ���� ����Ʈ�� ���
        L->head = newNode;
        return;
    }

    temp = L->head;
    while (temp->link != NULL) temp = temp->link;   // ������ ��� Ž��
    temp->link = newNode;                           // ������ ��� �ڿ� �� ��� ����
}

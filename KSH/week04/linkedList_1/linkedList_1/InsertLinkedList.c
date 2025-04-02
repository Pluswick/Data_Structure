#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "InsertLinkedList.h"

// 공백 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL;  // 공백 리스트이므로 NULL로 설정
    return L;
}

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* L) {
    listNode* p;
    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;
        free(p);
        p = NULL;
    }
}

// 연결 리스트를 순서대로 출력하는 연산
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

// 첫 번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h* L, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));  // 삽입할 새 노드 할당
    strcpy(newNode->data, x);                       // 새 노드의 데이터 필드에 x 저장
    newNode->link = L->head;                        // 새 노드의 링크가 현재 head 가리키게
    L->head = newNode;                              // 리스트의 head 를 새 노드로 업데이트
}

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));  // 새 노드 동적 할당
    strcpy(newNode->data, x);                       // 새 노드에 데이터 복사

    if (L->head == NULL) {                          // 공백 리스트인 경우
        newNode->link = NULL;
        L->head = newNode;
    }
    else if (pre == NULL) {                       // pre가 NULL인 경우 (첫 번째에 삽입)
        newNode->link = L->head;
        L->head = newNode;
    }
    else {                                        // 중간 삽입
        newNode->link = pre->link;                  // 새 노드가 pre 뒤 노드를 가리킴
        pre->link = newNode;                        // pre가 새 노드를 가리키게 함
    }
}

// 마지막 노드로 삽입하는 연산
void insertLastNode(linkedList_h* L, char* x) {
    listNode* newNode;
    listNode* temp;
    newNode = (listNode*)malloc(sizeof(listNode));  // 새 노드 동적 할당
    strcpy(newNode->data, x);                       // 데이터 복사
    newNode->link = NULL;

    if (L->head == NULL) {                          // 공백 리스트일 경우
        L->head = newNode;
        return;
    }

    temp = L->head;
    while (temp->link != NULL) temp = temp->link;   // 마지막 노드 탐색
    temp->link = newNode;                           // 마지막 노드 뒤에 새 노드 연결
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularLinkedList.h"

// 원형 리스트 생성
circularList_h* createCircularList_h(void) {
    circularList_h* CL = (circularList_h*)malloc(sizeof(circularList_h));
    CL->tail = NULL;
    return CL;
}

// 마지막 노드 뒤에 삽입
void insertLastNode(circularList_h* CL, char* x) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);

    if (CL->tail == NULL) {
        CL->tail = newNode;
        newNode->link = newNode;  // 자기 자신 가리킴
    }
    else {
        newNode->link = CL->tail->link;     // 첫 번째 노드 연결
        CL->tail->link = newNode;           // 기존 마지막 노드 → 새 노드 연결
        CL->tail = newNode;                 // tail 갱신
    }
}

// 리스트 출력
void printList(circularList_h* CL) {
    if (CL->tail == NULL) {
        printf("CL = ()\n");
        return;
    }

    listNode* p = CL->tail->link;  // 첫 노드부터 시작
    printf("CL = (");
    do {
        printf("%s", p->data);
        p = p->link;
        if (p != CL->tail->link) printf(", ");
    } while (p != CL->tail->link);
    printf(")\n");
}

// 메모리 해제
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

#include <stdio.h>
#include <stdlib.h>
#include "PolyLinkedList.h"

// ����Ʈ ����
polyList* createPolyList(void) {
    polyList* PL = (polyList*)malloc(sizeof(polyList));
    PL->head = NULL;
    PL->tail = NULL;
    return PL;
}

// �� �߰�
void appendTerm(polyList* PL, int coef, int expo) {
    polyNode* newNode = (polyNode*)malloc(sizeof(polyNode));
    newNode->coef = coef;
    newNode->expo = expo;
    newNode->link = NULL;

    if (PL->head == NULL) {
        PL->head = PL->tail = newNode;
    }
    else {
        PL->tail->link = newNode;
        PL->tail = newNode;
    }
}

// ���׽� ���
void printPoly(polyList* PL) {
    polyNode* p = PL->head;
    while (p != NULL) {
        printf("%dx^%d", p->coef, p->expo);
        if (p->link != NULL) printf(" + ");
        p = p->link;
    }
    printf("\n");
}

// ���׽� ����
polyList* addPoly(polyList* A, polyList* B) {
    polyNode* p = A->head;
    polyNode* q = B->head;
    polyList* C = createPolyList();

    while (p && q) {
        if (p->expo > q->expo) {
            appendTerm(C, p->coef, p->expo);
            p = p->link;
        }
        else if (p->expo < q->expo) {
            appendTerm(C, q->coef, q->expo);
            q = q->link;
        }
        else {
            int sum = p->coef + q->coef;
            if (sum != 0)
                appendTerm(C, sum, p->expo);
            p = p->link;
            q = q->link;
        }
    }

    while (p) {
        appendTerm(C, p->coef, p->expo);
        p = p->link;
    }

    while (q) {
        appendTerm(C, q->coef, q->expo);
        q = q->link;
    }

    return C;
}

// �޸� ����
void freePoly(polyList* PL) {
    polyNode* p = PL->head;
    polyNode* temp;
    while (p) {
        temp = p;
        p = p->link;
        free(temp);
    }
    free(PL);
}

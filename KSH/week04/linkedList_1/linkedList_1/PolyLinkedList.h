#pragma once

typedef struct PolyNode {
    int coef;   // ���
    int expo;   // ����
    struct PolyNode* link;
} polyNode;

// ���׽� ���
typedef struct {
    polyNode* head;
    polyNode* tail;
} polyList;

// �Լ� ����
polyList* createPolyList(void);
void appendTerm(polyList* PL, int coef, int expo);
polyList* addPoly(polyList* A, polyList* B);
void printPoly(polyList* PL);
void freePoly(polyList* PL);

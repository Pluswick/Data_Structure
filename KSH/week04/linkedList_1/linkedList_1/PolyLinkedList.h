#pragma once

typedef struct PolyNode {
    int coef;   // 계수
    int expo;   // 차수
    struct PolyNode* link;
} polyNode;

// 다항식 헤더
typedef struct {
    polyNode* head;
    polyNode* tail;
} polyList;

// 함수 원형
polyList* createPolyList(void);
void appendTerm(polyList* PL, int coef, int expo);
polyList* addPoly(polyList* A, polyList* B);
void printPoly(polyList* PL);
void freePoly(polyList* PL);

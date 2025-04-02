#include <stdio.h>
#include "PolyLinkedList.h"

int main(void) {
    // 다항식 A(x) = 4x^3 + 3x^2 + 5x
    polyList* A = createPolyList();
    appendTerm(A, 4, 3);
    appendTerm(A, 3, 2);
    appendTerm(A, 5, 1);

    // 다항식 B(x) = 3x^4 + 1x^3 + 2x + 1
    polyList* B = createPolyList();
    appendTerm(B, 3, 4);
    appendTerm(B, 1, 3);
    appendTerm(B, 2, 1);
    appendTerm(B, 1, 0);

    // 결과 C(x) = A(x) + B(x)
    polyList* C = addPoly(A, B);

    printf("A(x) = "); printPoly(A);
    printf("B(x) = "); printPoly(B);
    printf("C(x) = "); printPoly(C);

    freePoly(A);
    freePoly(B);
    freePoly(C);
    return 0;
}

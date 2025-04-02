#include <stdio.h>
#include "DoubleLinkedList.h"

int main(void) {
    dlinkedList_h* DL = createDLinkedList_h();

    insertNode(DL, NULL, "수");  // 첫 노드
    insertNode(DL, DL->head, "금");  // '수' 뒤에 '금'
    insertNode(DL, NULL, "월");  // 맨 앞에 '월'
    printList(DL);  // DL = (월, 수, 금)

    // 삭제 테스트: '수' 삭제
    deleteNode(DL, DL->head->rlink);  // '수'는 두 번째 노드
    printList(DL);  // DL = (월, 금)

    freeDLinkedList(DL);
    return 0;
}

#include <stdio.h>
#include "LinkedList.h"

int main(void) {
    linkedList_h* L = createLinkedList_h();

    insertFirstNode(L, "수");
    insertLastNode(L, "금");
    insertFirstNode(L, "월");
    insertMiddleNode(L, L->head, "화");  // '월' 뒤에 '화' 삽입
    printList(L);  // L = (월, 화, 수, 금)

    // 탐색
    listNode* found = searchNode(L, "수");
    if (found) printf("탐색 성공: %s\n", found->data);

    // 삭제 ('화' 뒤의 '수' 삭제)
    listNode* pre = searchNode(L, "화");
    deleteNode(L, pre);
    printList(L);  // L = (월, 화, 금)

    // 역순 변환
    reverse(L);
    printList(L);  // L = (금, 화, 월)

    freeLinkedList_h(L);
    return 0;
}

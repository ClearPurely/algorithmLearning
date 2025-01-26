#include "_86_Partition.h"

ListNode* _86_Partition::partition(ListNode* head, int x)
{
    ListNode* leftHead = NULL;  // < x 的区域的头节点
    ListNode* leftTail = NULL;  // < x 的区域的尾节点
    ListNode* rightHead = NULL; // >= x 的区域的头节点
    ListNode* rightTail = NULL; // >= x 的区域的尾节点
    ListNode* next = NULL;      // 临时存储当前节点的下一个节点

    // 遍历链表
    while (head != NULL) {
        next = head->next;
        head->next = NULL;

        if (head->val < x) {
            if (leftHead == NULL) {
                leftHead = head;
            }
            else {
                leftTail->next = head;
            }
            leftTail = head;
        }
        else {
            if (rightHead == NULL) {
                rightHead = head;
            }
            else {
                rightTail->next = head;
            }
            rightTail = head;
        }

        head = next;
    }

    if (leftHead == NULL) {
        return rightHead;
    }
    leftTail->next = rightHead;
    return leftHead;
}

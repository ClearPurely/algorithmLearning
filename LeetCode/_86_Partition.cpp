#include "_86_Partition.h"

ListNode* _86_Partition::partition(ListNode* head, int x)
{
    ListNode* leftHead = NULL;  // < x �������ͷ�ڵ�
    ListNode* leftTail = NULL;  // < x �������β�ڵ�
    ListNode* rightHead = NULL; // >= x �������ͷ�ڵ�
    ListNode* rightTail = NULL; // >= x �������β�ڵ�
    ListNode* next = NULL;      // ��ʱ�洢��ǰ�ڵ����һ���ڵ�

    // ��������
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

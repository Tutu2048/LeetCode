//
// Created by 18122252978 on 2025/2/24.
//
/*
*21. �ϲ�������������
* ��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
*ʾ�� 1��
*���룺l1 = [1,2,4], l2 = [1,3,4]
*�����[1,1,2,3,4,4]
*
*ʾ�� 2��
*���룺l1 = [], l2 = []
*�����[]
*
*ʾ�� 3��
*���룺l1 = [], l2 = [0]
*�����[0]
*
*/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr) { return list2; }
        if (list2 == nullptr) { return list1; }

        ListNode *head,*cur1,*cur2;
        if(list1->val < list2->val) {
            head = list1;
            cur1 = list1->next;
            cur2 = list2;
        }else {
            head = list2;
            cur1 = list1;
            cur2 = list2->next;
        }
        ListNode *cur = head;

        while (cur1 && cur2) {
            if (cur1->val < cur2->val) {
                cur->next = cur1;
                cur1 = cur1->next;
            }else {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }

        if (cur1) {
            cur->next = cur1;
        } else {
            cur->next = cur2;
        }

        return head;
    }
};

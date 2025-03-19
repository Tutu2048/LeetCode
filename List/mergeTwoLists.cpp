//
// Created by 18122252978 on 2025/2/24.
//
/*
*21. 合并两个有序链表
* 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
*示例 1：
*输入：l1 = [1,2,4], l2 = [1,3,4]
*输出：[1,1,2,3,4,4]
*
*示例 2：
*输入：l1 = [], l2 = []
*输出：[]
*
*示例 3：
*输入：l1 = [], l2 = [0]
*输出：[0]
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

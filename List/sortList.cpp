/*
*148. 排序链表
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
示例 1：
输入：head = [4,2,1,3]
输出：[1,2,3,4]
*
示例 2：
输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
*
示例 3：
输入：head = []
输出：[]
*
提示：
链表中节点的数目在范围 [0, 5 * 104] 内
-105 <= Node.val <= 105
进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
*/
#include "../normal.h"
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //常规插入排序 O（n^2）
        if(head==NULL || head->next==NULL) return head;

        //根据提议设置一个足够小的数字
        ListNode *headPre = new ListNode(-1000,head);
        ListNode *last = head, *pre = headPre;
        while (last != NULL) {
            if(last->val >= pre->val) {
                last = last->next;
                pre = pre->next;
            }
            else {
                ListNode *tmp = headPre;
                while(tmp !=last) {
                    if (last->val >= tmp->val && last->val < tmp->next->val) {
                        insertNode(tmp, pre,last);
                        last =pre->next;
                        break;
                    }
                    tmp = tmp->next;
                }
            }
        }
        return headPre->next;
    }

    void insertNode(ListNode *cur,ListNode* preNode, ListNode *newNode) {
        //脱链子
        preNode->next = newNode->next;
        //insert
        newNode->next = cur->next;
        cur->next = newNode;
    }

    ListNode* sortListFast(ListNode* head) {
        //归并
        if(head==NULL || head->next==NULL) return head;

        int len=1;
        ListNode *node= head;
        while(node) {
            node=node->next;
            len++;
        }

        ListNode *vhead =new ListNode(-1000,head);
        ListNode *ret = vhead;
        for (int length = 1; length < len; length *= 2) {
            ListNode *cur = ret->next;
            vhead =ret;
            while(cur) {
                //find first list
                ListNode *head1 = cur;
                for (int i = 1; cur != nullptr && i < length; ++i) {
                    cur= cur->next;
                }
                //unlink 1 list find sencond list
                ListNode *head2 = nullptr;
                if(cur) {
                    head2 = cur->next;
                    cur->next = NULL;
                    cur = head2;
                }

                //unlink 2
                for (int i = 1; cur != nullptr && i < length; ++i) {
                    cur= cur->next;
                }
                if(cur) {
                    ListNode *tmp = cur->next;
                    cur->next = nullptr;
                    cur = tmp;
                }

                //sort
                auto headx = ListSortHelper(head1,head2);
                vhead->next = headx;
                while(vhead->next) {
                    vhead = vhead->next;
                }
            }
        }

        return ret->next;
    }

    ListNode* ListSortHelper(ListNode* head1,ListNode* head2) {
        ListNode *ret = new ListNode(-1000);
        ListNode *cur= ret;
        while(head1&&head2) {
            if(head1->val <= head2->val) {
                cur->next = head1;
                head1=head1->next;
            }else {
                cur->next = head2;
                head2=head2->next;
            }
            cur = cur->next;
        }
        if (head1) cur->next = head1;
        else cur->next = head2;

        return ret->next;
    }

};
int main() {
    //还可以直接交换数字,不执行链表的插入操作
    //但链表的插入效率也很高了。
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    Solution solution;
    auto ret =solution.sortListFast(head);
    while(ret != NULL) {
        cout << ret->val << endl;
        ret = ret->next;
    }
}


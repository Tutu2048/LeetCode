/*
*148. ��������
���������ͷ��� head ���뽫�䰴 ���� ���в����� ���������� ��
ʾ�� 1��
���룺head = [4,2,1,3]
�����[1,2,3,4]
*
ʾ�� 2��
���룺head = [-1,5,3,4,0]
�����[-1,0,3,4,5]
*
ʾ�� 3��
���룺head = []
�����[]
*
��ʾ��
�����нڵ����Ŀ�ڷ�Χ [0, 5 * 104] ��
-105 <= Node.val <= 105
���ף�������� O(n log n) ʱ�临�ӶȺͳ������ռ临�Ӷ��£����������������
*/
#include "../normal.h"
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //����������� O��n^2��
        if(head==NULL || head->next==NULL) return head;

        //������������һ���㹻С������
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
        //������
        preNode->next = newNode->next;
        //insert
        newNode->next = cur->next;
        cur->next = newNode;
    }

    ListNode* sortListFast(ListNode* head) {
        //�鲢
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
    //������ֱ�ӽ�������,��ִ������Ĳ������
    //������Ĳ���Ч��Ҳ�ܸ��ˡ�
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


//86. 分隔链表
//给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
//你应当 保留 两个分区中每个节点的初始相对位置。
//
//示例 1：
//输入：head = [1,4,3,2,5,2], x = 3
//输出：[1,2,2,4,3,5]

//示例 2：
//输入：head = [2,1], x = 2
//输出：[1,2]
//
//提示：
//链表中节点的数目在范围 [0, 200] 内
//-100 <= Node.val <= 100
//-200 <= x <= 200

#include "../normal.h"
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head ||!head->next)   return head;
        //思路：fast向后搜索查找比x小的，slow指向大于x的第一个
        //fast找到 ，交换slow和fast的值，校准slow ， fast继续寻找。
        ListNode* slow= nullptr;
        ListNode* fast= head;
        while(fast){
            if(fast->val < x){
                if(slow){
                    swap(fast->val,slow->val);
                    slow = slow->next;
                }
            }else{
                //首次赋值
                if(!slow)   slow  = fast;
            }
            fast =fast->next;
        }
        return head;
    }
    //But:不能保证相对位置
    //变种，slow指向最后一个小于x的节点，fast节点插入到slow后
    //因为要保留前一个节点的信息
    ListNode* partition2(ListNode* head, int x) {
        if(!head ||!head->next)   return head;

        ListNode dummy(-1, head);
        auto slow= &dummy;
        auto fast= slow;

        while(fast->next){
            if(fast->next->val < x){
                if(fast !=slow)
                    insert(fast,fast->next,slow);
                else
                    fast = fast->next;
                //矫正,保证slow的意义
                slow = slow->next;
            }else{
                fast = fast->next;
            }
        }

        return dummy.next;
    }

    void insert(ListNode* preIndex,ListNode* newIndex,ListNode* in){
        //断链
        preIndex->next = newIndex->next;
        //插入操作
        newIndex->next = in->next;
        in->next = newIndex;
    }
};

int main(){
    //官方解是，用两个哑节点，每遍历一个就插入到某一列，最后将两个哑节点到链连起来
    //test
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    head = s.partition2(head,3);
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;

}
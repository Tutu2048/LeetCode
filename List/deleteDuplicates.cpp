// 2025-03-28 09:06:22
// 82 删除排序链表中的重复元素 II
//给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
//
// 示例 1：
//输入：head = [1,2,3,3,4,4,5]
//输出：[1,2,5]
//
// 示例 2：
//输入：head = [1,1,1,2,3]
//输出：[2,3]
//
// 提示：
// 链表中节点数目在范围 [0, 300] 内
// -100 <= Node.val <= 100
// 题目数据保证链表已经按升序 排列

#include "../normal.h"
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      if(head==nullptr||head->next ==nullptr) return head;
      ListNode* fast = head->next;
      ListNode*slow = new ListNode(-1000,head);
      ListNode* ret= slow;//head可能被删除
      while(fast!=nullptr){
          if(fast->val==slow->next->val){
            fast = fast->next;
          }else if(fast == slow->next->next){
            slow = slow->next;
          }else{
            erase(slow,fast);
            fast = fast->next;
          }
      }

      //解决最后一次
      if(slow->next->next)
          slow ->next =nullptr;
      return ret->next;
    }
private:
    void erase(ListNode* start,ListNode* end){
      start->next=end;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main() {
  //还有优化空间，可以不需要fast slow 2个指针
  //可以用一个指针，来判断是否是重复的
    Solution s;
    // vector<int> nodes = {1,2,3,3,4,4,5};
    ListNode *head = new ListNode(1);
    ListNode* result = s.deleteDuplicates(head);
    // printList(result); // Output: 1 -> 2 -> 5
    return 0;
}

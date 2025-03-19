/*
*129. ����ڵ㵽Ҷ�ڵ�����֮��
����һ���������ĸ��ڵ� root ������ÿ���ڵ㶼�����һ�� 0 �� 9 ֮������֡�
ÿ���Ӹ��ڵ㵽Ҷ�ڵ��·��������һ�����֣�

���磬�Ӹ��ڵ㵽Ҷ�ڵ��·�� 1 -> 2 -> 3 ��ʾ���� 123 ��
����Ӹ��ڵ㵽Ҷ�ڵ����ɵ� ��������֮�� ��

Ҷ�ڵ� ��ָû���ӽڵ�Ľڵ㡣

ʾ�� 1��
���룺root = [1,2,3]
�����25
���ͣ�
�Ӹ���Ҷ�ӽڵ�·�� 1->2 �������� 12
�Ӹ���Ҷ�ӽڵ�·�� 1->3 �������� 13
��ˣ������ܺ� = 12 + 13 = 25

ʾ�� 2��
���룺root = [4,9,0,5,1]
�����1026
���ͣ�
�Ӹ���Ҷ�ӽڵ�·�� 4->9->5 �������� 495
�Ӹ���Ҷ�ӽڵ�·�� 4->9->1 �������� 491
�Ӹ���Ҷ�ӽڵ�·�� 4->0 �������� 40
��ˣ������ܺ� = 495 + 491 + 40 = 1026

��ʾ��
���нڵ����Ŀ�ڷ�Χ [1, 1000] ��
0 <= Node.val <= 9
������Ȳ����� 10
 */

#include "../normal.h"
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return help(root,0);
    }

    int help(TreeNode *root,int upLevelNum) {
        if (root == nullptr) return 0;

        int thisLevelNum =upLevelNum*10+root->val;
        if (!root->left && !root->right) {
            return thisLevelNum;
        }
        return  help(root->left,thisLevelNum)+help(root->right,thisLevelNum);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution test;
    cout <<test.sumNumbers(root)<<endl;

}
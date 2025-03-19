/*
*637. �������Ĳ�ƽ��ֵ
����һ���ǿն������ĸ��ڵ� root , ���������ʽ����ÿһ��ڵ��ƽ��ֵ����ʵ�ʴ���� 10-5 ���ڵĴ𰸿��Ա����ܡ�
ʾ�� 1��
���룺root = [3,9,20,null,null,15,7]
�����[3.00000,14.50000,11.00000]
���ͣ��� 0 ���ƽ��ֵΪ 3,�� 1 ���ƽ��ֵΪ 14.5,�� 2 ���ƽ��ֵΪ 11 ��
��˷��� [3, 14.5, 11] ��

ʾ�� 2:
���룺root = [3,9,20,15,7]
�����[3.00000,14.50000,11.00000]

��ʾ��
���нڵ������� [1, 104] ��Χ��
-231 <= Node.val <= 231 - 1
 */
#include "../normal.h"
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        queue<TreeNode*> nextl;
        vector<double> res;

        int num=0;
        double sum = 0;
        q.push(root);

        while(!q.empty()||!nextl.empty()){
            auto x = q.front();
            q.pop();
            sum += x->val;
            ++num;

            if(x->left) {nextl.push(x->left);}
            if(x->right) {nextl.push(x->right);}

            if(q.empty()){
                q.swap(nextl);
                res.push_back(sum/num);
                sum=0;num=0;
            }
        }
        return res;
    }
};

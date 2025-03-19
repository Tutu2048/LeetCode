/*
*637. 二叉树的层平均值
给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。
示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[3.00000,14.50000,11.00000]
解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
因此返回 [3, 14.5, 11] 。

示例 2:
输入：root = [3,9,20,15,7]
输出：[3.00000,14.50000,11.00000]

提示：
树中节点数量在 [1, 104] 范围内
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

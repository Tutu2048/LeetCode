/*222. 完全二叉树的节点个数
*给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
*
*完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
*并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层（从第 0 层开始），则该层包含 1~ 2^h 个节点。
*/

#include "../normal.h"
class Solution {
public:
    int countNodes(TreeNode* root) {
        //层序遍历一遍
        queue<TreeNode*> q;

        if(!root) return 0;
        q.push(root);
        int count=0;
        while(!q.empty()) {
            root =q.front();
            q.pop();
            ++count;

            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }

        return count;
    }
};
int main() {
    //官方解 ：二分查找+位运算！?

    return 0;
}
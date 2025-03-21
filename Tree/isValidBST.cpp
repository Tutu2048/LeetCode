// 2025-03-21 09:09:53
// 98 验证二叉搜索树
//给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
//
// 有效 二叉搜索树定义如下：
// 节点的左子树只包含 小于 当前节点的数。
// 节点的右子树只包含 大于 当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。
//
// 示例 1：
//输入：root = [2,1,3]
//输出：true
//
// 示例 2：
//输入：root = [5,1,4,null,null,3,6]
//输出：false
//解释：根节点的值是 5 ，但是右子节点的值是 4 。
//
// 提示：
// 树中节点数目范围在[1, 10⁴] 内
// -2³¹ <= Node.val <= 2³¹ - 1
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 2537 👎 0

#include "../normal.h"
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        helper(root);
        for(int i=1;i<values.size();++i){
            if(values[i]<=values[i-1]) return false;
        }
        return true;
    }

    void helper(TreeNode* root){
        if(!root)   return;
        helper(root->left);
        values.push_back(root->val);
        helper(root->right);
    }

    bool isValidBST2(TreeNode* root) {
        TreeNode* pre= nullptr;
        return helper(root, pre);
    }

    bool helper(TreeNode* root,TreeNode*& pre){
        if (!root)  return true;

        if(!helper(root->left,pre)) return false;
        if(pre && pre->val >= root->val)  return false;
        pre = root;
        if(!helper(root->right,pre)) return false;

        return true;
    }

private:
    vector<int> values;
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right= new TreeNode(3);
    cout<<s.isValidBST2(root)<<endl;
    cout<<s.isValidBST(root)<<endl;
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(6);
    root1->right->left = new TreeNode(3);
    root1->right->right = new TreeNode(7);
    cout<<s.isValidBST2(root1)<<endl;
    return 0;
}

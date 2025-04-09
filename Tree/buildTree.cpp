// 2025-04-09 08:48:35
// 105 从前序与中序遍历序列构造二叉树
//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并
//返回其根节点。
//
// 示例 1:
//输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//输出: [3,9,20,null,null,15,7]
//
// 示例 2:
//输入: preorder = [-1], inorder = [-1]
//输出: [-1]
//
// 提示:
// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder 和 inorder 均 无重复 元素
// inorder 均出现在 preorder
// preorder 保证 为二叉树的前序遍历序列
// inorder 保证 为二叉树的中序遍历序列
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 2516 👎 0



#include "../normal.h"
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        int i=0;
        for(;i<inorder.size();i++){
            value2Index[inorder[i]] = i;
        }
        return buildHelp(preorder,inorder,0,i-1,0,i-1);


    }
private:
    TreeNode* buildHelp(vector<int>& preorder, vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd){
        if (preStart > preEnd || inStart > inEnd || preStart < 0 || preEnd < 0 || inStart < 0 || inEnd < 0 || preStart >= preorder.size() || preEnd >= preorder.size() || inStart >= preorder.size() || inEnd >= preorder.size())
            return nullptr;
        TreeNode* root =new TreeNode(preorder[preStart]);

        int index = value2Index[root->val];//index  代表inorder root的位置
        int size = index - inStart; //左子树的大小
        root->left = buildHelp(preorder,inorder,preStart+1,preStart + size ,inStart,index-1);
        root->right= buildHelp(preorder,inorder,preStart+size+1,preEnd,index+1,inEnd);
        return root;
    }

    map<int,int> value2Index;
};
//leetcode submit region end(Prohibit modification and deletion)
int main(){
    vector<int> a={3,9,20,15,7};
    vector<int> b={9,3,15,20,7};
    Solution s;
    s.buildTree(a,b);
}
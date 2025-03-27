// 2025-03-27 13:30:17
// 104 二叉树的最大深度 
//给定一个二叉树 root ，返回其最大深度。 
//
// 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。 
//
// 示例 1： 
//输入：root = [3,9,20,null,null,15,7]
//输出：3
// 
// 示例 2：
//输入：root = [1,null,2]
//输出：2
//
// 提示： 
// 树中节点的数量在 [0, 10⁴] 区间内。
// -100 <= Node.val <= 100 

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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;

        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty()) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[i] != -1) { // -1 represents null
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Test cases
#include <cassert>
void test_maxDepth() {
    Solution solution;

    // Test case 1: Example 1
    TreeNode* root1 = buildTree({3, 9, 20, -1, -1, 15, 7});
    assert(solution.maxDepth(root1) == 3);

    // Test case 2: Example 2
    TreeNode* root2 = buildTree({1, -1, 2});
    assert(solution.maxDepth(root2) == 2);

    // Test case 3: Empty tree
    TreeNode* root3 = nullptr;
    assert(solution.maxDepth(root3) == 0);

    // Test case 4: Single node
    TreeNode* root4 = buildTree({1});
    assert(solution.maxDepth(root4) == 1);

    // Test case 5: Left-skewed tree
    TreeNode* root5 = buildTree({1, 2, -1, 3, -1, 4});
    assert(solution.maxDepth(root5) == 4);

    // Test case 6: Right-skewed tree
    TreeNode* root6 = buildTree({1, -1, 2, -1, 3, -1, 4});
    assert(solution.maxDepth(root6) == 4);

    // Test case 7: Full binary tree
    TreeNode* root7 = buildTree({1, 2, 3, 4, 5, 6, 7});
    assert(solution.maxDepth(root7) == 3);

    cout << "All test cases passed!" << endl;
}

int main() {
    test_maxDepth();
    return 0;
}
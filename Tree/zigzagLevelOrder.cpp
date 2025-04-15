//103. 二叉树的锯齿形层序遍历
//给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
//
//示例 1：
//输入：root = [3,9,20,null,null,15,7]
//输出：[[3],[20,9],[15,7]]

//示例 2：
//输入：root = [1]
//输出：[[1]]

//示例 3：
//输入：root = []
//输出：[]
//
//提示：
//树中节点数目在范围 [0, 2000] 内
//-100 <= Node.val <= 100

#include "../normal.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)   return  {};
        queue<TreeNode*> q;
        q.push(root);
        bool isleft=1;
        vector<vector<int>> res;

        while(!q.empty()){
            int size = q.size();
            deque<int> layer;

            for(int i=0;i<size;++i){
                //遍历
                auto cur = q.front();
                q.pop();

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);

                //输出
                if(isleft)
                    layer.push_back(cur->val);
                else
                    layer.push_front(cur->val);
            }
            res.emplace_back(layer.begin(),layer.end());
            isleft = !isleft;
        }
        return res;
    }
};
int main(){

    return 0;
}
//108. 将有序数组转换为二叉搜索树
//给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。
//
//示例 1：
//输入：nums = [-10,-3,0,5,9]
//输出：[0,-3,9,-10,null,5]
//解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
//
//示例 2：
//输入：nums = [1,3]
//输出：[3,1]
//解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
//
//提示：
//1 <= nums.length <= 104
//-104 <= nums[i] <= 104
//nums 按 严格递增 顺序排列

#include "../normal.h"
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size  = nums.size();
        return help(nums,0,size-1);
    }

private:
    TreeNode* help(vector<int>& nums , int start ,int end){
        if(start >end)  return nullptr;

        int mid = (end+start)/2;
        auto root = new TreeNode(nums[mid]);

        if(start != end){
            root->left = help(nums,start,mid-1);
            root->right = help(nums,mid+1,end);
        }

        return root;
    }
};
int main(){
    Solution s;
    vector<int> nums = {-10,-3,0,5,9};
    auto ans = s.sortedArrayToBST(nums);

    return 0;
}

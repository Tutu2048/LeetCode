// 2025-03-19 09:09:42
// 300 最长递增子序列
//给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
//
// 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子
//序列。
//
// 示例 1：
//输入：nums = [10,9,2,5,3,7,101,18]
//输出：4
//解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
//
// 示例 2：
//输入：nums = [0,1,0,3,2,3]
//输出：4
//
// 示例 3：
//输入：nums = [7,7,7,7,7,7,7]
//输出：1

// 提示：
// 1 <= nums.length <= 2500
// -10? <= nums[i] <= 10?
//
// 进阶：
// 你能将算法的时间复杂度降低到 O(n log(n)) 吗?



#include "../normal.h"
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())return 0;
        int maxNums=1;
        //dp[i] 表示以nums[i]为最大值 的最长子序列的长度
        vector<int> dp(nums.size(),1);
        for(int i=0;i<nums.size();++i){
            int cur = nums[i];
            for(int j=0;j<i;++j){
                if(cur > nums[j]){
                    dp[i] = dp[i] > dp[j]+1 ?dp[i] :dp[j]+1;
                    maxNums = max(dp[i],maxNums);
                }
            }
        }
        return maxNums;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
int main(){
    //重新定义dp表以有序表的方式展现结合二分法，来降低时间复杂度。
    //例如map<int,int> key:最长子序列长度 value：最小的 最长子序列 的终点 （不需要1对多）
}

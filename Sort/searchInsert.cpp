#include  "../normal.h"
/*给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
示例 1:

输入: nums = [1,3,5,6], target = 5
输出: 2
示例 2:

输入: nums = [1,3,5,6], target = 2
输出: 1
示例 3:

输入: nums = [1,3,5,6], target = 7
输出: 4
请必须使用时间复杂度为 O(log n) 的算法。*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        int left = 0,right = nums.size()-1;
        int mid= (left + right)/2;
        while(left <= right) {
            if (target == nums[mid]) return mid;
            if(target <nums[mid]) right = mid-1;
            else left = mid+1;
            mid = (left + right)/2;
        }
        return left;
    }
};
int main() {
    Solution test;
    vector<int>  v{1,3,5,6};
    cout << test.searchInsert(v,5) << endl;
    cout << test.searchInsert(v,2) << endl;
    cout << test.searchInsert(v,7) << endl;

}
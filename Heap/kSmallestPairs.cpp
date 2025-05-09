//373. 查找和最小的 K 对数字
//给定两个以 非递减顺序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。
//定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
//请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。
//
//示例 1:
//输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
//输出: [1,2],[1,4],[1,6]
//解释: 返回序列中的前 3 对数：
//[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

//示例 2:
//输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
//输出: [1,1],[1,1]
//解释: 返回序列中的前 2 对数：
//[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
//
//提示:
//1 <= nums1.length, nums2.length <= 105
//-109 <= nums1[i], nums2[i] <= 109
//nums1 和 nums2 均为 升序排列
//1 <= k <= 104
//k <= nums1.length * nums2.length
//注意：不能是同数组的元素对！！！！！即 nums1[i] 和 nums1[j] 不能是同一个元素。

#include "../normal.h"

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1, &nums2](const pair<int, int> & a, const pair<int, int> & b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>  pq(cmp);
        for (int i = 0; i < min(k, m); i++) {
            pq.emplace(i, 0);
        }
        while (k-- > 0 && !pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            ans.emplace_back(initializer_list<int>{nums1[x], nums2[y]});
            if (y + 1 < n) {
                pq.emplace(x, y + 1);
            }
        }

        return ans;
    }
};


int main(){
    Solution s;
    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};
    int k = 3;
    auto ans = s.kSmallestPairs(nums1, nums2, k);

    return 0;
}
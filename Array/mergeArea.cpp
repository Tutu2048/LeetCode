#include "../normal.h"
/*
*以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
*请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
*示例 1：
*
*输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
*输出：[[1,6],[8,10],[15,18]]
*解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
*示例 2：
*
*输入：intervals = [[1,4],[4,5]]
*输出：[[1,5]]
*解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。

 */

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> > &intervals) {
        if (intervals.empty()) return intervals;
        vector<vector<int> > res;
        sort(intervals.begin(), intervals.end());
        for (auto interval: intervals) {
            int left = interval[0];
            int right = interval[1];
            if (res.empty() || res.back()[1] < left) {
                res.emplace_back(vector<int>{left, right});
            }else{
                res.back()[1] = max(res.back()[1], right);
            }
        }
        return res;
   }

};

void print(vector<vector<int> > vec) {
    for (auto v: vec) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;
}

int main() {
    //简单的先排序后处理的思想
    vector<vector<int> > v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution s;
    print(s.merge(v));
}


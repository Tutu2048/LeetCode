#include <algorithm>
#include <bits/ranges_algo.h>

#include "../normal.h"
/*
*������ intervals ��ʾ���ɸ�����ļ��ϣ����е�������Ϊ intervals[i] = [starti, endi] ��
*����ϲ������ص������䣬������ һ�����ص����������飬��������ǡ�ø��������е��������� ��
*ʾ�� 1��
*
*���룺intervals = [[1,3],[2,6],[8,10],[15,18]]
*�����[[1,6],[8,10],[15,18]]
*���ͣ����� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].
*ʾ�� 2��
*
*���룺intervals = [[1,4],[4,5]]
*�����[[1,5]]
*���ͣ����� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣

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
    //�򵥵�����������˼��
    vector<vector<int> > v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution s;
    print(s.merge(v));
}


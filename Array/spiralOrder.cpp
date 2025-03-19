#include <algorithm>
#include <bits/ranges_algo.h>

#include "../normal.h"
/*
*给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
*示例 1：
*输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
*输出：[1,2,3,6,9,8,7,4,5]
*
*示例 2：
*输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
*输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 */
enum{
  	Right,
	Down,
    Left,
  	Up
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
     	if(matrix.empty() || matrix[0].empty()) return {};

        vector<int> ret;
        vector<vector<int>> tmp=matrix;
        while(!tmp.empty()) {
            ret.insert(ret.end(),tmp[0].begin(),tmp[0].end());
            tmp.erase(tmp.begin());
            spinArray(tmp);
        }
        return ret;
    }

    void spinArray(vector<vector<int>>& v) {
        vector<vector<int>> ret;
        if (v.empty() || v[0].empty()) return ;
        int rows = v.size();//行数
        int lines = v[0].size();//列数
        for(int i=lines-1;i>=0;--i){
            vector<int> tmp;
            for(int j=0;j<rows;++j) {
                tmp.push_back(v[j][i]);
            }
            ret.push_back(tmp);
        }
        v.clear();
        v.swap(ret);
        // for(auto x:ret) {
            // v.push_back(x);
        // }
    }
};

void print(vector<vector<int> > vec) {
    cout<<"[";
    for (auto v: vec) {
        cout << "[";
        for (int i = 0; i < v.size(); ++i) {
            if (i != v.size() - 1) {
                cout << v[i] << " ";
            } else {
                cout << v[i] << "]";
            }
        }
    }
    cout << "]" << endl;
}

int main() {
    //操作(旋转)数组的代价太大
    //TODO:模拟法这种截图  辅助数组visted[][] 和方向数组[0,1][-1,0][0,-1][1,0] 代表向左、向下、向右、向上
    //用4个指针来控制遍历，是该题的效率解
    vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    print(v);
    Solution s;
    auto x= s.spiralOrder(v);
    for(auto a: x) {
        cout <<a<<",";
    }

}


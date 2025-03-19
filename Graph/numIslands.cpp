/*
200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

示例 1：
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1

示例 2：
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3


提示：
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'
*/
#include "../normal.h"
class Solution {
public:
    int numIslands(vector<vector<char> > &grid) {

        int num = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                    if(grid[i][j] == '1') {
                        mergeOneIsland(grid,i,j);
                        num++;
                    }
                }
            }
        return num;
    }

    void mergeOneIsland(vector<vector<char> > &grid,int i,int j) {
        //置零操作
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        mergeOneIsland(grid, i - 1, j);
        mergeOneIsland(grid, i + 1, j);
        mergeOneIsland(grid, i, j - 1);
        mergeOneIsland(grid, i, j + 1);
    }
};
int mian() {
    //题目抽象：将一片连续的“1”即为一座岛屿
    //技巧：搜索+剪枝 深度搜索相邻的“1”,并将其置为“0”
}

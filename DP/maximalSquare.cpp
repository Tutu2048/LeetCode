// 2025-03-26 09:55:03
// 221 最大正方形 
//在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

// 示例 1：
//输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"]
//,["1","0","0","1","0"]]
//输出：4
// 
// 示例 2：
//输入：matrix = [["0","1"],["1","0"]]
//输出：1
// 
// 示例 3：
//输入：matrix = [["0"]]
//输出：0
//
// 提示： 
// m == matrix.length
// n == matrix[i].length 
// 1 <= m, n <= 300 
// matrix[i][j] 为 '0' 或 '1' 
//


#include "../normal.h"
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
            int rows = matrix.size(), cols = matrix[0].size();
    
            vector<vector<int>> dp(rows, vector<int>(cols, 0));
            int maxSide = 0;
            for (int i = 0; i < rows; ++i){
                for (int j = 0; j < cols; ++j){
                    if (matrix[i][j] == '0')  continue;
    
                    if (i == 0 || j == 0){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    }
    
                    maxSide = max(maxSide, dp[i][j]);
                }
            }

            return maxSide*maxSide;
        }
     };
// leetcode submit region end(Prohibit modification and deletion)

     int main()
     {
         // 思路递进：
         // 1.暴力求解法，遍历每个节点作为左上角的节点，然后向下向右搜索1
         // 2.暴力方式会有很多重复搜索，如何复用原先的搜索结果呢？
         // 动态规划：遍历每个节点作为正方形的右下角，若为1 ，则搜索 左、上、左上 3个节点 是否为正方形，都为正方形则可以拼成一个更大的正方形

         // 测试用例 边长为200的正方形，全为1
         vector<vector<char>> matrix(200, vector<char>(200, '1'));
         Solution s;
         cout << s.maximalSquare(matrix) << endl;

         return 0;
     }

     // 下列这种方式想要省去dp的开销，但是若边长大于char的表达范围，会出现错误
     // class Solution
     // {
     // public:
     //     int maximalSquare(vector<vector<char>> &matrix)
     //     {
     //         if (matrix.size() == 0 || matrix[0].size() == 0)
     //             return 0;

     //         int maxSide = 0; // 修改为 int 类型
     //         for (int i = 0; i < matrix.size(); ++i)
     //         {
     //             for (int j = 0; j < matrix[0].size(); ++j)
     //             { // 修复循环变量
     //                 if (matrix[i][j] == '0')
     //                     continue; // 修复类型比较

     //                 int left = 0, up = 0, lu = 0;
     //                 if (i - 1 >= 0 && j - 1 >= 0)
     //                 {
     //                     left = matrix[i][j - 1] - '0';                // 转换为整数
     //                     up = matrix[i - 1][j] - '0';                  // 转换为整数
     //                     lu = matrix[i - 1][j - 1] - '0';              // 转换为整数
     //                     matrix[i][j] = min({left, up, lu}) + 1 + '0'; // 转换回字符
     //                 }
     //                 maxSide = max(maxSide, matrix[i][j] - '0'); // 转换为整数
     //             }
     //         }

     //         return maxSide * maxSide;
     //     }
     // };
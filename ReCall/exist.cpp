//
// Created by 18122252978 on 2025/3/7.
//
#include "../normal.h"
/*
* 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例 1：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true

示例 2：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
输出：true

示例 3：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
输出：false

提示：
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board 和 word 仅由大小写英文字母组成
 */

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (word.empty() || board.empty()) return false;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (existHelper(i,j,0,word,board)) return true;
            }
        }
        return false;
    }

    bool existHelper(int i, int j, int index, string word, vector<vector<char> > &board) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()
            || word[index] != board[i][j])
            return false;
        //减枝，访问过的节点，在该次递归时，不应该被再次访问
        board[i][j] = '0';
        if(index == word.size()-1) return true;
        bool res=existHelper(i - 1, j, index+1, word, board)||existHelper(i, j-1, index+1, word, board)
            ||existHelper(i + 1, j, index+1, word, board)||existHelper(i, j + 1, index+1, word, board);

        board[i][j] = word[index];

        return res;
    }
};

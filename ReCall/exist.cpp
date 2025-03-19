//
// Created by 18122252978 on 2025/3/7.
//
#include "../normal.h"
/*
* ����һ�� m x n ��ά�ַ����� board ��һ���ַ������� word ����� word �����������У����� true �����򣬷��� false ��

���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�

ʾ�� 1��
���룺board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
�����true

ʾ�� 2��
���룺board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
�����true

ʾ�� 3��
���룺board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
�����false

��ʾ��
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board �� word ���ɴ�СдӢ����ĸ���
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
        //��֦�����ʹ��Ľڵ㣬�ڸôεݹ�ʱ����Ӧ�ñ��ٴη���
        board[i][j] = '0';
        if(index == word.size()-1) return true;
        bool res=existHelper(i - 1, j, index+1, word, board)||existHelper(i, j-1, index+1, word, board)
            ||existHelper(i + 1, j, index+1, word, board)||existHelper(i, j + 1, index+1, word, board);

        board[i][j] = word[index];

        return res;
    }
};

#include "../normal.h"
/* 有效的数独
* 请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
* 数字 1-9 在每一行只能出现一次。
* 数字 1-9 在每一列只能出现一次。
* 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<multiset<char>> rows(9);
        vector<multiset<char>> ranks(9);
        vector<multiset<char>> smallSudo(9);
        //插入
        for(int x=0;x<9;++x){
            for(int y=0;y<9;++y) {
                char c = board[x][y];
                if(c != '.' && rows[x].contains(c)){}
                rows[x].insert(c);
                ranks[y].insert(c);
                int index = (x/3) * 3 + (y/3);
                smallSudo[index].insert(c);
            }
        }

        //检查
        for(auto x:smallSudo) {
            for (char i = '1'; i <= '9'; ++i) {
                if(x.count(i)>=2) {
                    return false;
                }
            }
        }
        for(auto x:rows) {
            for (char i = '1'; i <= '9'; ++i) {
                if(x.count(i)>=2) {
                    return false;
                }
            }
        }
        for(auto x:ranks) {
            for (char i = '1'; i <= '9'; ++i) {
                if(x.count(i)>=2) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    //时间复杂度 O（logn） 空间复杂度O（1）
    //时间复杂度受限于multiset的count速度
    //设计二维数组 int row[9][9]=0; x为行号 y为存在的数字 value为出现的次数
    //如此对于数量的检查遍历可以脱离count限制，将时间复杂度降至O(1)
    //https://leetcode.cn/problems/valid-sudoku/solutions/1001859/you-xiao-de-shu-du-by-leetcode-solution-50m6/?envType=study-plan-v2&envId=top-interview-150

    return 0;
}

#include "../normal.h"
/* ��Ч������
* �����ж�һ�� 9 x 9 �������Ƿ���Ч��ֻ��Ҫ �������¹��� ����֤�Ѿ�����������Ƿ���Ч���ɡ�
* ���� 1-9 ��ÿһ��ֻ�ܳ���һ�Ρ�
* ���� 1-9 ��ÿһ��ֻ�ܳ���һ�Ρ�
* ���� 1-9 ��ÿһ���Դ�ʵ�߷ָ��� 3x3 ����ֻ�ܳ���һ�Ρ�
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<multiset<char>> rows(9);
        vector<multiset<char>> ranks(9);
        vector<multiset<char>> smallSudo(9);
        //����
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

        //���
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
    //ʱ�临�Ӷ� O��logn�� �ռ临�Ӷ�O��1��
    //ʱ�临�Ӷ�������multiset��count�ٶ�
    //��ƶ�ά���� int row[9][9]=0; xΪ�к� yΪ���ڵ����� valueΪ���ֵĴ���
    //��˶��������ļ�������������count���ƣ���ʱ�临�ӶȽ���O(1)
    //https://leetcode.cn/problems/valid-sudoku/solutions/1001859/you-xiao-de-shu-du-by-leetcode-solution-50m6/?envType=study-plan-v2&envId=top-interview-150

    return 0;
}

/*
200. ��������
����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������
�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�����/����ֱ���������ڵ�½�������γɡ�
���⣬����Լ��������������߾���ˮ��Χ��

ʾ�� 1��
���룺grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
�����1

ʾ�� 2��
���룺grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
�����3


��ʾ��
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] ��ֵΪ '0' �� '1'
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
        //�������
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
    //��Ŀ���󣺽�һƬ�����ġ�1����Ϊһ������
    //���ɣ�����+��֦ ����������ڵġ�1��,��������Ϊ��0��
}

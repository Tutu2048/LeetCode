#include <algorithm>
#include <bits/ranges_algo.h>

#include "../normal.h"
/*
*����һ�� m �� n �еľ��� matrix ���밴�� ˳ʱ������˳�� �����ؾ����е�����Ԫ�ء�
*ʾ�� 1��
*���룺matrix = [[1,2,3],[4,5,6],[7,8,9]]
*�����[1,2,3,6,9,8,7,4,5]
*
*ʾ�� 2��
*���룺matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
*�����[1,2,3,4,8,12,11,10,9,5,6,7]
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
        int rows = v.size();//����
        int lines = v[0].size();//����
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
    //����(��ת)����Ĵ���̫��
    //TODO:ģ�ⷨ���ֽ�ͼ  ��������visted[][] �ͷ�������[0,1][-1,0][0,-1][1,0] �����������¡����ҡ�����
    //��4��ָ�������Ʊ������Ǹ����Ч�ʽ�
    vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    print(v);
    Solution s;
    auto x= s.spiralOrder(v);
    for(auto a: x) {
        cout <<a<<",";
    }

}


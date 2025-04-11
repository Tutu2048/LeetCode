//51. N 皇后
//按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
//每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
//
//示例 1：
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。

//示例 2：
//输入：n = 1
//输出：[["Q"]]
//
//提示：
//1 <= n <= 9

#include "../normal.h"
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        for(int i=0;i<n;++i){
            vector<string> tmp(n,string(n,'.'));
            tmp[0][i] = 'Q';
            helper(tmp,1,n);

            //恢复原有样子，节省vector创销毁
            //tmp[0][i] = '.';
        }
        return _res;
    }

private:
    void helper(vector<string>& s,int nLayer,int n){
        if(nLayer == n)  _res.push_back(s);

        for(int i=0;i < n; ++i){
            if(!isValid(s,nLayer,i)) {
                continue;
            }

            s[nLayer][i] = 'Q';
            helper(s,nLayer+1,n);
            //找到一个解后，恢复，该层状态,搜索是否还有别的解
            s[nLayer][i] = '.';
        }
    }

    bool isValid(vector<string>& s , int x, int y){
        //由于是从上至下搜索，所以只需要向上检查是否有效
        int n = s.size();
        //横向在上一层已经保证唯一
        //竖向
        for(int i =0;i<x;++i){
            if(s[i][y] == 'Q') return false;
        }

        //右上斜线
        for(int i=x-1,j=y+1;i>=0 && j<n;--i,++j){
            if(s[i][j] =='Q') return false;
        }

        //左斜线
        for(int i=x-1,j=y-1;i>=0 && j>=0;--i,--j){
            if(s[i][j] =='Q') return false;
        }

        return true;
    }

    vector<vector<string>> _res;
};

int main(){
    //n*n 放n个也就意味这每行都要放一个
    Solution s;
    auto ret = s.solveNQueens(4);
    for(auto& vec:ret){
        for(auto& str:vec){
            for(int i=0;i<str.size();++i){
                cout<<str[i]<<" ";
            }
            cout <<endl;
        }
        cout<<"-----------------"<<endl;
    }
    return 0;
}
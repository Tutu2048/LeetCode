// 2025-03-31 10:54:07
// 212 单词搜索 II 
//给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words， 返回所有二维网格上的单词 。 
//
// 单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使
//用。 
//
// 示例 1： 
//输入：board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f",
//"l","v"]], words = ["oath","pea","eat","rain"]
//输出：["eat","oath"]
// 
//
// 示例 2： 
//输入：board = [["a","b"],["c","d"]], words = ["abcb"]
//输出：[]
//
// 提示： 
// m == board.length 
// n == board[i].length 
// 1 <= m, n <= 12 
// board[i][j] 是一个小写英文字母 
// 1 <= words.length <= 3 * 10⁴ 
// 1 <= words[i].length <= 10 
// words[i] 由小写英文字母组成 
// words 中的所有字符串互不相同 
//
// Related Topics 字典树 数组 字符串 回溯 矩阵 👍 935 👎 0

#include "../normal.h"
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty()) return vector<string>();
        vector<string> ret;
        int size=0;
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                for(string& word:words){
                    if(findWordsHelp(board,i,j,0,word)){
                        ret.push_back(word); 
                    }
                }
                if(ret.size() >size){
                    size = ret.size();
                    for(int k=0;k<size;++k){
                        auto it = find(words.begin(),words.end(),ret[k]);
                        if(it != words.end()){
                            words.erase(it);
                        }
                    }
                }
            }
        }
        return ret;
        
    }
    bool findWordsHelp(vector<vector<char>> &board,int i,int j,int index,string word){
        if(i<0 ||j<0||i>=board.size()||j>=board[0].size()||word[index]!=board[i][j])    return false;
        if(index +1 ==word.size()) return true;
        board[i][j]='0';
        bool ret= findWordsHelp(board, i+1,j,index+1,word)
                || findWordsHelp(board, i-1,j,index+1,word)
                || findWordsHelp(board, i,j+1,index+1,word)
                || findWordsHelp(board, i,j-1,index+1,word);

        board[i][j] = word[index];
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main(){
    vector<int> a = {1,2,3,4,5};
    for(auto it=a.begin();it!=a.end();){
        it=a.erase(it);
    }
    for(auto it=a.begin();it!=a.end();++it){
        cout << *it << " "; 
    }

}
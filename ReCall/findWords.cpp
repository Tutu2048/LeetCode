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
class Trie {
public:
    Trie():_children(26, nullptr) {

    }

    void insert(string word) {
        Trie* tmp =this;
        for(char& ch:word){
            int index = ch -'a';
            if(!tmp->_children[index]){
                tmp->_children[index]= new Trie();
            }
            tmp =tmp->_children[index];
        }
        tmp->_word = word;
    }

    vector<Trie *>  _children;
//    bool _end=false;
    string _word;//因为需要直接插入该节点的路径，所以使用word来替代_end,如果有word就表示，到该节点是一个插入的word
};

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

    void findWordsHelp(vector<vector<char>> &board,int i,int j,Trie * root,set<string>& res){
        char ch = board[i][j];
        int index = ch -'a';

        if(!root->_children[index]){
            return ;
        }

        auto pre =root;
        root = root->_children[index];
        if(!root->_word.empty()){
            res.insert(root->_word);
        }

        board[i][j]='0';
        for(int k=0;k<4;++k){
            int nx = i +_dir[k][0];
            int ny = j +_dir[k][1];
            if(nx >=0 &&ny >=0 &&nx<board.size() && ny<board[0].size() && board[nx][ny] != '0'){
                findWordsHelp(board,nx,ny,root,res);
            }
        }

        board[i][j] = ch;
    }

    vector<string> findWords2(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty()) return vector<string>();
        set<string> ret;

        for(auto& word:words){
            _add.insert(word);
        }

        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                findWordsHelp(board,i,j,&_add,ret);
            }
        }

        return vector<string>(ret.begin(),ret.end());
    }
private:
    int _dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    Trie _add;
};

//leetcode submit region end(Prohibit modification and deletion)
int main(){
    //当words 出现大量前缀时，会出现很多冗余的搜索
    //可以在搜索到之后进行标记 or 删除trie的操作来减少搜索次数(删除操作需要使用map来构建trie会更加好)
    Solution s;
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    auto ret = s.findWords2(board, words);
    for(auto& str:ret){
        cout<<str<<endl;
    }


}
// 2025-04-07 11:19:34
// 290 单词规律
//给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
//
// 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。
// 示例1:
//输入: pattern = "abba", s = "dog cat cat dog"
//输出: true
//
// 示例 2:
//输入:pattern = "abba", s = "dog cat cat fish"
//输出: false
//
// 示例 3:
//输入: pattern = "aaaa", s = "dog cat cat dog"
//输出: false
//
// 提示:
// 1 <= pattern.length <= 300
// pattern 只包含小写英文字母
// 1 <= s.length <= 3000
// s 只包含小写英文字母和 ' '
// s 不包含 任何前导或尾随对空格
// s 中每个单词都被 单个空格 分隔



#include "../normal.h"
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool wordPattern(string pattern, string s) {
      map<char, string> _mc2s;
      map<string, char> _ms2c;
      std::stringstream ss(s);
      for(char& ch:pattern){
        string word;
        if(ss.eof()) return false;
        ss>>word;
        if(_mc2s.find(ch) == _mc2s.end()){
          _mc2s[ch] = word;
          if(_ms2c.find(word) != _ms2c.end())  return false;

          _ms2c[word] = ch;
          continue;
        }

        if(_mc2s[ch] != word || _ms2c[word] != ch){ return false; }
        }

      return ss.eof();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


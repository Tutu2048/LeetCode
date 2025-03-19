#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
using namespace  std;

/*给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。

另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。

返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替代这个答案。

注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。

注意：未在等式列表中出现的变量是未定义的，因此无法确定它们的答案。

示例 1：

输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
解释：
条件：a / b = 2.0, b / c = 3.0
问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
注意：x 是未定义的 => -1.0*/

class Graph {
public:
    unordered_map<string ,vector<pair<string,double>>> _graph;
    //生成邻接矩阵
    Graph(vector<vector<string> > &verties, vector<double> value): _graph() {
        for(int i = 0; i < verties.size(); i++) {
            auto& pair = verties[i];
            _graph[pair[0]].emplace_back(pair[1],value[i]);
            _graph[pair[1]].emplace_back(pair[0],1.0/value[i]);
        }
    }

    void print() {
        for(auto it = _graph.begin(); it != _graph.end(); it++) {
            cout << it->first << ": ";
            for(auto x:it->second) {
                cout << x.first << "(" <<x.second<<") ";
            }
            cout<<endl;
        }

    }

    //如果返回遍历顺序vector也行，只不过需要再遍历一遍vector和graph
    double dfsHelper(unordered_set<string> &visted,string& startV,string& endV) {
        if(_graph.find(startV) == _graph.end()||_graph.find(endV) == _graph.end()) {
            cout << "don't find "<<startV << endl;
            return -1.0;
        }
        if(startV == endV) {return 1;}

        visted.insert(startV);
        for (auto &V: _graph.at(startV)) {
            if(visted.count(V.first)) {continue;}
            if(V.first == endV) {
                return V.second;
            }
            //由于题目规定value>0,所以可以用返回值正负进行判断
            //编写Tip：把dfsHelper递归函数当成普通函数进行理解，
            //·若搜索未发现end，则舍弃其返回值。
            //·若搜索发现，则采用其返回值
            auto ret= dfsHelper(visted, V.first, endV);
            if(ret>0)
                return V.second *ret;
        }

        return -1.0;
    }

    vector<double> dfs(vector<vector<string> > &queries) {
        vector<double> result;
        for(vector<string> x:queries) {
            unordered_set<string> visted(0);
            result.push_back(dfsHelper(visted,x[0],x[1]));
        }
        return result;
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        Graph g(equations,values);
        g.print();
        return g.dfs(queries);
    }
};


int main() {
    vector<vector<string> > equations = {{"x1", "x2"}, {"x2", "x3"}, {"x3", "x4"}, {"x4", "x5"}};
    vector<double> values = {3.0, 4.0, 5.0, 6.0};
    vector<vector<string> > queries = {
        {"x1", "x5"}, {"x5", "x2"}, {"x2", "x4"}, {"x2", "x2"}, {"x2", "x9"}, {"x9", "x9"}
    };
    Solution s;
    auto xx = s.calcEquation(equations, values, queries);
    for (auto x: xx) {
        cout << x << " ";
    }
    cout << endl;

    //TODO: 本题：特解 通过树结构实现--并查集--结构

    /*类型：图 同类型练习
    *「力扣」第 547 题：省份数量（中等）；
    *「力扣」第 684 题：冗余连接（中等）；
    *「力扣」第 1319 题：连通网络的操作次数（中等）；
    *「力扣」第 1631 题：最小体力消耗路径（中等）；
    *「力扣」第 959 题：由斜杠划分区域（中等）；
    *「力扣」第 1202 题：交换字符串中的元素（中等）；
    *「力扣」第 947 题：移除最多的同行或同列石头（中等）；
    *「力扣」第 721 题：账户合并（中等）；
    *「力扣」第 803 题：打砖块（困难）；
    *「力扣」第 1579 题：保证图可完全遍历（困难）;
    *「力扣」第 778 题：水位上升的泳池中游泳（困难）。
    */
    //主要考察对题目的抽象能力
    return 0;
}

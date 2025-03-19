#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
using namespace  std;

/*����һ������������ equations ��һ��ʵ��ֵ���� values ��Ϊ��֪���������� equations[i] = [Ai, Bi] �� values[i] ��ͬ��ʾ��ʽ Ai / Bi = values[i] ��ÿ�� Ai �� Bi ��һ����ʾ�����������ַ�����

����һЩ������ queries ��ʾ�����⣬���� queries[j] = [Cj, Dj] ��ʾ�� j �����⣬���������֪�����ҳ� Cj / Dj = ? �Ľ����Ϊ�𰸡�

���� ��������Ĵ� ���������ĳ���޷�ȷ���Ĵ𰸣����� -1.0 �������𰸡���������г����˸�������֪������û�г��ֵ��ַ�����Ҳ��Ҫ�� -1.0 �������𰸡�

ע�⣺����������Ч�ġ�����Լ�����������в�����ֳ���Ϊ 0 ��������Ҳ������κ�ì�ܵĽ����

ע�⣺δ�ڵ�ʽ�б��г��ֵı�����δ����ģ�����޷�ȷ�����ǵĴ𰸡�

ʾ�� 1��

���룺equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
�����[6.00000,0.50000,-1.00000,1.00000,-1.00000]
���ͣ�
������a / b = 2.0, b / c = 3.0
���⣺a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
�����[6.0, 0.5, -1.0, 1.0, -1.0 ]
ע�⣺x ��δ����� => -1.0*/

class Graph {
public:
    unordered_map<string ,vector<pair<string,double>>> _graph;
    //�����ڽӾ���
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

    //������ر���˳��vectorҲ�У�ֻ������Ҫ�ٱ���һ��vector��graph
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
            //������Ŀ�涨value>0,���Կ����÷���ֵ���������ж�
            //��дTip����dfsHelper�ݹ麯��������ͨ����������⣬
            //��������δ����end���������䷵��ֵ��
            //�����������֣�������䷵��ֵ
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

    //TODO: ���⣺�ؽ� ͨ�����ṹʵ��--���鼯--�ṹ

    /*���ͣ�ͼ ͬ������ϰ
    *�����ۡ��� 547 �⣺ʡ���������еȣ���
    *�����ۡ��� 684 �⣺�������ӣ��еȣ���
    *�����ۡ��� 1319 �⣺��ͨ����Ĳ����������еȣ���
    *�����ۡ��� 1631 �⣺��С��������·�����еȣ���
    *�����ۡ��� 959 �⣺��б�ܻ��������еȣ���
    *�����ۡ��� 1202 �⣺�����ַ����е�Ԫ�أ��еȣ���
    *�����ۡ��� 947 �⣺�Ƴ�����ͬ�л�ͬ��ʯͷ���еȣ���
    *�����ۡ��� 721 �⣺�˻��ϲ����еȣ���
    *�����ۡ��� 803 �⣺��ש�飨���ѣ���
    *�����ۡ��� 1579 �⣺��֤ͼ����ȫ���������ѣ�;
    *�����ۡ��� 778 �⣺ˮλ������Ӿ������Ӿ�����ѣ���
    */
    //��Ҫ�������Ŀ�ĳ�������
    return 0;
}

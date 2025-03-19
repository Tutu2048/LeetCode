

#include "../normal.h"
/*
* 给定一个二叉树：
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 nullptr 。
初始状态下，所有 next 指针都被设置为 nullptr 。

示例 1：

输入：root = [1,2,3,4,5,nullptr,7]
输出：[1,#,2,3,#,4,5,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化输出按层序遍历顺序（由 next 指针连接），'#' 表示每层的末尾。
示例 2：

输入：root = []
输出：[]*/

struct Node :public TreeNode{
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node():left(nullptr), right(nullptr){}
    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        if(!root) return root;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();//不能直接用于for判断，因为对队列有增删操作
            Node *pre = nullptr;
            for (int i = 0; i <size ; ++i) {
                Node *cur = q.front();
                q.pop();
                if (pre) {
                    pre->next = cur;
                }
                pre = cur;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        return root;
    }

    Node *connect2(Node *root) {
        Node *cur = root;
        Node *levelCur = nullptr;
        Node *levelHead= nullptr;//层序 每层的第一个
        while(cur) {
            if(!levelHead) {
                if (cur->left) { levelHead = cur->left; }
                else if (cur->right) { levelHead = cur->right; }
                levelCur = levelHead;
                if(cur->left&&cur->right) {
                    levelCur->next = cur->right;
                    levelCur = levelCur->next;
                }
            }else {
                if (cur->left) {
                    levelCur->next = cur->left;
                    levelCur = levelCur->next;
                }
                if (cur->right) {
                    levelCur->next = cur->right;
                    levelCur = levelCur->next;
                }
            }

            if(cur->next)
                cur = cur->next;
            else {
                cur = levelHead;
                levelHead =nullptr;
                levelCur = nullptr;
            }
        }

        return root;
    }
};

// Node* buileTree(vector<int> v) {
// int root=0;
// for(auto x:v) {
// Node *root = new Node(x);
// if(!x)
// Node *root = new Node(x);
// }

// }


int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    Solution test;
    // test.connect(root);
    test.connect2(root);


    //法一：常见思路，用队列实现层序遍历
    //法二：特殊思路，减小空间复杂度，利用next指针来实现层序遍历
}

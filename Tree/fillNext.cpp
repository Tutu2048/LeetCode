

#include "../normal.h"
/*
* ����һ����������
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
�������ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ㡣����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ nullptr ��
��ʼ״̬�£����� next ָ�붼������Ϊ nullptr ��

ʾ�� 1��

���룺root = [1,2,3,4,5,nullptr,7]
�����[1,#,2,3,#,4,5,7,#]
���ͣ�������������ͼ A ��ʾ����ĺ���Ӧ���������ÿ�� next ָ�룬��ָ������һ���Ҳ�ڵ㣬��ͼ B ��ʾ�����л�������������˳���� next ָ�����ӣ���'#' ��ʾÿ���ĩβ��
ʾ�� 2��

���룺root = []
�����[]*/

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
            int size = q.size();//����ֱ������for�жϣ���Ϊ�Զ�������ɾ����
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
        Node *levelHead= nullptr;//���� ÿ��ĵ�һ��
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


    //��һ������˼·���ö���ʵ�ֲ������
    //����������˼·����С�ռ临�Ӷȣ�����nextָ����ʵ�ֲ������
}

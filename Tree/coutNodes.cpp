/*222. ��ȫ�������Ľڵ����
*����һ�� ��ȫ������ �ĸ��ڵ� root ����������Ľڵ������
*
*��ȫ������ �Ķ������£�����ȫ�������У�������ײ�ڵ����û�����⣬����ÿ��ڵ������ﵽ���ֵ��
*����������һ��Ľڵ㶼�����ڸò�����ߵ�����λ�á�����ײ�Ϊ�� h �㣨�ӵ� 0 �㿪ʼ������ò���� 1~ 2^h ���ڵ㡣
*/

#include "../normal.h"
class Solution {
public:
    int countNodes(TreeNode* root) {
        //�������һ��
        queue<TreeNode*> q;

        if(!root) return 0;
        q.push(root);
        int count=0;
        while(!q.empty()) {
            root =q.front();
            q.pop();
            ++count;

            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }

        return count;
    }
};
int mian() {
    //�ٷ��� �����ֲ���+λ���㣡?


}
//
// Created by 18122252978 on 2025/2/14.
//

#ifndef NORMAL_H
#define NORMAL_H

#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <math.h>
#include <queue>
#include <map>
#include <algorithm>
using namespace  std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode():left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};


#endif //NORMAL_H

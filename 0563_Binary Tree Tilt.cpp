#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Runtime: 36 ms, faster than 26.43% of C++ online submissions for Binary Tree Tilt.
// Memory Usage: 23.7 MB, less than 75.76% of C++ online submissions for Binary Tree Tilt.
class Solution {
public:
    int total; 
    int findTilt(TreeNode* root) {
        total = 0;
        readNode(root);
        return total;
    }
    int readNode(TreeNode* node)
    {
        if(node==nullptr) return 0;
        int leftdif = readNode(node->left);
        int rightdif = readNode(node->right);
        total += abs(leftdif - rightdif);
        return node->val + leftdif + rightdif;

    }
};
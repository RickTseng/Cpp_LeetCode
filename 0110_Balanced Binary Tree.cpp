#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Runtime: 27 ms, faster than 21.44% of C++ online submissions for Balanced Binary Tree.
// Memory Usage: 20.9 MB, less than 80.93% of C++ online submissions for Balanced Binary Tree.
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool res = true;
        int temp = checkBalance(root,res);
        return res;
    }
    int checkBalance(TreeNode* node,bool &jdg){
        if(node == nullptr) return 0;
        if(!jdg) return 0;
        int leftNode = checkBalance(node->left,jdg);
        int rightNode = checkBalance(node->right,jdg);
        if(abs(leftNode-rightNode) > 1){
            jdg = false;
        }
        return 1 + max(leftNode, rightNode);
    }
};
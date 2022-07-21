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

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Ref Gujjushroud
// 0 false
// 1 true
// 2 or
// 3 and
class Solution
{
public:
    bool evaluateTree(TreeNode *root)
    {
        if(!root->left && !root->right) return root->val;
        
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        
        if(root->val == 2) return left || right;
        
        return left && right;
    }
    
};
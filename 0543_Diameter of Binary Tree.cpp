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
//Accept 220617
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int di = 0;
        readNode(root,di);
        return di;
    }
    int readNode(TreeNode* node, int &di){
        if(node == nullptr) return 0;
        int lnode = readNode(node->left,di);
        int rnode = readNode(node->right,di);
        di = max(di,lnode+rnode);
        return max(lnode,rnode) + 1;
    }
};
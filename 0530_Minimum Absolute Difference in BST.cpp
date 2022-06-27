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
//****Accept *******///
class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {

        int min_dif = INT_MAX,val = -1;
        return readNode(root,val,min_dif);
    }
    int readNode(TreeNode *node,int &val,int &min_dif)
    {
        if (node->left != nullptr)
            readNode(node->left, val, min_dif);
        if (val >= 0)
            min_dif = min(min_dif, node->val - val);
        val = node->val;
        if (node->right != nullptr)
            readNode(node->right, val, min_dif);
        return min_dif;
    }
};
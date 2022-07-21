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

// Runtime: 21 ms, faster than 80.17% of C++ online submissions for Kth Smallest Element in a BST.
// Memory Usage: 28.9 MB, less than 16.28% of C++ online submissions for Kth Smallest Element in a BST.

class Solution
{
public:
    vector<int> valTb;
    int kthSmallest(TreeNode *root, int k)
    {
        valTb.resize(1e4+1,0);
        readProcess(root);
        for(int idx = 0;idx<valTb.size();++idx)
        {
            k-=valTb[idx];
            if(k<=0)
            {
                return idx;
            }
        }
        return -1;
    }
    void readProcess(TreeNode *node)
    {
        if(node==nullptr) return;
        valTb[node->val]++;
        readProcess(node->left);
        readProcess(node->right);
    }
};
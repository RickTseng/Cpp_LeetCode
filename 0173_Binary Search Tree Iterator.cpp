#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <stack>
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

// Ref xcv58
// Runtime: 32 ms, faster than 86.50% of C++ online submissions for Binary Search Tree Iterator.
// Memory Usage: 24.1 MB, less than 54.54% of C++ online submissions for Binary Search Tree Iterator.

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        buildStack(root);
    }
    
    int next() 
    {
        TreeNode *tmpNode = treeStack.top();
        treeStack.pop();
        buildStack(tmpNode->right);
        return tmpNode->val;
    }
    
    bool hasNext() 
    {
        return !treeStack.empty();
    }
private:
    stack<TreeNode *> treeStack;
    void buildStack(TreeNode *node)
    {
        if(node==nullptr) return;
        treeStack.push(node);
        buildStack(node->left);
    }
};
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

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int depth = 1,_min = 100001;
        readNode(root,depth,_min);
        return _min;
    }
    void readNode(TreeNode *node, int depth,int &_min){
        if(node == nullptr){
            return;
        }
        if(node->left == nullptr && node->right == nullptr)
        {
            _min = min(_min,depth);
            return;
        }
        readNode(node->left,depth + 1,_min);
        readNode(node->right,depth + 1,_min);
    }
};
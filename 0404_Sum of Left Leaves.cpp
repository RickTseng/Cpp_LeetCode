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
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        read(root,sum);
        return sum;
    }
    void read(TreeNode *node,int &sum){
        if(node->left == nullptr && node->right == nullptr)
        {
            return;
        }
        if(node->left!=nullptr && node->left->left == nullptr && node->left->right == nullptr)
        {
            sum+=node->left->val;
        }
        if(node->left!=nullptr){
            read(node->left,sum);
        }
        if(node->right!=nullptr){
            read(node->right,sum);
        }
        

    }

};
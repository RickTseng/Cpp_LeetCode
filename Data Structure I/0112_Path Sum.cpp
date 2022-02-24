#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        bool hasSum = false;
        if (root != NULL)
        {
            if (!root->left && !root->right)
            {
                if (root->val == targetSum)
                {
                    return true;
                }
            }
            if (!hasSum && root->left != NULL)
            {
                searchPath(root->left, root->val, targetSum, hasSum);
            }
            if (!hasSum && root->right != NULL)
            {
                searchPath(root->right, root->val, targetSum, hasSum);
            }
        }

        return hasSum;
    }
    void searchPath(TreeNode *node, int count, int targetSum, bool &hasSum)
    {
        if (!node->left && !node->right)
        {
            if (count + node->val == targetSum)
            {
                hasSum = true;
            }
            return;
        }
        if (!hasSum && node->left != NULL)
        {
            searchPath(node->left, count + node->val, targetSum, hasSum);
        }
        if (!hasSum && node->right != NULL)
        {
            searchPath(node->right, count + node->val, targetSum, hasSum);
        }
    }
};
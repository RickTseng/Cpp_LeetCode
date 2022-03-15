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
    bool validate(TreeNode *root, TreeNode *low, TreeNode *high)
    {
        // Empty trees are valid BSTs.
        if (root == nullptr)
        {
            return true;
        }

        // The current node's value must be between low and high.     
        if ((low != nullptr && root->val <= low->val) || (high != nullptr && root->val >= high->val))
        {
            return false;
        }
        int rootVal = root->val;

        // The left and right subtree must also be valid.
        return validate(root->right, root, high) && validate(root->left, low, root);
    }

    bool isValidBST(TreeNode *root)
    {
        return validate(root, nullptr, nullptr);
    }
    bool isValidBST_org(TreeNode *root)
    {
        bool res = true;
        // pq.push(root->val);
        leftValid(root->left, root->val, res);
        rightValid(root->right, root->val, res);
        return res;
    }
    void leftValid(TreeNode *node, int target, bool &res)
    {
        if (node == nullptr)
        {
            return;
        }
        if (node->val >= target)
        {
            res = false;
            return;
        }
        if (res)
        {
            leftValid(node->left, node->val, res);
        }
        if (res)
        {
            rightValid(node->right, node->val, res);
        }
    }
    void rightValid(TreeNode *node, int target, bool &res)
    {
        if (node == nullptr)
        {
            return;
        }
        if (node->val <= target)
        {
            res = false;
            return;
        }
        if (res)
        {
            leftValid(node->left, node->val, res);
        }
        if (res)
        {
            rightValid(node->right, node->val, res);
        }
    }
};
int main()
{
    TreeNode *root = new TreeNode(3, new TreeNode(1, new TreeNode(0), new TreeNode(2)), new TreeNode(4, NULL, new TreeNode(5)));
    Solution sol;
    bool ans = sol.isValidBST(root);
}
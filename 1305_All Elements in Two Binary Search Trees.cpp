#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
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
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> arr;
        readTree(root1,arr);
        readTree(root2,arr);
        sort(arr.begin(),arr.end());
        return arr;
    }
    void readTree(TreeNode* node,vector<int> &arr)
    {
        if(node == nullptr){
            return;
        }
        arr.push_back(node->val);
        readTree(node->left,arr);
        readTree(node->right,arr);
    }
};
/**
 * @brief Runtime: 260 ms, faster than 20.32% of C++ online submissions for All Elements in Two Binary Search Trees.
 * Memory Usage: 84.5 MB, less than 79.25% of C++ online submissions for All Elements in Two Binary Search Trees.
 * 
 */
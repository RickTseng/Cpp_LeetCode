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
// Constraints:

// The number of nodes in the tree is in the range [0, 1000].
// -10^9 <= Node.val <= 10^9
// -1000 <= targetSum <= 1000
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

// Ref harshit0311
// Runtime: 41 ms, faster than 44.09% of C++ online submissions for Path Sum III.
// Memory Usage: 15.8 MB, less than 98.52% of C++ online submissions for Path Sum III.

class Solution {
public:
    int ans=0;
    int pathSum(TreeNode* root, long long sum) {
        if(root){
            dfs(root,sum);
            pathSum(root->left,sum);
            pathSum(root->right,sum);
        }
        return ans;
    }
    void dfs(TreeNode* root, long long sum){
        if(!root)return;
        if(root->val==sum)ans++;
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
    }
};
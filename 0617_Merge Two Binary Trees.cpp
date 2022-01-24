#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        readNode(root1,root2);
        return root2;
    }
    void readNode(TreeNode* node1,TreeNode* &node2){
        if(node2==nullptr || node1 == nullptr){
            if(node1!=nullptr){
                node2 = node1;
            }
            return;
        }
        node2->val+=node1->val;
        readNode(node1->left,node2->left);
        readNode(node1->right,node2->right);
    }
};
/**
 * @brief 
 * Runtime: 49 ms, faster than 41.73% of C++ online submissions for Merge Two Binary Trees.
 * Memory Usage: 32.4 MB, less than 62.12% of C++ online submissions for Merge Two Binary Trees.
 * 
 */
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
class Solution {
public:
    TreeNode* matchNode = NULL;
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root!=NULL){
            if(root->val == val){
                matchNode = root;
                return root;
            }
            if(root->left!=NULL){
                searchBST(root->left,val);
            }
            if(root->right!=NULL){
                searchBST(root->right,val);
            }
        }
        return matchNode;
        
    }
};
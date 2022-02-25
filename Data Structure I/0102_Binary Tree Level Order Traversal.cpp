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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<TreeNode*> tmpNode;
        if(root!=NULL){
            res.push_back({root->val});
            tmpNode.push_back(root);
            while (!tmpNode.empty())
            {
                vector<int> levels;
                vector<TreeNode*> tmpNode1;
                for(auto nd:tmpNode){
                    readNode(nd,levels,tmpNode1);
                }
                tmpNode = tmpNode1;
                if(!levels.empty()){
                    res.push_back(levels);
                }
                
            }
        }
        return res;
    }
    void readNode(TreeNode *node,vector<int> &levels,vector<TreeNode*> &tmpNode1){
        if(node->left!=NULL){
            tmpNode1.push_back(node->left);
            levels.push_back(node->left->val);
        }
        if(node->right!=NULL){
            tmpNode1.push_back(node->right);
            levels.push_back(node->right->val);
        }
    }
};
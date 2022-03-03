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
    bool findTarget(TreeNode* root, int k) {
        vector<int> tmp;
        readNode(root,tmp);
        sort(tmp.begin(),tmp.end());
        for(int i = 0;i<tmp.size();i++){
            for(int j = i+1;j<tmp.size();j++){
                if(tmp[i]+tmp[j]==k){
                    return true;
                }
            }
        }
        
        return false;
    }
    void readNode(TreeNode* node,vector<int> &tmp){
        tmp.push_back(node->val);
        if(node->left!=NULL){
            readNode(node->left,tmp);
        }
        if(node->right!=NULL){
            readNode(node->right,tmp);
        }

    }
};
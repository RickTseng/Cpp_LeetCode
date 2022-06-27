#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;
// Definition for a binary tree node.
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
    string res;
    string tree2str(TreeNode* root) {
        res = "";
        readNode
    }
    string readNode(TreeNode* node){
        if(node==nullptr) return "";
        string l_Str = readNode(node->left);
        string r_Str = readNode(node->right);
        string tmp = "("+((char)(node->val + '0'))+')';
        return res;
    }
};
int main(){
    TreeNode *root = new TreeNode(1,new TreeNode(2,new TreeNode(4),nullptr),new TreeNode(3));
    Solution sol;
    string ans = sol.tree2str(root);
}
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
    TreeNode *invertTree(TreeNode *root)
    {
        if(root!=NULL)
        {   
        if(root->left!=NULL || root->right!=NULL){
            swap(root->left,root->right);
        }
        invertTree(root->left);
        invertTree(root->right);}
         return root;
    }
    
};
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    Solution sol;
    TreeNode *ans = sol.invertTree(root);
}
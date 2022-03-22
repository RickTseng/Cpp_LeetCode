#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <set>
#include <unordered_map>
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
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        bool get = false;
        readNode(root,subRoot,get);
        return get;
    }
    void readNode(TreeNode *node,TreeNode *subRoot,bool &get){
        if(node==nullptr){
            return;
        }
        if(node->val == subRoot->val){
            bool cmp = true;
            check(node,subRoot,cmp);
            if(cmp){
                get = true;
                return;
            }
        }
        if(!get){
            readNode(node->left,subRoot,get);
        }
        if(!get){
            readNode(node->right,subRoot,get);
        }
    }
    void check(TreeNode *node,TreeNode *subRoot,bool &cmp){
        if(node==nullptr && subRoot != nullptr){
            cmp = false;
            return;
        }
        if(node!=nullptr && subRoot == nullptr){
            cmp = false;
            return;
        }
        if(node==nullptr && subRoot == nullptr){
            return;
        }
        if(node->val != subRoot->val){
            cmp = false;
            return;
        }
        if(cmp){
            check(node->left,subRoot->left,cmp);
        }
        if(cmp){
            check(node->right,subRoot->right,cmp);
        }
    }
};
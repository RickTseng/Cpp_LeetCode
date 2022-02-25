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
    int maxDepth(TreeNode* root) {
        int _max = 0;
        if(root!=NULL){
            _max = 1;
            readDepth(root,_max,1);
        }
        return _max;
    }
    void readDepth(TreeNode* node,int &_max,int count){
        if(node->left!=NULL){
            readDepth(node->left,_max,count+1);
        }
        if(node->right!=NULL){
            readDepth(node->right,_max,count+1);
        }
        _max = max(_max,count);
        return;
    }
};
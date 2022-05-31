#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
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
class Solution {
public:
    int res;
    int averageOfSubtree(TreeNode* root) 
    {
        res = 0;
        travel(root);
        return res;
    }
    void readSub(TreeNode* node,int &sum,int &count)
    {
        if(node==nullptr){
            return;
        }
        readSub(node->left,sum+= node->val,count += 1);
        sum-=node->val;
        count-=1;
        readSub(node->right,sum+= node->val,count += 1);
        
    }
    void travel(TreeNode *node){
        if(node==nullptr){
            return;
        }
        int sum = 0, count = 0;
        readSub(node,sum,count);
        if(sum / count == node->val){
            res++;
        }
        travel(node->left);
        travel(node->right);
    }
};
/*4,8,5,0,1,null,6]*/
int main(){
    TreeNode *root = new TreeNode(4,new TreeNode(8,new TreeNode(0),new TreeNode(1)),new TreeNode(5,NULL,new TreeNode(6)));
    Solution sol;
    int ans = sol.averageOfSubtree(root);
}
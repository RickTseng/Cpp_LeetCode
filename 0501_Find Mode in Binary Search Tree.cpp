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
// Runtime: 59 ms, faster than 5.74% of C++ online submissions for Find Mode in Binary Search Tree.
// Memory Usage: 44.8 MB, less than 5.83% of C++ online submissions for Find Mode in Binary Search Tree.
class Solution
{
public:
    vector<int> rcPos,rcNeg,res;
    vector<int> findMode(TreeNode *root)
    {
        rcPos.resize(1e5+1,0);
        rcNeg.resize(1e5+1,0);
        int _max = 0;
        readNode(root,_max);
        for(int i = 0;i<1e5+1;++i)
        {
            if(rcPos[i]==_max){
                res.push_back(i);
            }
            if(rcNeg[i]==_max){
                res.push_back(-i);
            }
        }
        return res;
    }
    void readNode(TreeNode* node,int &_max)
    {
        if(node == nullptr) return;
        if(node->val>=0){
            rcPos[node->val]++;
            _max = max(_max,rcPos[node->val]);
        }
        else{
            rcNeg[-node->val]++;
            _max = max(_max,rcNeg[-node->val]);
        }
        readNode(node->left,_max);
        readNode(node->right,_max);
    }
};
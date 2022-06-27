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

class Solution
{
public:
//220616ACCEPT
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return builder(nums,0,nums.size()-1);
    }
    TreeNode* builder(vector<int>& nums, int low,int high){
        if(low<=high){
            int mid = low + (high-low)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = builder(nums, low, mid-1);
            root->right = builder(nums, mid+1, high);
            return root;
        }
        return NULL;
    }

};
int main(){
    vector<int> nums = {1,2,3,4,5};
    Solution sol;
    TreeNode *ans = sol.sortedArrayToBST(nums);
}
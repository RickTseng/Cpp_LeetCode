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
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
        {
            return 0;
        }
        vector<int> mem(200, 0);
        queue<char> len;
        len.push(s[0]);
        mem[s[0]]++;
        int beg = 0, end = 1, _max = len.size(), cSize = len.size();
        while (end < s.size())
        {
            mem[s[end]]++;
            len.push(s[end]);
            while (mem[s[end]] > 1)
            {
                len.pop();
                mem[s[beg]]--;
                beg++;
            }
            cSize = len.size();
            _max = max(_max, cSize);
            end++;
        }
        return _max;
    }
    bool isSymmetric(TreeNode* root) {
        if(root->right==nullptr && root->left!=nullptr){
            return false;
        }
        if(root->right!=nullptr && root->left==nullptr){
            return false;
        }
        if(root->right==nullptr && root->left==nullptr){
            return true;
        }
        if(root->right->val!=root->left->val){
            return false;
        }
        bool jd = true;
        int rval = 0,lval = 0;
        cmp(root->right,rval,root->left,lval , jd);
        return jd;
    }
    void cmp(TreeNode* rn,int &rval,TreeNode* ln,int &lval,bool &jd){
        if(rn==nullptr && ln!=nullptr){
            jd = false;
            return;
        }
        if(rn!=nullptr && ln==nullptr){
            jd = false;
            return;
        }
        if(rn==nullptr && ln==nullptr){
            return;
        }
        if(rn->val!=ln->val){
            jd = false;
            return;
        }
        if(jd){
            cmp(rn->right,rn->val,ln->left,ln->val,jd);
            if(rval!=lval){
                jd = false;
                return;
            }
            cmp(rn->left,rn->val,ln->right,ln->val,jd);
            if(rval!=lval){
                jd = false;
                return;
            }
        }
        
    }
};
int main()
{
    Solution sol;
    int ans = sol.lengthOfLongestSubstring("abcabcdb");
}
/**
 * @brief Runtime: 8 ms, faster than 87.08% of C++ online submissions for Longest Substring Without Repeating Characters.
 * Memory Usage: 9 MB, less than 35.62% of C++ online submissions for Longest Substring Without Repeating Characters.
 * 
 */
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
    TreeNode *res;
    vector<TreeNode*> pPath,qPath;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int pVal = p->val, qVal = q->val;
        
        bool getP = false,getQ = false;
        searchNode(root,pVal,pPath,getP);
        searchNode(root,qVal,qPath,getQ);
        for(int i = 0;i<min(pPath.size(),qPath.size());i++){
            if(pPath[i]==qPath[i])
            {
                res = pPath[i];
            }
        }
        return res;
    }
        
    void searchNode(TreeNode *node, int val,vector<TreeNode*> &path,bool &get){
        path.push_back(node);
        if(node->val==val){
            get = true;
            return;
        }    
        if(!get && node->left!=NULL){
            searchNode(node->left,val,path,get);
            if(!get){
                path.pop_back();
            }
            
        }
        if(!get && node->right!=NULL){
            searchNode(node->right,val,path,get);
            if(!get){
                path.pop_back();
            }
        }
        
    }
};
int main(){
    Solution sol;
    TreeNode *root = new TreeNode(6,new TreeNode(2,new TreeNode(0),new TreeNode(4)),new TreeNode(8));
    TreeNode *p = new TreeNode(2),*q = new TreeNode(4);
    TreeNode *ans = sol.lowestCommonAncestor(root,p,q);
}
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    struct Node{
      Node *node[2];
    };
    
    Node *newNode(){
        Node *n=new Node();
        n->node[0]=NULL;
        n->node[1]=NULL;
        
        return n;
    }
    
    void BuildTrie(Node *root,int num){
        
        for(int i=4;i>=0;i--)
            if(root->node[(num>>i)&1]==NULL){
                root->node[(num>>i)&1]=newNode();
                root=root->node[(num>>i)&1];
            }
            else
                root=root->node[(num>>i)&1]; 
    }
    
    int QueryTrie(Node *root,int num){
        int ans=0;
        for(int i=4;i>=0;i--)
            if(root->node[!((num>>i)&1)]!=NULL){
                root=root->node[!((num>>i)&1)];
                ans+=(1<<i);
            }
            else
                root=root->node[(num>>i)&1];
        
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        Node *root=newNode();
        for(auto num:nums)
            BuildTrie(root,num);
        
        int ans=INT_MIN;
        for(auto num:nums)
            ans=max(ans,QueryTrie(root,num));
        return ans;
    }
};
int main(){
    vector<int> nums = {3,10,5,25,2,8};
    Solution sol;
    int ans = sol.findMaximumXOR(nums);
}
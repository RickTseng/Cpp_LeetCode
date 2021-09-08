#include<stdio.h>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution{
    public:
    ListNode* reverseList(ListNode* head) {
        ListNode* l1 = new ListNode;
        if(head==nullptr){
            return nullptr;
        }
        Solution sol;
        vector<int> nums;
        sol.readNode(head,nums);
        ListNode* temp1 = new ListNode(nums[0]);
        l1 = temp1;
        for(int i = 1;i<nums.size();i++){
            ListNode* n = new ListNode;
            n->val = nums[i];
            n->next = nullptr;
            temp1->next = n;
            temp1 = temp1->next;
        }
        return l1;
        
    }
    void readNode(ListNode* head,vector<int>& nums){
        if(head==nullptr){
            return;
        }
        else{
            readNode(head->next,nums);
            nums.push_back(head->val);
            
        }
    }
    
    
    
};
int main(){
    Solution sol;
    vector<int> nums;
    for(int i = 0;i<5000;i++){
        nums.push_back(i);
    }
    ListNode* temp1 = new ListNode(nums[0]);
    ListNode* l1 = temp1;
    for(int i = 1;i<nums.size();i++){
        ListNode* n = new ListNode;
        n->val = nums[i];
        n->next = nullptr;
        temp1->next = n;
        temp1 = temp1->next;
    }
    ListNode* ans = sol.reverseList(l1);
    
}
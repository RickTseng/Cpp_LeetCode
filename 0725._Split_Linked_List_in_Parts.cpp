#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
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
        vector<ListNode*> splitListToParts(ListNode* head, int k) {
            vector<ListNode*> res;
            map<int,int> order;
            vector<int> nums;
            readNode(head,nums);
            //reverse nums since search to deep when reading
            reverse(nums.begin(),nums.end());
            int indexK = 1;
            //caculate linklist lenght ex: if k = 3 nums,size()=10 -> 4,3,3
            for(int i = 0;i<nums.size();i++){
                if(indexK>k){
                    indexK = 1;
                }
                if(order.find(indexK)==order.end()){
                    order[indexK]=1;
                }
                else{
                    order[indexK]++;
                }
                indexK++;
            }
            int l_index = 0;
            //build linklist
            for(auto linkx:order){
                ListNode* l1 = new ListNode;
                ListNode* temp1 = new ListNode(nums[l_index]);
                l_index++;
                l1 = temp1;
                for(int i = 0;i<linkx.second-1;i++){
                    ListNode* n = new ListNode;
                    n->val = nums[l_index];
                    n->next = nullptr;
                    temp1->next = n;
                    temp1 = temp1->next;
                    l_index++;
                }
                res.push_back(l1);
            }
            //k more than linklist
            if(nums.size()<k){
                for(int i = 0;i<k-nums.size();i++){
                    
                    res.push_back(nullptr);
                }
                
            }
            return res;
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
    for(int i = 0;i<10;i++){
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
    vector<ListNode*> res = sol.splitListToParts(l1,11);
}

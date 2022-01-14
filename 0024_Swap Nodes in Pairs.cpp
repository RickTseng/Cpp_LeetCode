#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       
        upN(head,head->val,head->val);
        return head;
    }
    void upN(ListNode* node,int valUp,int valDn){
        if(node==nullptr){
            return;
        }
        dnN(node->next,node->val,valDn);
        if(node->next!=nullptr){
            node->val = valDn;
        }
        
    }
    void dnN(ListNode* node,int valUp,int &valDn){
        if(node==nullptr){
            return;
        }
        upN(node->next,valUp,node->val);
        valDn = node->val;
        node->val = valUp;
        
    }
};
int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution sol;
    ListNode *ans = sol.swapPairs(head);
}
/**
 *   Runtime: 3 ms, faster than 65.51% of C++ online submissions for Swap Nodes in Pairs.
 *   Memory Usage: 7.7 MB, less than 6.85% of C++ online submissions for Swap Nodes in Pairs.
 * 
 */
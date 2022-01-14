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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> tmp;
        int b=1,e = 0;
        read(head,k,b,e,tmp);
        return head;

    }
    void read(ListNode* &node,int k,int b,int &e,vector<int> &tmp){
        if(node==nullptr){
            e=1;
            return;
        }
        tmp.push_back(node->val);
        read(node->next,k,b+1,e,tmp);
        if(e==k){
            
            node->val = tmp[k-1];
        }
        if(b==k){
            node->val = tmp[tmp.size()-k];
        }
        e++;
    }

};
int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution sol;
    ListNode *ans = sol.swapNodes(head,4);
}
/*
The number of nodes in the list is n.
1 <= k <= n <= 10^5
0 <= Node.val <= 100
Runtime: 1054 ms, faster than 16.08% of C++ online submissions for Swapping Nodes in a Linked List.
Memory Usage: 197.9 MB, less than 6.11% of C++ online submissions for Swapping Nodes in a Linked List.

*/
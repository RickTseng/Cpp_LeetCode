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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Runtime: 36 ms, faster than 90.86% of C++ online submissions for Add Two Numbers II.
// Memory Usage: 72.3 MB, less than 33.85% of C++ online submissions for Add Two Numbers II.

class Solution {
public:
    vector<int> v1,v2;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len = 0,sum0 = 0;
        readNode(l1,v1);
        readNode(l2,v2);
        len = max(v1.size(),v2.size());
        while (v1.size()<len)
        {
            v1.push_back(0);
        }
        while (v2.size()<len)
        {
            v2.push_back(0);
        }
        
        ListNode* res = new ListNode(0);
        int idx = 0;
        while(idx<v1.size() || idx<v2.size())
        {
            res->val = (v1[idx]+v2[idx]+ sum0)%10 ;
            sum0 = (v1[idx]+v2[idx]+ sum0)/10;
            idx++;
            if((idx<v1.size()) || (idx<v2.size()) || sum0>0 )
            {
                ListNode* node = new ListNode(0,res);
                res = node;
            }
        }
        if(sum0>0){
            res->val = sum0;
        }
        return res;
    }
    void readNode(ListNode* node,vector<int> &v){
        if(node==nullptr) return;
        readNode(node->next,v);
        v.push_back(node->val);
        
    }
};
int main(){
    // Input: l1 = [7,2,4,3], l2 = [5,6,4]
    ListNode* l1 = new ListNode(7,new ListNode(2,new ListNode(4,new ListNode(3))));
    ListNode* l2 = new ListNode(2,new ListNode(8,new ListNode(4,new ListNode(3))));
    Solution sol;
    ListNode* ans = sol.addTwoNumbers(l1,l2);
}
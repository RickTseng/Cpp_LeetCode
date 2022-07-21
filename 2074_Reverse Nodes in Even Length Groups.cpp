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

// Runtime: 2119 ms, faster than 6.82% of C++ online submissions for Reverse Nodes in Even Length Groups.
// Memory Usage: 364.7 MB, less than 10.35% of C++ online submissions for Reverse Nodes in Even Length Groups.

class Solution {
public:
    vector<vector<int>> v;
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int> row;
        readNode(head,row,1);
        return head;
        
    }
    void readNode(ListNode* node,vector<int> &row,int len){
        if(node==nullptr)return;
        if(len%2==1)
        {
            row.push_back(node->val);
        }
        else
        {
            row.insert(begin(row),node->val);
        }
        if(row.size()==len){
            v.push_back(row);
            row.clear();
            len+=1;
        }
        readNode(node->next,row,len);
        if(!row.empty()){
            if(len%2==0 && row.size()%2==1)
            {
                reverse(begin(row),end(row));
            }
            if(len%2==1 && row.size()%2==0)
            {
                reverse(begin(row),end(row));
            }
            v.push_back(row);
            row.clear();
        }
        if(v.back().empty()){
            int s = v.size();
            v.resize(s-1);
            
        }
        if(!v.back().empty()){
            node->val = v.back().back();
            v.back().pop_back();
        }
        
    }
};
int main(){
    ListNode* l1 = new ListNode(5,new ListNode(2,new ListNode(6,new ListNode(3,new ListNode(9,new ListNode(1,new ListNode(7,new ListNode(3,new ListNode(8)))))))));
    Solution sol;
    ListNode* ans = sol.reverseEvenLengthGroups(l1);
}
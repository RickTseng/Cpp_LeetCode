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

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Runtime: 25 ms, faster than 43.27% of C++ online submissions for Reverse Nodes in k-Group.
// Memory Usage: 13.2 MB, less than 5.51% of C++ online submissions for Reverse Nodes in k-Group.

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        vector<ListNode*> tmp;
        vector<int> vals;
        readNode(head,tmp,vals,k);
        return head;
    }
    void readNode(ListNode *node,vector<ListNode*> &tmp,vector<int> &vals,int k)
    {
        if(node==nullptr){
            return;
        }
        tmp.push_back(node);
        vals.push_back(node->val);
        if(tmp.size() == k)
        {
            for(int i = 0;i<k;++i)
            {
                tmp[i]->val = vals[k-i-1];
            }
            tmp.clear();
            vals.clear();
            
        }
        readNode(node->next,tmp,vals,k);
        
    }
};
int main(){
    ListNode *head = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    Solution sol;
    ListNode *ans = sol.reverseKGroup(head,2);
}
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

// Runtime: 10 ms, faster than 7.75% of C++ online submissions for Reverse Linked List II.
// Memory Usage: 7.5 MB, less than 63.64% of C++ online submissions for Reverse Linked List II.

class Solution {
public:
    vector<int> midList;
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(left==right) return head;
        getMid(head,1,left,right);
        fillVal(head,1,left,right);
        return head;
    }
    void getMid(ListNode* &node,int lv,int left,int right){
        if(node == nullptr) return;
        if(lv>=left){
            midList.push_back(node->val);
        }
        if(lv == right)
        {
            return;
        }
        getMid(node->next,lv+1,left,right);
    }
    void fillVal(ListNode* &node,int lv,int left,int right)
    {
        if(node == nullptr) return;
        if(lv>=left){
            node->val = midList.back();
            midList.pop_back();
        }
        if(lv == right)
        {
            return;
        }
        fillVal(node->next,lv+1,left,right);
    }

};
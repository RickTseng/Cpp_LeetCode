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

// Runtime: 213 ms, faster than 81.09% of C++ online submissions for Sort List.
// Memory Usage: 53.2 MB, less than 70.44% of C++ online submissions for Sort List.

class Solution {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    ListNode* sortList(ListNode* head) 
    {
        readList(head);
        fillVal(head);
        return head;
    }
    void readList(ListNode* node){
        if(node==nullptr)return;
        pq.push(node->val);
        readList(node->next);
    }
    void fillVal(ListNode* &node)
    {
        if(node==nullptr)return;
        node->val = pq.top();
        pq.pop();
        fillVal(node->next);
    }
};
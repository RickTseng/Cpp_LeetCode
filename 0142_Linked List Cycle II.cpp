#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
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

// Runtime: 21 ms, faster than 17.06% of C++ online submissions for Linked List Cycle II.
// Memory Usage: 11.9 MB, less than 6.91% of C++ online submissions for Linked List Cycle II.

class Solution {
public:
    unordered_set<ListNode*>us;
    ListNode *res;
    ListNode *detectCycle(ListNode *head) {
        read(head);
        return res;
    }
    void read(ListNode* node){
        if(node==nullptr){
            res = nullptr;
            return;
        }
        int tmpSize = us.size();
        us.insert(node);
        if(tmpSize==us.size()){
            res = node;
            return;
        }
        read(node->next);
    }
};
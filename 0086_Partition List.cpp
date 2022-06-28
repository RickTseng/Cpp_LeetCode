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

// Runtime: 20 ms, faster than 5.13% of C++ online submissions for Partition List.
// Memory Usage: 10.8 MB, less than 11.62% of C++ online submissions for Partition List.

class Solution {
public:
    vector<int> aN;
    vector<int> bN;
    ListNode* partition(ListNode* head, int x) {
        readNode(head,x);
        ListNode* res = nullptr;
        buildList(res);
        return res;

    }
    void readNode(ListNode* node,int x){
        if(node==nullptr){
            return;
        }
        node->val < x? aN.push_back(node->val):bN.push_back(node->val);
        readNode(node->next,x);
    }
    void buildList(ListNode* &node)
    {
        if(!aN.empty()){
            ListNode *tmp = new ListNode(aN.front());
            aN.erase(begin(aN));
            node == nullptr? node = tmp : node->next = tmp;
            buildList(node->next);
        }
        if(!bN.empty()){
            ListNode *tmp = new ListNode(bN.front());
            bN.erase(begin(bN));
            node == nullptr? node = tmp : node->next = tmp;
            buildList(node->next);
        }
    }
};
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

// Runtime: 3 ms, faster than 98.28% of C++ online submissions for Rotate List.
// Memory Usage: 11.7 MB, less than 54.64% of C++ online submissions for Rotate List.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr){
            return 0;
        }
        int count = 0;
        read2deep(head,count);
        k > count ? k%= count:k;
        ListNode* rNode;
        cutList(head,0,count-k,rNode);
        connect(head,rNode);
        return rNode;
    }
    void read2deep(ListNode* node,int &count){
        if(node==nullptr) return;
        read2deep(node->next,++count);
    }
    void cutList(ListNode* &node,int lv,int target,ListNode* &rNode){
        if(lv == target){
            rNode = node;
            node = nullptr;
            return;
        }
        cutList(node->next,lv+1,target,rNode);
    }
    void connect(ListNode* &node,ListNode* rNode){
        
        if(rNode!=nullptr && rNode->next == nullptr){
            rNode->next = node;
            return;
        }
        if(rNode==nullptr){
            rNode = node;
            return;
        }
        connect(node,rNode->next);
        
    }

};
int main(){
    ListNode *head = new ListNode(1,new ListNode(2,new ListNode(3)));
    Solution sol;
    ListNode *ans = sol.rotateRight(head,99);
}
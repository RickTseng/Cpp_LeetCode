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

// Runtime: 30 ms, faster than 8.89% of C++ online submissions for Odd Even Linked List.
// Memory Usage: 10.6 MB, less than 29.08% of C++ online submissions for Odd Even Linked List.

class Solution {
public:
    ListNode* tail;
    ListNode* oddEvenList(ListNode* head) 
    {
        ListNode* evenLN = new ListNode(0);
        tail = evenLN;
        int lv = 1;
        exec(head,lv,evenLN);
        return head;
    }
    void exec(ListNode* head,int &lv,ListNode* evenLN)
    {
        if(head==nullptr) return;
        
            
        if(lv == 1)
        {
            evenLN->next = head->next;
            if(head->next==nullptr)
            {
                head->next = tail->next;
                return;
            }
            head->next = head->next->next;
            if(head->next==nullptr)
            {
                head->next = tail->next;
                return;
            }
            lv = 0;
            exec(head->next,lv,evenLN->next);
        }
        else{
            lv = 1;
            exec(head,lv,evenLN);
        }
    }
};
int main(){
    ListNode *head = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5,new ListNode(6))))));
    Solution sol;
    ListNode *ans = sol.oddEvenList(head);
}
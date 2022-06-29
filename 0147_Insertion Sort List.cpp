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

// Ref jianchao-li
// Runtime: 23 ms, faster than 82.38% of C++ online submissions for Insertion Sort List.
// Memory Usage: 9.6 MB, less than 35.82% of C++ online submissions for Insertion Sort List.

class Solution
{
public:
    ListNode *insertionSortList_ref(ListNode *&head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        while (cur != nullptr)
        {
            if ((cur->next != nullptr) && (cur->next->val < cur->val))
            {
                while ((pre->next!=nullptr) && (pre->next->val < cur->next->val))
                {
                    pre = pre->next;
                }
                ListNode *temp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = temp;
                pre = dummy;
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
    ListNode *insertionSortList(ListNode *&head)
    {
        
    }
};
int main()
{
    ListNode *head = new ListNode(2, new ListNode(1, new ListNode(4, new ListNode(5, new ListNode(3)))));
    Solution sol;
    ListNode *ans = sol.insertionSortList(head);
}
// ListNode* insertionSortList(ListNode* head) {
//         ListNode* dummy = new ListNode(0);
//         dummy -> next = head;
//         ListNode *pre = dummy, *cur = head;
//         while (cur) {
//             if ((cur -> next) && (cur -> next -> val < cur -> val)) {
//                 while ((pre -> next) && (pre -> next -> val < cur -> next -> val)) {
//                     pre = pre -> next;
//                 }
//                 ListNode* temp = pre -> next;
//                 pre -> next = cur -> next;
//                 cur -> next = cur -> next -> next;
//                 pre -> next -> next = temp;
//                 pre = dummy;
//             }
//             else {
//                 cur = cur -> next;
//             }
//         }
//         return dummy -> next;
//     }
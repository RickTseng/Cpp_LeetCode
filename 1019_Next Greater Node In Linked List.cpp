#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <stack>
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

// Ref Abhi_sharma solution
// Runtime: 155 ms, faster than 45.51% of C++ online submissions for Next Greater Node In Linked List.
// Memory Usage: 39.7 MB, less than 89.15% of C++ online submissions for Next Greater Node In Linked List.


class Solution
{
public:
    vector<int> res;
    stack<int> sk;
    vector<int> nextLargerNodes(ListNode *head)
    {
        read2End(head);
        return res;
    }
    void read2End(ListNode *node)
    {
        if (node->next == nullptr)
        {
            res.push_back(0);
            sk.push(node->val);
            return;
        }
        read2End(node->next);
        while (!sk.empty())
        {
            if (sk.top() > node->val)
            {
                res.insert(begin(res), sk.top());
                sk.push(node->val);
                return;
            }
            else
            {
                sk.pop();
            }
        }
        if (sk.empty())
        {
            res.insert(begin(res), 0);
            sk.push(node->val);

        }
    }
};
int main()
{
    ListNode *head = new ListNode(1, new ListNode(7, new ListNode(5, new ListNode(1, new ListNode(9, new ListNode(2, new ListNode(5, new ListNode(1, new ListNode(1, new ListNode(5, new ListNode(2, new ListNode(1, new ListNode(5, new ListNode(9))))))))))))));
    Solution sol;
    vector<int> ans = sol.nextLargerNodes(head);
}

// ListNode* reverseList(ListNode* head)
//     {
//         ListNode* prev = NULL;
//         while(head != NULL)
//         {
//             ListNode* nxt = head->next;
//             head->next = prev;
//             prev = head;
//             head = nxt;
//         }
//        return prev;
//     }
//     vector<int> nextLargerNodes(ListNode* head) {
//         vector<int> ans;
//         if(head == NULL)
//             return ans;
//         head = reverseList(head);
        
//         stack<int> s;
//         while(head != NULL)
//         {
//             if(s.empty())
//             {
//                 ans.push_back(0);
//                 s.push(head->val);
//                 head = head->next;
//             }
//             else if(s.top() > head->val)
//             {
//                 ans.push_back(s.top());
//                 s.push(head->val);
//                 head = head->next;
//             }
//             else
//                 s.pop();
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };
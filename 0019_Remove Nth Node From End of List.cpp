#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        vector<int> v;
        read(head, v);
        v.erase(v.end() - n);
        ListNode *nHead = nullptr;
        if (!v.empty())
        {
            nHead = new ListNode(v[0]);
            if(v.size()>1){
                buildList(nHead, v, 1);
            }
            return nHead;
        }
        else
        {
            return nHead;
        }
    }
    void read(ListNode *node, vector<int> &v)
    {
        if (node == nullptr)
        {
            return;
        }
        v.push_back(node->val);
        read(node->next, v);
    }
    void buildList(ListNode *node, vector<int> v, int idx)
    {
        if (idx > v.size() - 1)
        {
            return;
        }
        node->next = new ListNode(v[idx]);
        buildList(node->next, v, idx + 1);
    }
};
int main()
{
    ListNode *head = new ListNode(0);
    /*
    ListNode *tmp;
    tmp = head;
    for (int i = 1; i < 11; i++)
    {
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    */
    Solution sol;
    ListNode *ans = sol.removeNthFromEnd(head, 1);
    return 0;
}
/*

Runtime: 4 ms, faster than 79.57% of C++ online submissions for Remove Nth Node From End of List.
Memory Usage: 11.6 MB, less than 32.17% of C++ online submissions for Remove Nth Node From End of List.

*/
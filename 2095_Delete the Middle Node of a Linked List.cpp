#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
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
    ListNode *deleteMiddle(ListNode *head)
    {
        vector<int> val;
        ListNode *res, *tmp;
        tmp = new ListNode;
        
        readNode(head, val);
        if(val.size()==1){
            return res;
        }
        if(val.size()==2){
            return res = new ListNode(val[0]);
        }
        res = tmp;
        for (int i = 0; i < val.size(); i++)
        {

            if (i == val.size() / 2)
            {
                continue;
            }
            tmp->val = val[i];
            if (i == val.size() - 1)
            {
                break;
            }
            tmp->next = new ListNode();
            tmp = tmp->next;
        }
        return res;
    }
    void readNode(ListNode *node, vector<int> &val)
    {
        if (node == nullptr)
        {
            return;
        }
        val.push_back(node->val);
        readNode(node->next, val);
    }
};
int main()
{
    ListNode *head = new ListNode;
    head->val = 0;
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    Solution sol;
    ListNode *ans = sol.deleteMiddle(head);
}
/*

Runtime: 1648 ms, faster than 8.88% of C++ online submissions for Delete the Middle Node of a Linked List.
Memory Usage: 359.1 MB, less than 24.91% of C++ online submissions for Delete the Middle Node of a Linked List.

*/
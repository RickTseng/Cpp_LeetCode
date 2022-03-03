#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        int pastVal = head->val;
        ListNode *res = new ListNode(head->val);
        exec(head->next, pastVal, res);
        return res;
    }
    void exec(ListNode *node, int &pastVal, ListNode *&res)
    {
        if (node == NULL)
        {
            return;
        }
        if (node->val == pastVal)
        {
            exec(node->next, pastVal, res);
        }
        else
        {
            res->next = new ListNode(node->val);
            pastVal = node->val;
            exec(node->next, pastVal, res->next);
        }
    }
};
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);
    Solution sol;
    ListNode*  ans = sol.deleteDuplicates(head);
}
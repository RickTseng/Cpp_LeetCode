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
    ListNode *tmp = NULL;
    ListNode *removeElements(ListNode *&head, int val)
    {
        if (head != NULL)
        {
            // ListNode* newHaed = NULL;
            if (head->val == val)
            {
                if (head->next != NULL)
                {
                    tmp = head->next;
                    head = NULL;
                    head = tmp;
                    removeElements(head, val);
                }
                else
                {
                    head = NULL;
                    return head;
                }
            }
            else
            {
                if (head->next != NULL)
                {
                    removeElements(head->next, val);
                }
            }
        }
        return head;
    }
};
int main()
{
    ListNode *head = new ListNode(6), *tmp = NULL;
    tmp = head;
    for (int i = 0; i < 10; i++)
    {
        tmp->next = new ListNode(6);
        tmp = tmp->next;
    }
    Solution sol;
    ListNode *ans = sol.removeElements(head, 6);
}
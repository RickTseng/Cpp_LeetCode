#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <unordered_map>
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
    map<int, int> tmpVal;
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        ListNode *res, *tmp;
        //res = tmp;
        readNode(head);
        for(auto t:tmpVal){
            if(t.second==1){
                add(res,t.first);
            }
        }
        return res;
    }
    void readNode(ListNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        tmpVal[node->val]++;
        readNode(node->next);
    }
    void add(ListNode *&node, int val)
    {
        if(node == nullptr)
        {
            node = new ListNode(val);
            return;
        }
        add(node->next,val);
    }
};
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(4);
    Solution sol;
    ListNode *ans = sol.deleteDuplicates(head);
}
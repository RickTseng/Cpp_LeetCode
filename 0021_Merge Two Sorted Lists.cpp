#include <algorithm>
#include <vector>
#include <string>
#include <map>
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if(list1==nullptr&&list2==nullptr)
        {
            return nullptr;
        }
        vector<int> pq;
        readList(list1, pq);
        readList(list2, pq);
        sort(pq.begin(),pq.end());
        ListNode *res, *tmp;        
        res = new ListNode(pq[0]);
        tmp = res;
        int i = 1;
        while (i<pq.size())
        {
            tmp->next = new ListNode(pq[i]);
            i++;
            tmp = tmp->next;
        }
        return res;
    }
    void readList(ListNode *node, vector<int> &pq)
    {
        if (node == nullptr)
        {
            return;
        }
        pq.push_back(node->val);
        readList(node->next, pq);
    }
};
int main(){
    ListNode *l1 = new ListNode(0);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(2);
    l1->next->next->next = new ListNode(3);
    Solution sol;
    ListNode* ans = sol.mergeTwoLists(l1,l1);
}
/**
 * @brief Runtime: 7 ms, faster than 76.20% of C++ online submissions for Merge Two Sorted Lists.
 * Memory Usage: 15.2 MB, less than 8.56% of C++ online submissions for Merge Two Sorted Lists.
 * 
 */
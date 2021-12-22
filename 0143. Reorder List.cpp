#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <list>
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
    void reorderList(ListNode *head)
    {
        ListNode *tmp = head;
        list<int> db;
        while (tmp!=nullptr)
        {
            db.push_back(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        while (!db.empty())
        {
            if(!db.empty())
            {
                tmp->val = db.front();
                db.pop_front();
                tmp = tmp->next;
            }
            if(!db.empty())
            {
                tmp->val = db.back();
                db.pop_back();
                tmp = tmp->next;
            }
        }
        
        
    }
};
int main(){
    ListNode *head = new ListNode();
    head->val = 1;
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution sol;
    sol.reorderList(head);
}

/*

Constraints:

The number of nodes in the list is in the range [1, 5 * 10^4].
1 <= Node.val <= 1000


*/
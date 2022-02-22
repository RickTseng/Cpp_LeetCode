#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        int count = 10000;
        while(head && count >= 0)
        {
            head = head->next;
            count--;
        }
        return count < 0;
        //return false;
    }
};
int main(){
    Solution sol;
    ListNode *head = new ListNode(3);
    ListNode *head1 = new ListNode(2);
    ListNode *head4 = new ListNode(-4);
    head->next = head1;
    head->next->next = new ListNode(0);
    head->next->next->next = head4;
    //head4->next = head1;
    bool ans = sol.hasCycle(head);
}
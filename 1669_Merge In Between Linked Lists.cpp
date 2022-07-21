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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Runtime: 448 ms, faster than 51.73% of C++ online submissions for Merge In Between Linked Lists.
// Memory Usage: 94.5 MB, less than 55.84% of C++ online submissions for Merge In Between Linked Lists.

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode *curr1 = list1;
        ListNode *curr2 = list2;
        ListNode *head, *tail;
        int idx = 0;
        while(curr1!=nullptr){
            if(idx+1 == a)
            {
                head = curr1;
            }
            if(idx==b){
                tail = curr1->next;
                break;
            }
            idx++;
            curr1 = curr1->next;
        }
        while (curr2->next!=nullptr)
        {
            curr2 = curr2->next;
        }
        curr2->next = tail;
        head->next = list2;
        return list1;

    }
    
};
int main(){
    ListNode* l1 = new ListNode(5,new ListNode(2,new ListNode(6,new ListNode(3,new ListNode(9,new ListNode(1,new ListNode(7,new ListNode(3,new ListNode(8)))))))));
    Solution sol;
    ListNode* ans = sol.mergeInBetween(l1,1,3,l1);
}
// Constraints:

// 3 <= list1.length <= 10^4
// 1 <= a <= b < list1.length - 1
// 1 <= list2.length <= 10^4
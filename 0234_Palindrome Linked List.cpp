#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    vector<int> tmp;
    bool isPalindrome(ListNode* head) {
        readNode(head);
        int left = 0,right = tmp.size()-1;
        while (left<=right)
        {
            if(tmp[left]!=tmp[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void readNode(ListNode *node)
    {
        if(node== nullptr){
            return;
        }
        tmp.push_back(node->val);
        readNode(node->next);
    }
};
#include <algorithm>
#include <vector>
#include <string>
#include <map>
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
    ListNode* middleNode(ListNode* head) 
    {
        vector<ListNode*> rc;
        readList(rc,head);
        int mid= rc.size()/2;
        return rc[mid];
    }
    void readList( vector<ListNode> &rc,ListNode* node){
        if(node==nullptr){
            return;
        }
        rc.push_back(node);
        readList(rc,node->next);
    }
};
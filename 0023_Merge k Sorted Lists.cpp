#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<queue>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> pq;
        for(auto l:lists){
            readList(l,pq);
        }
        if(pq.empty()){
            return nullptr;
        }
        sort(pq.begin(),pq.end(),greater<int>());
        ListNode* res = new ListNode(0),*tmp;
        tmp = res;
        while (!pq.empty())
        {
            tmp->val = pq[pq.size()-1];
            pq.pop_back();
            if(!pq.empty()){
                tmp->next = new ListNode(0);
                tmp = tmp->next;
            }
            
        }
        return res;
    }
    void readList(ListNode* node,vector<int> &pq){
        if(node==nullptr){
            return;
        }
        pq.push_back(node->val);
        readList(node->next,pq);
    }
};
int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    vector<ListNode*> lists;
    for(int i = 0;i<10;i++){
        lists.push_back(head);
    }
    Solution sol;
    ListNode *ans = sol.mergeKLists(lists);
}
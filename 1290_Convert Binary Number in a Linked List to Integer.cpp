#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
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
    int getDecimalValue(ListNode *head)
    {
        vector<int> v;
        read(head,v);
        int b = 1,sum = 0;
        for(int i = v.size()-1;i>=0;i--){
            sum+=(v[i] * b);
            b*=2;
        }
        return sum;
    }
    void read(ListNode *node,vector<int> &v){
        if(node == nullptr){
            return;
        }
        v.push_back(node->val);
        read(node->next,v);
    }
};
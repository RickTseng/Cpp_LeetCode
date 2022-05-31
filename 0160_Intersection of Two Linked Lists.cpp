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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        vector<ListNode *> tbA, tbB;
        readNode(headA, tbA);
        readNode(headB, tbB);
        int idxA = tbA.size() - 1;
        int idxB = tbB.size() - 1;
        while (idxA >= 0 && idxB >= 0)
        {
            if (tbA[idxA] != tbB[idxB])
            {
                break;
            }
            idxA--;
            idxB--;
        }
        if (idxA  == tbA.size() - 1 && idxB  == tbB.size() - 1)
        {
            return NULL;
        }
        if (idxA  == tbA.size() - 1)
        {
            return tbB[idxB + 1];
        }
        if (idxB  == tbB.size() - 1)
        {
            return tbA[idxA + 1];
        }
        return tbA[idxA + 1];
    }
    void readNode(ListNode *node, vector<ListNode *> &tb)
    {
        if (node == NULL)
        {
            return;
        }
        tb.push_back(node);
        readNode(node->next, tb);
    }
};
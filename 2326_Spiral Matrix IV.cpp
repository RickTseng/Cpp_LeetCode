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

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Runtime: 644 ms, faster than 33.33% of C++ online submissions for Spiral Matrix IV.
// Memory Usage: 241.4 MB, less than 33.33% of C++ online submissions for Spiral Matrix IV.

class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        res.resize(m,vector<int>(n,-1));
        readNode(head,m,n,0,0,"R");
        return res;

    }
    void readNode(ListNode *node,int m,int n,int r,int c,string side){
        if(node==nullptr) return;
        res[r][c] = node->val;
        if(side =="R")
        {
            
            if(c + 1 == n || res[r][c+1] !=-1 )
            {
                readNode(node->next,m,n,r+1,c,"D");
            }
            else
            {
                readNode(node->next,m,n,r,c+1,"R");
            }
        }
        if(side =="D")
        {
            if(r + 1 == m || res[r+1][c] !=-1 )
            {
                readNode(node->next,m,n,r,c-1,"L");
            }
            else
            {
                readNode(node->next,m,n,r+1,c,"D");
            }
        }
        if(side =="L")
        {
            if(c - 1 < 0 || res[r][c-1] !=-1 )
            {
                readNode(node->next,m,n,r-1,c,"U");
            }
            else
            {
                readNode(node->next,m,n,r,c-1,"L");
            }
        }
        if(side =="U")
        {
            if(r - 1 < 0 || res[r-1][c] !=-1 )
            {
                readNode(node->next,m,n,r,c+1,"R");
            }
            else
            {
                readNode(node->next,m,n,r-1,c,"U");
            }
        }
    }
};
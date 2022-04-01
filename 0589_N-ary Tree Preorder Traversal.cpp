#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        res.push_back(root->val);
        vector<Node*> tmp = root->children;
        readNode(tmp,res);
        return res;
    }
    void readNode(vector<Node*> nodeList,vector<int> &res){
        for(auto node:nodeList){
            res.push_back(node->val);
            vector<Node*> tmp = node->children;
            readNode(tmp,res);
        }
        
    }
};
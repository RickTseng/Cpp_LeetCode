#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return root;
        }
        vector<Node*> nodeList;
        nodeList.push_back(root);
        bfs(nodeList);
        return root;
    }
    void bfs(vector<Node*> &nodeList){
        if(nodeList.empty()){
            return;
        }
        vector<Node*> levelNode;
        for(int i = 0;i<nodeList.size();i++){
            if(nodeList[i]->left!=NULL){
                levelNode.push_back(nodeList[i]->left);
            }
            if(nodeList[i]->right!=NULL){
                levelNode.push_back(nodeList[i]->right);
            }
            if(i+1<nodeList.size()){
                nodeList[i]->next = nodeList[i+1];
            }
            else{
                nodeList[i]->next = NULL;
            }
        }
        bfs(levelNode);
    }
};
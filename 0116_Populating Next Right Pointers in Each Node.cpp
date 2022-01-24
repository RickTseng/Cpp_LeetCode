#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
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
        vector<Node*> vN,tmp;
        vN.push_back(root);
        tmp = vN;
        bool run = true;
        while (true)
        {
            vector<Node*> tmp1;
            for(int i = 0;i<tmp.size();i++){
                if(!dfs(tmp[i],tmp1)){
                    run = false;
                    break;
                }
            }
            if(!run){
                break;
            }
            for(int i = 0;i+1<tmp1.size();i++){
                tmp1[i]->next = tmp1[i+1];
            }
            tmp = tmp1;

        }
        
        
        return root; 
    }
    bool dfs(Node* node,vector<Node*> &tmp){
        if(node->left==NULL && node->right==NULL){
            return false;
        }
        tmp.push_back(node->left);
        tmp.push_back(node->right);
        return true;
    }
};
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution sol;
    Node* ans = sol.connect(root);
}
/**
 * @brief 
 * Runtime: 19 ms, faster than 74.00% of C++ online submissions for Populating Next Right Pointers in Each Node.
 * Memory Usage: 17.8 MB, less than 5.81% of C++ online submissions for Populating Next Right Pointers in Each Node.
 * 
 */
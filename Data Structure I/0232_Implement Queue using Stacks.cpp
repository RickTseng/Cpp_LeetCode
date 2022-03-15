#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;
class MyQueue {
public:
    vector<int> tmp;
    MyQueue() {
        
    }
    
    void push(int x) {
        tmp.push_back(x);
    }
    
    int pop() {
        //auto it = tmp.begin();
        int ans = *tmp.begin();
        tmp.erase(tmp.begin());
        return ans;
    }
    
    int peek() {
        return tmp.front();
    }
    
    bool empty() {
        return tmp.empty();
    }
};
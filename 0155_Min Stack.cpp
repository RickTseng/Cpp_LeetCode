#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
class MinStack {
public:
    stack<pair<int,int>> rec;

    MinStack() {
        
    }
    
    void push(int val) {
        if(rec.empty()||rec.top().second>=val){
            rec.push({val,val});
        }
        else{
            rec.push({val,rec.top().second});
        }
    }
    
    void pop() {
        rec.pop();
    }
    
    int top() {
        return rec.top().first;
    }
    
    int getMin() {
        return rec.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 * 
 * 
 * -2^31 <= val <= 2^31 - 1
 * Methods pop, top and getMin operations will always be called on non-empty stacks.
 * At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
 */
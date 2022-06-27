#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        qq.push(x);
        for(int i=0;i<qq.size()-1;i++){
			qq.push(qq.front());
			qq.pop();
		}
        
    }
    
    int pop() {
        int x = qq.front();
        qq.pop();
        return x;
    }
    
    int top() {
        return qq.front();
    }
    
    bool empty() {
        return qq.empty();
    }
private:
    queue<int> qq;
};
int main(){
    queue<int> tmp;
    MyStack _stk;
    for(int i = 0;i<10;i++){
        _stk.push(i);
    }
    
    
}
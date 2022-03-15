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
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> ss,st;
        for(auto c:s){
            if(c!='#'){
                ss.push(c);
            }
            else{
                if(!ss.empty()){
                    ss.pop();
                }
            }
        }
        for(auto c:t){
            if(c!='#'){
                st.push(c);
            }
            else{             
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        if(ss.size()!=st.size()){
            return false;
        }
        while (!ss.empty())
        {
            if(ss.top()!=st.top()){
                return false;
            }
            ss.pop();
            st.pop();
        }
        
        return true;
    }
};
int main(){
    Solution sol;
    bool ans = sol.backspaceCompare("ab#c","ac");
}
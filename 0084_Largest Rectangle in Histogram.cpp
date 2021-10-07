#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<stack>
using namespace std;
class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int res = 0, n = heights.size();
        for(int i = 0; i <n ;i++)
        {
            while( !s.empty() && heights[s.top()] >= heights[i])
            {
                int tp = s.top();
                s.pop();
                int curr = heights[tp]*((s.empty()) ? i : (i - s.top() -1));
                res = max(res, curr);
            }
            s.push(i);
        }
        
        while(!s.empty())
        {
            int tp = s.top();
            s.pop();
            int curr = heights[tp]*((s.empty()) ? n : (n - s.top() -1));
            res = max(res, curr);
        }
        
        return res;
    
        /********************************************************
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            if (st.empty() || heights[st.top()] < heights[i]) {
                st.push(i);
            } 
            else {
                int cur = st.top(); st.pop();
                res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
                --i;
            }     
        }
        return res;
        /********************************************************/
        /*int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (i + 1 < heights.size() && heights[i] <= heights[i + 1]) {
                continue;
            }
            int minH = heights[i];
            for (int j = i; j >= 0; --j) {
                minH = min(minH, heights[j]);
                int area = minH * (i - j + 1);
                res = max(res, area);
            }
        }
        return res;
        /********************************************************/
        /*int _max = 0;
        int currentH = -1;
        for(int i = 0;i<heights.size();i++){
            if(currentH>=heights[i] && i<heights.size())
            {
                i++;
            }
            currentH = max(currentH,heights[i]);
            int _min = 10001;
            for(int j = i;j<heights.size();j++){
                _min = min(heights[j],_min);
                _max = max(_max,_min*(j-i+1));
            }
        }
        return _max;
        /********************************************************/
    }
};
//1 <= heights.length <= 10^5
//0 <= heights[i] <= 10^4

int main(){
    //vector<int> heights(100000,10000);
    vector<int> heights = {2,1,5,6,2,3};
    Solution sol;
    int ans = sol.largestRectangleArea(heights);
}
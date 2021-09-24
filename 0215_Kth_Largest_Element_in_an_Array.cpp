#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<map>
#include<queue>
using namespace std;
class Solution{
    public:
    int findKthLargest(vector<int>& nums, int k) {
        //sort(nums.begin(),nums.end());
        

        //return nums[nums.size()-k];


        priority_queue<int, vector<int>, greater<int>> qu;
        for (int v : nums) {
            qu.push(v);
            if (qu.size() > k)
                qu.pop();
        }
               
        return qu.top();
    }
};
int main(){
    vector<int> nums = {3,2,3,1,0,4,5,5,6};
    Solution sol;
    int ans = sol.findKthLargest(nums, 4);
    printf("%d",ans);
}
//First use sort and find nums.size()-k 's element
//Study other solution find queue STL use priority_queue
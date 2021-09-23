#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
class Solution{
    public:
    void rotate(vector<int>& nums, int k) {
        //reverse(nums.end()-k,nums.end());
        vector<int> tmp;
        
        if(k>nums.size()){
            k%=nums.size();
        }
        tmp.insert(tmp.begin(),nums.end()-k,nums.end());
        nums.insert(nums.begin(),tmp.begin(),tmp.end());
        nums.resize(nums.size()-k);
        //nums.erase(nums.end()-k,nums.end());
        /*for(int i = 0;i<k;i++){
            nums.insert(nums.begin(),nums[nums.size()-1]);
            nums.pop_back();
        }
        */
    }
};
int main(){
    
    //for(int i = 0;i<10000;i++){
    //    nums.push_back(i+7);
    //}
    vector<int> nums = {1,2,3};
    Solution sol;
    sol.rotate(nums,1);
    printf("%d",nums.size());
    system("pause");
}
//Runtime: 24 ms, faster than 90.87% of C++ online submissions for Rotate Array.
//Memory Usage: 26.1 MB, less than 8.75% of C++ online submissions for Rotate Array.
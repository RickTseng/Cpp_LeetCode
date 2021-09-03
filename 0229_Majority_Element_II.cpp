#include<vector>
#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;
class Solution
{
    public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()==1){
            return nums;
        }
        sort(nums.begin(),nums.end());
        int standard = nums.size()/3+1;
        vector<int> res;
        map<int,int> _map;
        int exist = INT32_MIN;
        for(int i =0;i<nums.size();i++){
            if(_map.find(nums[i])==_map.end()){
                _map[nums[i]] = 1;
                if(_map[nums[i]]>=standard){
                    exist = nums[i];
                    res.push_back(nums[i]);
                }
            }
            else{
                if(nums[i] != exist){
                    _map[nums[i]] += 1;
                    if(_map[nums[i]]>=standard){
                        exist = nums[i];
                        res.push_back(nums[i]);
                    }
                }
            }
                
        }
        return res;
    }
    
};
int main(){

    vector<int> nums;
    for(int i = 0 ; i<50000;i++){
        nums.push_back(i*3);
    }
    Solution solution;
    vector<int> x = solution.majorityElement(nums);
    system("pause");
}
//Runtime: 37 ms, faster than 5.34% of C++ online submissions for Majority Element II.
//Memory Usage: 16 MB, less than 9.87% of C++ online submissions for Majority Element II.

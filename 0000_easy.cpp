#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    int missingNumber_org(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=i){
                return i;
            }
        }
        return nums.size();
    }

    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int desired = n * (n+1) / 2;
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        //ex:0~6 sum = 21
        //if nums sum equal 15 it's means missing '6'
        return desired - sum;
    }

    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            int target = nums[i];
            for(int j = i+1;j<nums.size();j++){
                if(nums[j]==target){
                    count++;
                }
            }
        }
        return count;
    }
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int index = 0;
        while (index<len)
        {
            if(nums[index]==0){
                nums.erase(nums.begin()+index);
                nums.push_back(0);
                len--;
            }
            else{
                index++;
            }
        }
    }
};
int main(){
    Solution sol;
    vector<int> nums = {0,1,0,5,3,0};
    sol.moveZeroes(nums);
    printf("end\n");
}
/**********************
 * n == nums.length
 * 1 <= n <= 10^4
 * 0 <= nums[i] <= n
 * All the numbers of nums are unique.
 

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?*/
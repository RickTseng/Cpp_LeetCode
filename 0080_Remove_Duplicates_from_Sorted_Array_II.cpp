#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
class Solution{
    public:
    int removeDuplicates(vector<int>& nums) {
        //vector<int> line;
        int index = 0;
        int count = 0;
        int step = 0;
        int val = nums[index];
        while (index<nums.size())
        {
            if(val==nums[index]){
                //line.push_back(val);
                nums[count] = val;
                count++;
                step++;
            }
            else if (val < nums[index]){
                step = 2;
                index--;
            }
            if(step==2){
                val++;
                step=0;
            }
            index++;
        }
        return count;
    }
};
int main(){
    //vector<int> nums = {1,1,1,2,2,3};
    //vector<int> nums1 = {0,0,1,1,1,1,2,3,3};
    vector<int> nums;
    for(int i =0;i<10;i++){
        nums.push_back(i/3);
    }
    Solution sol;
    int ans = sol.removeDuplicates(nums);
    printf("End\n");
}
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Duplicates from Sorted Array II.
//Memory Usage: 10.9 MB, less than 74.08% of C++ online submissions for Remove Duplicates from Sorted Array II.
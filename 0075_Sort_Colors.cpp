#include<vector>
#include<stdio.h>
using namespace std;
class Solution
{
    public:
        void sortColors_org(vector<int>& nums) {
            int count0 = 0;
            int count1 = 0;
            int count2 = 0;
            while (nums.size()>0)
            {
                if(nums[nums.size()-1]==0){
                    count0++;
                }
                if(nums[nums.size()-1]==1){
                    count1++;
                }
                if(nums[nums.size()-1]==2){
                    count2++;
                }
                nums.pop_back();
            }
            for(int i = 0;i<count0;i++){
                nums.push_back(0);
            }
            for(int i = 0;i<count1;i++){
                nums.push_back(1);
            }
            for(int i = 0;i<count2;i++){
                nums.push_back(2);
            }
        }

};
int main(){
    Solution sol;
    vector<int> nums = {};
    sol.sortColors(nums);
}
//Runtime: 7 ms, faster than 5.01% of C++ online submissions for Sort Colors.
//Memory Usage: 8.3 MB, less than 22.96% of C++ online submissions for Sort Colors.
/*int l = 0, m = 0, r = n-1;
        
        while(l<r && m <= r)
        {
            if(a[m] == 0)
            {
                swap(a[l], a[m]);
                l++,m++;
            }
            else if(a[m] == 1)
            {
                m++;
            }
            else if(a[m] == 2)
            {
                swap(a[r], a[m]);
                r--;
            }
        }*/
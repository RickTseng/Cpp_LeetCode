#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int,int> tmp;
        for(int i =0;i<nums2.size();i++){
            tmp[nums2[i]] = i;
        }
        for(auto n1:nums1){
            bool get = false;
            for(int s = tmp[n1];s<nums2.size();s++){
                if(nums2[s]>n1){
                    res.push_back(nums2[s]);
                    get = true;
                    break;
                }
            }
            if(!get){
                res.push_back(-1);
            }
        }
        return res;
    }
};
int main(){
    vector<int> nums1 = {1,3,5,2,4};
    vector<int> nums2 = {6,5,4,3,2,1,7};
    Solution sol;
    vector<int> ans = sol.nextGreaterElement(nums1,nums2);

}

/*
    Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
    Output: [-1,3,-1]

    [1,3,5,2,4]
    [6,5,4,3,2,1,7]

    ans:77777

    1 <= nums1.length <= nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 10^4
    All integers in nums1 and nums2 are unique.
    All the integers of nums1 also appear in nums2.

*/